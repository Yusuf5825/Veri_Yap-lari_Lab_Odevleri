// 1. soru tek Node Oluþturma
#include <stdio.h>
#include <stdlib.h>
/*
struct Node {
    int data;           //
    struct Node* next;  
};

int main() {
    // 2. Node için bellekte dinamik olarak yer ayýrma
    struct Node* dugum = (struct Node*)malloc(sizeof(struct Node));
    
    // 3. Ýstenen 10 deðerini atama ve next iþaretçisini NULL yapma
    dugum->data = 10;
    dugum->next = NULL;
    
    // 4. Node içindeki deðeri ekrana yazdýrma
    printf("Node icerisindeki deger: %d\n", dugum->data);
    
    // Ýþlem bittikten sonra ayrýlan belleði serbest býrakma
    free(dugum);
    
    return 0;
}*/

//2. soru: Ýki node'u birbirine baðlama
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // 1. Ýki farklý Node için bellekte yer ayýrma
    struct Node* dugum1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* dugum2 = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Ýlgili deðerleri düðümlere atama
    dugum1->data = 10;
    dugum2->data = 20;
    
    // 3. Düðümleri birbirine baðlama süreci (10 -> 20 -> NULL)
    dugum1->next = dugum2; // 1. düðümün next iþaretçisi, 2. düðümü gösterir
    dugum2->next = NULL;   // 2. düðüm listenin sonu olduðu için NULL deðerini alýr
    
    
    printf("Bagli Liste: %d -> %d -> NULL\n", dugum1->data, dugum1->next->data);
    
    
    free(dugum1);
    free(dugum2);
    
    return 0;
}
*/
//3. Soru: Üç Node'u Listeyi yazdýrma
/*

struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* dugum2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* dugum3 = (struct Node*)malloc(sizeof(struct Node));
    
    
    head->data = 10;
    head->next = dugum2;
    
    dugum2->data = 20;
    dugum2->next = dugum3;
    
    dugum3->data = 30;
    dugum3->next = NULL;
    
    
    struct Node* gecici = head; // Baþlangýç noktasýný kaybetmemek için geçici bir pointer kullanýlýr
    
    printf("Bagli Liste: ");
    while (gecici != NULL) {
        printf("[%d] -> ", gecici->data);
        gecici = gecici->next; // Bir sonraki düðüme geç
    }
    printf("NULL\n");
    
    
    free(head);
    free(dugum2);
    free(dugum3);
    
    return 0;
}
*/
// 4. Soru: malloc Kullanarak Linked List Oluþturma
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* dugum2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* dugum3 = (struct Node*)malloc(sizeof(struct Node));
    
    // Bellek tahsisinin baþarýsýz olma ihtimaline karþý kontrol
    if (head == NULL || dugum2 == NULL || dugum3 == NULL) {
        printf("Bellek tahsisi basarisiz oldu.\n");
        return 1;
    }

    
    
    // Ýlk düðüm (head)
    head->data = 10;
    head->next = dugum2; // head'in next'i 2. düðümü gösterir
    
    // Ýkinci düðüm
    dugum2->data = 20;
    dugum2->next = dugum3; // 2. düðümün next'i 3. düðümü gösterir
    
    // Üçüncü (son) düðüm
    dugum3->data = 30;
    dugum3->next = NULL; // Listenin sonu olduðu için NULL atanýr
    
    
    struct Node* temp = head;
    printf("Olusturulan Liste: ");
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    
    free(head);
    free(dugum2);
    free(dugum3);
    
    return 0;
}
*/
//5. soru:Listenin Eleman Sayýsýný bulma
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    
   
    head->data = 10;
    head->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = n4;
    
    n4->data = 40;
    n4->next = NULL;
    
    
    int sayac = 0; 
    struct Node* temp = head; // Listeyi kaybetmemek için geçici pointer kullan
    
    // temp NULL olana kadar 
    while (temp != NULL) {
        sayac++;           // Her düðümde sayacý 1 artýr[cite: 3]
        temp = temp->next; // Bir sonraki düðüme geç
    }
    
    printf("Listedeki Node sayisi: %d\n", sayac);
    
    
    free(head);
    free(n2);
    free(n3);
    free(n4);
    
    return 0;
}
*/
// 6. soru Listenin Elemanlarýný Toplama:
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    
    
    head->data = 10;
    head->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = n4;
    
    n4->data = 40;
    n4->next = NULL;
    
    
    int sum = 0;             
    struct Node* temp = head; 
    
    
    while (temp != NULL) {
        sum = sum + temp->data; 
        temp = temp->next;      
    }
    
    printf("Listenin elemanlari toplami: %d\n", sum);
    
    
    free(head);
    free(n2);
    free(n3);
    free(n4);
    
    return 0;
}*/
//7. soru Linked List Eleman Arama
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    
    
    head->data = 10;
    head->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = n4;
    
    n4->data = 40;
    n4->next = NULL;
    
    
    int aranan;
    printf("Aranacak sayiyi giriniz: ");
    scanf("%d", &aranan);
    
    
    struct Node* temp = head; 
    int bulundu = 0;          
    
    // temp NULL olana kadar döngüyü çalýþtýr
    while (temp != NULL) {
        if (temp->data == aranan) {
            bulundu = 1; // Eþleþme saðlandý
            break;       // Eleman bulunduðu için döngüyü gereksiz yere uzatmadan sonlandýr
        }
        temp = temp->next; // Bir sonraki düðüme geç
    }
    
    
    if (bulundu == 1) {
        printf("%d listende bulundu (Evet)\n", aranan);
    } else {
        printf("%d listede bulunamadi (Hayir)\n", aranan);
    }
    
    
    free(head);
    free(n2);
    free(n3);
    free(n4);
    
    return 0;
}*/
// 8. soru: Listenin Baþýna Eleman Ekleme
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    
   
    struct Node* head = n1; 
    
    n1->data = 10;
    n1->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = NULL;
    
    // Yeni eklenecek Node'u oluþturma
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 5;
    
    
    newNode->next = head; // Yeni düðümün next'i mevcut head'i (10) gösterir
    head = newNode;       // Listenin yeni baþý (head) artýk 5 deðerini tutan düðüm olur
    
    
    struct Node* temp = head;
    printf("Guncel Liste: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    
    free(newNode); // 5
    free(n1);      // 10
    free(n2);      // 20
    free(n3);      // 30
    
    return 0;
}*/

