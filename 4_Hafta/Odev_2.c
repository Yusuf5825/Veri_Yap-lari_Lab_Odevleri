#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100


typedef struct Node {
    char word[MAX_WORD_LEN];
    struct Node* next;
} Node;

// Push - Add
void push(Node** top, char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return;
    }
    strcpy(newNode->word, word);
    newNode->next = *top; // Yeni düðüm eski top'ý gösterir
    *top = newNode;       // Yeni top artýk bu düðüm
}

// Pop - Undo
void pop(Node** top) {
    if (*top == NULL) {
        // Stack zaten boþsa iþlem yapýlmaz
        return;
    }
    Node* temp = *top;
    *top = (*top)->next; // Top bir alttaki düðüme kayar
    free(temp);          // Eski top bellekten silinir
}


void printBottomToTop(Node* top) {
    if (top == NULL) {
        return;
    }
    // Önce bir sonraki (alttaki) düðüme git, dönerken yazdýr (böylece ilk eklenen ilk yazýlýr)
    printBottomToTop(top->next);
    printf("%s ", top->word);
}

// Mevcut metni gösterme (Show)
void show(Node* top) {
    printf("-> ");
    if (top != NULL) {
        printBottomToTop(top);
    }
    printf("\n");
}

int main() {
    Node* stackTop = NULL;
    char input[150];
    char command[20];
    char word[MAX_WORD_LEN];

    printf("--- Undo (Geri Alma) Simulasyonu ---\n");
    printf("Kullanim: 'add <kelime>', 'undo', 'show', 'exit'\n\n");

    while (1) {
        printf("> ");
        
        // Tüm satýrý oku
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        int args = sscanf(input, "%s %s", command, word);

        if (args >= 1) {
            if (strcmp(command, "add") == 0 && args == 2) {
                push(&stackTop, word);
            } 
            else if (strcmp(command, "add") == 0 && args == 1) {
                printf("Lutfen eklenecek kelimeyi de girin (Ornek: add Merhaba)\n");
            }
            else if (strcmp(command, "undo") == 0) {
                pop(&stackTop);
            } 
            else if (strcmp(command, "show") == 0) {
                show(stackTop);
            } 
            else if (strcmp(command, "exit") == 0) {
                break;
            } 
            else {
                printf("Gecersiz komut!\n");
            }
        }
    }

    
    while (stackTop != NULL) {
        pop(&stackTop);
    }

    return 0;
}

