#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char dosyaAdi[100];
    struct Node* next;
} Node;

// Baþ ve Son iþaretçilerini tutar
typedef struct Queue {
    Node* front; 
    Node* rear;  
} Queue;

// Kuyruðu ilklendiren yardýmcý fonksiyon
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Kuyruða yeni yazdýrma iþi ekler (FIFO kuralýna göre sona eklenir)
void enqueuePrintJob(Queue* q, char* dosyaAdi) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsis hatasi!\n");
        return;
    }
    
    strcpy(newNode->dosyaAdi, dosyaAdi);
    newNode->next = NULL;

    // Kuyruk tamamen boþsa yeni düðüm hem baþ hem son olur
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Kuyruðun sonuna ekle ve arka iþaretçiyi (rear) güncelle
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("-> '%s' kuyruga eklendi.\n", dosyaAdi);
}

// Kuyruktan sýradaki iþi çýkarýr ve iþler (Baþtan silme)
void processNextJob(Queue* q) {
    
    if (q->front == NULL) {
        printf("-> Kuyruk bos! Yazdirilacak dosya bulunamadi.\n");
        return;
    }

    
    Node* temp = q->front;
    printf("-> YAZDIRILIYOR: %s\n", temp->dosyaAdi);

    q->front = q->front->next;

    // Eðer kuyruktan çýkarýlan eleman son elemansa, rear'ý da NULL yap
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); 
}

// Kuyruðun mevcut durumunu gösterir
void showQueue(Queue q) {
    if (q.front == NULL) {
        printf("-> Kuyruk su an bos.\n");
        return;
    }

    Node* current = q.front;
    int sira = 1;
    
    printf("\n--- Yazdirma Kuyrugu ---\n");
    while (current != NULL) {
        printf("%d. %s\n", sira, current->dosyaAdi);
        current = current->next;
        sira++;
    }
    printf("------------------------\n");
}

int main() {
    Queue q;
    initQueue(&q); // Kuyruðu baþlat
    
    int secim;
    char dosyaAdi[100];

    while (1) {
        printf("\n1) Yeni dosya ekle\n");
        printf("2) Yazdir\n");
        printf("3) Kuyrugu goster\n");
        printf("4) Cikis\n");
        printf("Seciminiz: ");
        
        // Hatalý karakter giriþlerini engellemek için
        if (scanf("%d", &secim) != 1) {
            while(getchar() != '\n'); 
            printf("Lutfen gecerli bir sayi girin!\n");
            continue;
        }
        getchar(); // 'Enter' karakterini temizler

        switch (secim) {
            case 1:
                printf("Eklenecek dosya adini girin: ");
                fgets(dosyaAdi, sizeof(dosyaAdi), stdin);
                dosyaAdi[strcspn(dosyaAdi, "\n")] = 0; 
                
                if (strlen(dosyaAdi) > 0) {
                    enqueuePrintJob(&q, dosyaAdi);
                } else {
                    printf("Dosya adi bos olamaz.\n");
                }
                break;
            case 2:
                processNextJob(&q);
                break;
            case 3:
                showQueue(q);
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                
                while (q.front != NULL) {
                    Node* temp = q.front;
                    q.front = q.front->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Gecersiz secim! Lutfen 1 ile 4 arasinda bir secim yapin.\n");
        }
    }

    return 0;
}
