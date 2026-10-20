#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


// Ayný deðer tekrar verilirse yeni düðüm oluþturmaz, mevcut düðümü döndürür.
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Soru 1: Aðacý küçükten büyüðe sýralý yazdýran inorder dolaþma (inorder)
// Sýralama: Sol -> Kök -> Sað
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Soru 2: Aðaçta deðer arama fonksiyonu (search)
// Bulunursa 1, bulunamazsa 0 döndürür.
int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Soru 2: Aðaçtaki en küçük deðeri bulan fonksiyon (findMin)
// BST kuralý gereði en küçük deðer en soldaki düðümdür.
int findMin(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int main() {
    Node* root = NULL;

    int values[] = {40, 20, 60, 10, 30, 50, 70};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    // Soru 2: 30 ve 90 deðerlerini arama
    printf("Arama 30: %s\n", search(root, 30) ? "Bulundu (1)" : "Bulunamadi (0)");
    printf("Arama 90: %s\n", search(root, 90) ? "Bulundu (1)" : "Bulunamadi (0)");

    // Soru 2: En küçük elemaný bulma ve yazdýrma
    printf("En kucuk eleman: %d\n", findMin(root));

    return 0;
}
