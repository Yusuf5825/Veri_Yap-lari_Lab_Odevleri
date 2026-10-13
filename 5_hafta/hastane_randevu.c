#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hasta dugumu 
typedef struct Patient {
    int id;
    char name[50];
    char status[20]; // bekliyor, muayenede, tamamlandi
    struct Patient* next;
} Patient;

// Bekleyen hastalar icin (FIFO)
typedef struct {
    Patient* front;
    Patient* rear;
} Queue;

// Muayenedeki hastalar icin (LIFO)
typedef struct {
    Patient* top;
} Stack;

//Gecmis kayitlar icin
typedef struct {
    Patient* head;
} LinkedList;

// Yeni bir hasta dugumu olusumu
Patient* createPatient(int id, const char* name, const char* status) {
    Patient* p = (Patient*)malloc(sizeof(Patient));
    if (!p) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    p->id = id;
    strcpy(p->name, name);
    strcpy(p->status, status);
    p->next = NULL;
    return p;
}

// Yapi ilklendirmeleri
void initQueue(Queue* q) { q->front = q->rear = NULL; }
void initStack(Stack* s) { s->top = NULL; }
void initLinkedList(LinkedList* ll) { ll->head = NULL; }

/* ---------------- KUYRUK  FONKSIYONLARI ---------------- */
void enqueue(Queue* q, int id, const char* name) {
    Patient* p = createPatient(id, name, "bekliyor");
    
    // Kuyruk bossa
    if (q->rear == NULL) {
        q->front = q->rear = p;
        return;
    }
    // Kuyrugun sonuna ekle
    q->rear->next = p;
    q->rear = p;
}

Patient* dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("\n[Uyari] Kuyruk bos! Bekleyen hasta bulunmamaktadir.\n");
        return NULL;
    }
    
    Patient* p = q->front;
    q->front = q->front->next;
    
    // Eger son eleman cikarildiysa reari da NULL yap
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    p->next = NULL; // Dugumu kuyruktan tamamen kopar
    return p;
}

/* ---------------- YIGIN  FONKSIYONLARI ---------------- */
void push(Stack* s, Patient* p) {
    strcpy(p->status, "muayenede");
    p->next = s->top;
    s->top = p;
}

Patient* pop(Stack* s) {
    if (s->top == NULL) {
        printf("\n[Uyari] Yigin bos! Muayene odasinda hasta bulunmamaktadir.\n");
        return NULL;
    }
    
    Patient* p = s->top;
    s->top = s->top->next;
    
    p->next = NULL; 
    return p;
}

/* ---------------- BAGLI LISTE  FONKSIYONLARI ---------------- */
void appendToHistory(LinkedList* ll, Patient* p) {
    strcpy(p->status, "tamamlandi");
    
    if (ll->head == NULL) {
        ll->head = p;
        return;
    }

    Patient* temp = ll->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

/* ---------------- LISTELEME FONKSIYONLARI ---------------- */
void printPatient(Patient* p) {
    printf("ID: %-5d | Ad: %-20s | Durum: %s\n", p->id, p->name, p->status);
}

void listQueue(Queue* q) {
    printf("\n--- BEKLEYEN HASTALAR ---\n");
    Patient* temp = q->front;
    if (!temp) {
        printf("Sirada bekleyen hasta yok.\n");
        return;
    }
    while (temp) {
        printPatient(temp);
        temp = temp->next;
    }
}

void listStack(Stack* s) {
    printf("\n--- MUAYENE ODASINDAKI HASTALAR  ---\n");
    Patient* temp = s->top;
    if (!temp) {
        printf("Muayene odasi bos.\n");
        return;
    }
    while (temp) {
        printPatient(temp);
        temp = temp->next;
    }
}

void listHistory(LinkedList* ll) {
    printf("\n--- GECMIS HASTA KAYITLARI---\n");
    Patient* temp = ll->head;
    if (!temp) {
        printf("Gecmis hasta kaydi bulunmamaktadir.\n");
        return;
    }
    while (temp) {
        printPatient(temp);
        temp = temp->next;
    }
}

/* ---------------- ANA PROGRAM (MENU) ---------------- */
int main() {
    Queue waitingQueue;
    Stack examStack;
    LinkedList historyList;
    
    initQueue(&waitingQueue);
    initStack(&examStack);
    initLinkedList(&historyList);
    
    int choice, id;
    char name[50];
    Patient* currentPatient;
    
    while (1) {
        printf("\n==========================================\n");
        printf("      HASTANE HASTA TAKIP SISTEMI\n");
        printf("==========================================\n");
        printf("1. Yeni Hasta Kaydi (Kuyruga Ekle)\n");
        printf("2. Hastayi Muayeneye Al (Kuyruktan -> Yigina)\n");
        printf("3. Muayeneyi Tamamla (Yigindan -> Gecmise)\n");
        printf("4. Bekleyen Hastalari Listele\n");
        printf("5. Muayene Odasindaki Hastalari Listele\n");
        printf("6. Gecmis Kayitlari Listele\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Gecersiz giris. Lutfen bir sayi giriniz.\n");
            while(getchar() != '\n'); // Bufferi temizle
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Hasta ID: ");
                scanf("%d", &id);
                printf("Hasta Adi Soyadi: ");
                scanf(" %[^\n]", name); // Bosluk iceren isimleri okumak icin
                enqueue(&waitingQueue, id, name);
                printf("\n[Basarili] %s kuyruga 'bekliyor' olarak eklendi.\n", name);
                break;
                
            case 2:
                currentPatient = dequeue(&waitingQueue);
                if (currentPatient != NULL) {
                    push(&examStack, currentPatient);
                    printf("\n[Basarili] %s muayeneye alindi.\n", currentPatient->name);
                }
                break;
                
            case 3:
                currentPatient = pop(&examStack);
                if (currentPatient != NULL) {
                    appendToHistory(&historyList, currentPatient);
                    printf("\n[Basarili] %s adli hastanin muayenesi tamamlandi ve gecmise eklendi.\n", currentPatient->name);
                }
                break;
                
            case 4:
                listQueue(&waitingQueue);
                break;
                
            case 5:
                listStack(&examStack);
                break;
                
            case 6:
                listHistory(&historyList);
                break;
                
            case 0:
                printf("\nSistemden cikiliyor...\n");
                return 0;
                
            default:
                printf("\nGecersiz secim! Lutfen 0-6 arasinda bir islem seciniz.\n");
        }
    }
    
    return 0;
}
