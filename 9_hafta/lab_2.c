#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int i;
// Düðüm yüksekliði
int height(struct Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Yeni düðüm oluþturma
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Sað rotasyon (LL durumu için)
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // Yeni kök
}

// Sol rotasyon (RR durumu için)
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // Yeni kök
}

// Denge faktörünü hesaplama
int getBalance(struct Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

// AVL Ekleme ve Dengeleme Fonksiyonu
struct Node* insertAVL(struct Node* node, int data) {
    // 1. Normal BST ekleme adýmý
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
    else // Eþit düðümler AVL'ye eklenmez
        return node;

    // 2. Yüksekliði güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Denge faktörünü al
    int balance = getBalance(node);

    // 4. Dört Dengesizlik Durumunu Kontrol Et
    // LL (Sol Sol) Durumu
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR (Sað Sað) Durumu
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // LR (Sol Sað) Durumu
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL (Sað Sol) Durumu
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Düðüm dengeliyse doðrudan döndür
    return node;
}

// Preorder Dolaþým
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Testleri çalýþtýran yardýmcý fonksiyon
void runTest(char* testName, int arr[], int size) {
    struct Node *root = NULL;
    printf("Test %s Eklendi: ", testName);
    for(i = 0; i < size; i++) {
        root = insertAVL(root, arr[i]);
    }
    
    printf("\nKok degeri: %d", root->data);
    printf("\nPreorder: ");
    preorder(root);
    printf("\n-------------------------\n");
}

int main() {
    int testA[] = {30, 20, 10};
    int testB[] = {10, 20, 30};
    int testC[] = {30, 10, 20};
    int testD[] = {10, 30, 20};
    
    runTest("A (LL)", testA, 3);
    runTest("B (RR)", testB, 3);
    runTest("C (LR)", testC, 3);
    runTest("D (RL)", testD, 3);
    
    return 0;
}
