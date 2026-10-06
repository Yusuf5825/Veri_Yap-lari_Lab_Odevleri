#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char isim[100];
    struct Node* prev;
    struct Node* next;
} Node;

Node* currentSong = NULL; 

// Listeye (sona) yeni þarký ekler
void addSongToEnd(Node** head, char* isim) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek hatasi!\n");
        return;
    }
    strcpy(newNode->isim, isim);
    newNode->next = NULL;
    newNode->prev = NULL;

    // Liste boþsa yeni düðüm baþ olur
    if (*head == NULL) {
        *head = newNode;
        currentSong = newNode; // Ýlk eklenen þarký otomatik olarak seçilir
        printf("'%s' listeye eklendi ve su an secili.\n", isim);
        return;
    }

    // Sona git ve ekle
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; // Çift yönlü baðlantý kuruldu
    printf("'%s' listeye eklendi.\n", isim);
}

// þarkýyý listeden siler
void removeSong(Node** head, char* isim) {
    if (*head == NULL) {
        printf("Liste bos.\n"); // Ýpucu gereksinimi: Liste boþken uyarý
        return;
    }

    Node* temp = *head;
    
    // Silinecek þarkýyý bul
    while (temp != NULL && strcmp(temp->isim, isim) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Sarki bulunamadi: %s\n", isim);
        return;
    }

    // Silinecek þarký o an çalan þarkýysa, currentSong iþaretçisini kaydýr
    if (currentSong == temp) {
        if (temp->next != NULL) {
            currentSong = temp->next; /
        } else {
            currentSong = temp->prev; 
        }
    }

    // prev ve next baðlantýlarýný güncelle
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Baþtaki düðüm siliniyorsa head güncellenir
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("'%s' listeden silindi.\n", isim);
}

// Bir sonraki þarký
void playNext() {
    if (currentSong == NULL) {
        printf("Liste bos veya sarki secili degil.\n");
        return;
    }
    
    if (currentSong->next != NULL) {
        currentSong = currentSong->next;
        printf("Siradaki sarki caliyor: %s\n", currentSong->isim);
    } else {
        printf("Listenin sonundasiniz, siradaki sarki yok.\n");
    }
}

// Bir önceki þarký
void playPrevious() {
    if (currentSong == NULL) {
        printf("Liste bos veya sarki secili degil.\n");
        return;
    }
    
    if (currentSong->prev != NULL) {
        currentSong = currentSong->prev;
        printf("Onceki sarki caliyor: %s\n", currentSong->isim);
    } else {
        printf("Listenin basindasiniz, onceki sarki yok.\n");
    }
}

// ana menü
int main() {
    Node* head = NULL;
    int secim;
    char sarkiIsmi[100];

    while (1) {
        printf("\n--- MUZIK CALAR MENUSU ---\n");
        printf("1. Sarki Ekle\n");
        printf("2. Sarki Sil\n");
        printf("3. Sonraki Sarkiyi Cal (playNext)\n");
        printf("4. Onceki Sarkiyi Cal (playPrevious)\n");
        printf("5. Su An Calani Goster\n");
        printf("6. Cikis\n");
        printf("Seciminiz: ");
        
        if (scanf("%d", &secim) != 1) {
            while(getchar() != '\n'); 
            printf("Gecersiz giris!\n");
            continue;
        }
        getchar(); // Enter karakterini tampondan temizle

        switch (secim) {
            case 1:
                printf("Eklenecek sarki ismini girin: ");
                fgets(sarkiIsmi, sizeof(sarkiIsmi), stdin);
                sarkiIsmi[strcspn(sarkiIsmi, "\n")] = 0; // Sondaki \n karakterini siler
                addSongToEnd(&head, sarkiIsmi);
                break;
            case 2:
                printf("Silinecek sarki ismini girin: ");
                fgets(sarkiIsmi, sizeof(sarkiIsmi), stdin);
                sarkiIsmi[strcspn(sarkiIsmi, "\n")] = 0;
                removeSong(&head, sarkiIsmi);
                break;
            case 3:
                playNext();
                break;
            case 4:
                playPrevious();
                break;
            case 5:
                if (currentSong != NULL) {
                    printf(">>> Su an caliyor: %s <<<\n", currentSong->isim);
                } else {
                    printf("Liste bos.\n"); // Ýpucu gereksinimi
                }
                break;
            case 6:
                printf("Uygulamadan cikiliyor...\n");
                
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Gecersiz secim. Lutfen 1-6 arasinda bir deger girin.\n");
        }
    }
    return 0;
}