//9. soru: Listenin Sonuna Eleman Ekleme
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = NULL;
    
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 40;
    newNode->next = NULL; // Listenin en sonuna ekleneceði için next deðeri NULL olmalýdýr
    
    
    struct Node* temp = head; // Listeyi dolaþmak için geçici iþaretçi
    
    // temp->next deðeri NULL olana kadar (son düðümü bulana kadar) ilerle
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Son düðüm bulundu (n3). Bu düðümün next iþaretçisini yeni düðüme baðla.
    temp->next = newNode;
    
    
    temp = head; // Yazdýrma iþlemine baþlamak için tekrar listenin baþýna dön
    printf("Guncel Liste: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    
    free(head);
    free(n2);
    free(n3);
    free(newNode);
    
    return 0;
}*/

//10. soru: belirli bir eleman silme
/*
struct Node {
    int data;
    struct Node* next;
};

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = n2;
    
    n2->data = 20;
    n2->next = n3;
    
    n3->data = 30;
    n3->next = n4;
    
    n4->data = 40;
    n4->next = NULL;
    
    
    int silinecek;
    printf("Silinecek degeri giriniz: ");
    scanf("%d", &silinecek);
    
    
    struct Node* temp = head; // Dolaþmak için geçici iþaretçi
    struct Node* prev = NULL; // Bir önceki düðümü aklýnda tutacak iþaretçi
    
    
    if (temp != NULL && temp->data == silinecek) {
        head = temp->next; // Listenin baþýný bir sonrakine kaydýr
        free(temp);        // Eski baþ düðümü bellekten sil
    } else {
        // Durum 2: Eleman ortada veya sondayken arama yapma
        // Silinecek deðeri bulana kadar veya liste bitene kadar ilerle
        while (temp != NULL && temp->data != silinecek) {
            prev = temp;       // Þu anki düðümü 'önceki' olarak kaydet
            temp = temp->next; // Bir sonraki düðüme geç
        }
        
        // Eðer döngü bittiðinde temp NULL ise eleman listede yoktur
        if (temp == NULL) {
            printf("Girdiginiz deger listede bulunamadi.\n");
        } else {
            
            prev->next = temp->next; 
            free(temp); 
        }
    }
    
    
    temp = head; 
    printf("Guncel Liste: ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}*/


// 11.Soru: Fonksiyanlaþtýrýlmýþ Linked List

struct Node {
    int data;
    struct Node* next;
};

// insertBeginning
// Çift yýldýz (**) kullanýlmasýnýn sebebi, main içindeki head iþaretçisinin adresini doðrudan güncelleyebilmektir.
void insertBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = (*head_ref); // Yeni düðümün next'ini eski head'e baðla
    (*head_ref) = newNode;       // head iþaretçisini yeni düðümü gösterecek þekilde güncelle
    printf("%d listenin basina eklendi.\n", new_data);
}

// display
void display(struct Node* node) {
    printf("Guncel Liste: ");
    while (node != NULL) {
        printf("[%d] -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// search
void search(struct Node* head, int aranan) {
    struct Node* temp = head;
    int bulundu = 0;
    
    while (temp != NULL) {
        if (temp->data == aranan) {
            bulundu = 1;
            break; // Eleman bulunduðunda döngüyü sonlandýr
        }
        temp = temp->next;
    }
    
    if (bulundu == 1) {
        printf("Arama Sonucu: %d listede BULUNDU.\n", aranan);
    } else {
        printf("Arama Sonucu: %d listede BULUNAMADI.\n", aranan);
    }
}

int main() {
    struct Node* head = NULL; // Baþlangýçta boþ bir liste oluþturulur

    // insertBeginning() fonksiyonunu test etme
    insertBeginning(&head, 30);
    insertBeginning(&head, 20);
    insertBeginning(&head, 10);
    
    printf("\n");

    // display() fonksiyonunu test etme
    display(head);
    
    printf("\n");

    // search() fonksiyonunu test etme
    search(head, 20);
    search(head, 50);

    return 0;
}
