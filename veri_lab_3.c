#include <stdio.h>
#include <stdlib.h>

/*
// Baðlý liste düðüm yapýsý
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Baðlý listeye sýralý þekilde yeni bir düðüm ekler
void addOrdered(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Araya veya sona ekleme için uygun konumu bulma
    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    // Yeni düðümü listeye baðlama
    newNode->next = current->next;
    current->next = newNode;
}

// Baðlý listede verilen deðere sahip ilk düðümü siler
void removeNode(Node** head, int value) {
    if (*head == NULL) return; // Liste boþsa iþlem yapma

    // Silinecek düðüm ilk düðümse
    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Silinecek deðeri arama
    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // Deðer bulunduysa sil ve belleði serbest býrak
    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Listedeki düðüm sayýsýný döndürür
int count(Node* head) {
    int nodeCount = 0;
    Node* current = head;
    while (current != NULL) {
        nodeCount++;
        current = current->next;
    }
    return nodeCount;
}

// Listenin elemanlarýný baþtan sona ekrana yazdýrýr
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Listedeki tüm düðümleri serbest býrakýr ve listeyi boþaltýr
void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next; // Sonraki düðümü kaydet
        free(current);            // Mevcut düðümü sil
        current = nextNode;       // Bir sonraki düðüme geç
    }
    
    *head = NULL; // Liste baþý iþaretçisini sýfýrla
}

// Fonksiyonlarý test etmek için örnek main fonksiyonu
int main() {
    Node* head = NULL;

    // Örnekteki sayýlarý sýrasýyla ekleme
    int sayilar[] = {23, 11, 5, 9, 6, 4, 12, 24};
    int boyut = sizeof(sayilar) / sizeof(sayilar[0]);
    int i;
    for (i = 0; i < boyut; i++) {
        addOrdered(&head, sayilar[i]);
    }

    printf("Liste icerigi: ");
    printList(head); // Beklenen çýktý: 4 -> 5 -> 6 -> 9 -> 11 -> 12 -> 23 -> 24

    printf("Dugum sayisi: %d\n", count(head));

    printf("11 degeri siliniyor...\n");
    removeNode(&head, 11);
    
    printf("Guncel liste: ");
    printList(head);

    printf("Liste temizleniyor...\n");
    clear(&head);
    
    printf("Temizlendikten sonra dugum sayisi: %d\n", count(head));

    return 0;
}*/
/*
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAt(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // 0 veya negatif pozisyona ekleme yapýldýðýnda baþa eklenir
    // Ya da liste tamamen boþsa ilk eleman olarak eklenir
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    int current_pos = 0;

    // Ýstenilen pozisyondan bir önceki düðüme veya listenin sonuna kadar ilerle
    while (current->next != NULL && current_pos < position - 1) {
        current = current->next;
        current_pos++;
    }

    // Pozisyon listedeki eleman sayýsýndan büyükse, döngü son elemana 
    // kadar gelir ve yeni düðüm listenin sonuna eklenmiþ olur.
    newNode->next = current->next;
    current->next = newNode;
}

// Verilen pozisyondaki düðümü siler
void deleteAt(Node** head, int position) {
    // Liste boþsa veya negatif pozisyon girildiyse iþlem yapýlmaz
    if (*head == NULL || position < 0) {
        return;
    }

    // 0. pozisyondaki düðüm silinirse, baþ düðüm güncellenir
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    int current_pos = 0;

    // Silinecek düðümden bir önceki düðüme kadar ilerle
    while (current->next != NULL && current_pos < position - 1) {
        current = current->next;
        current_pos++;
    }

    // Eðer current->next NULL ise, girilen pozisyon listedeki eleman
    // sayýsýndan daha büyüktür (geçersiz pozisyon), iþlem yapýlmaz.
    if (current->next == NULL) {
        return;
    }

    // Düðümü sil ve belleði serbest býrak
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Listenin elemanlarýný baþtan sona ekrana yazdýrýr
void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Listedeki tüm düðümleri serbest býrakýr ve listeyi boþaltýr
void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
}

// Fonksiyonlarý test etmek için main fonksiyonu
int main() {
    Node* head = NULL;
    int i; // C89/C90 uyumluluðu için döngü deðiþkeni dýþarýda tanýmlandý

    printf("Ekleme isaretleri basliyor...\n");
    // insertAt(head, deðer, pozisyon)
    insertAt(&head, 10, 0);  // 10
    insertAt(&head, 20, 1);  // 10 -> 20
    insertAt(&head, 30, 5);  // 10 -> 20 -> 30 (5 sayýsý sýnýr dýþý olduðu için sona eklenir)
    insertAt(&head, 5, -2);  // 5 -> 10 -> 20 -> 30 (Negatif pozisyon baþa ekler)
    insertAt(&head, 15, 2);  // 5 -> 10 -> 15 -> 20 -> 30 (2. indise ekler)
    
    printf("Mevcut liste: ");
    printList(head);

    printf("\nSilme islemleri basliyor...\n");
    printf("0. pozisyon siliniyor...\n");
    deleteAt(&head, 0); 
    printList(head); // 10 -> 15 -> 20 -> 30

    printf("2. pozisyon siliniyor...\n");
    deleteAt(&head, 2); 
    printList(head); // 10 -> 15 -> 30

    printf("Gecersiz pozisyon (10) silinmeye calisiliyor...\n");
    deleteAt(&head, 10); 
    printList(head); // Degismez: 10 -> 15 -> 30

    printf("\nListe temizleniyor...\n");
    clear(&head);
    printList(head);

    return 0;
}
*/

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Baðlý listedeki ortadaki düðümü döndürür (Yavaþ ve Hýzlý Ýþaretçi Yaklaþýmý)
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL; // Boþ liste durumu
    }

    Node* slow = head; // Her adýmda bir ilerler
    Node* fast = head; // Her adýmda iki ilerler

    // fast ve fast->next NULL olana kadar döngü devam eder
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // 1 adým git
        fast = fast->next->next;    // 2 adým git
    }

    // fast sona ulaþtýðýnda, slow tam ortadaki düðümü gösterir
    return slow;
}

// Listenin elemanlarýný baþtan sona ekrana yazdýrýr
void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Listedeki tüm düðümleri serbest býrakýr ve listeyi boþaltýr
void clear(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
}

// Test amaçlý: Listeye sona eleman ekler
void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Fonksiyonlarý test etmek için main fonksiyonu
int main() {
    Node* head = NULL;
    Node* middle = NULL;

    // --- Durum 1: Tek sayýda eleman ---
    printf("--- Tek Sayida Eleman (5 dugum) ---\n");
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    
    printf("Liste: ");
    printList(head); // 1 -> 2 -> 3 -> 4 -> 5

    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Ortadaki dugumun degeri: %d\n", middle->data); // Beklenen: 3
    }
    clear(&head);


    // --- Durum 2: Çift sayýda eleman ---
    printf("\n--- Cift Sayida Eleman (6 dugum) ---\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);
    append(&head, 60);

    printf("Liste: ");
    printList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> 60

    middle = findMiddle(head);
    if (middle != NULL) {
        printf("Ortadaki dugumun degeri: %d\n", middle->data); // Beklenen: 40 (Ýki ortadan ikincisi)
    }
    clear(&head);


    // --- Durum 3: Boþ liste ---
    printf("\n--- Bos Liste ---\n");
    middle = findMiddle(head);
    if (middle == NULL) {
        printf("Liste bos, ortadaki dugum yok (NULL dondu).\n");
    }

    return 0;
}































