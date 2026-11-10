#include <stdio.h>
#include <stdlib.h>

// AVL aðacý düðüm yapýsý
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Düðümün yüksekliðini döndüren fonksiyon
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Ýki tam sayýdan büyük olaný bulan yardýmcý fonksiyon
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Yeni düðüm oluþturan fonksiyon
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Yeni yaprak düðümün yüksekliði 1 kabul edilir
    return node;
}

// Denge faktörünü hesaplayan fonksiyon
int balanceFactor(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Sola rotasyon (Left Rotation) uygulayan fonksiyon
struct Node* rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Rotasyon iþlemi
    y->left = x;
    x->right = T2;

    // Yükseklikleri güncelle
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Yeni kökü döndür
    return y;
}

// Standart Ýkili Arama Aðacý (BST) ekleme fonksiyonu
struct Node* insertBST(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertBST(node->left, data);
    else if (data > node->data)
        node->right = insertBST(node->right, data);
    else 
        return node; // Eþit deðerlere izin verilmez

    // Yüksekliði güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    return node;
}

// Inorder dolaþým (Sol - Kök - Sað)
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder dolaþým (Kök - Sol - Sað)
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // 10 Ekle ve denge faktörünü yazdýr
    root = insertBST(root, 10);
    printf("10 eklendi. BF(kok) = %d\n", balanceFactor(root));

    // 20 Ekle ve denge faktörünü yazdýr
    root = insertBST(root, 20);
    printf("20 eklendi. BF(kok) = %d\n", balanceFactor(root));

    // 30 Ekle ve denge faktörünü yazdýr
    root = insertBST(root, 30);
    printf("30 eklendi. BF(kok) = %d\n", balanceFactor(root));

    // Dengesizlik kontrolü ve rotasyon (Soruya özel sadece RR kontrol ediliyor)
    int bf = balanceFactor(root);
    if (bf < -1 && balanceFactor(root->right) <= 0) {
        printf("RR dengesizliði: Sol rotasyon!\n\n");
        root = rotateLeft(root); // Kök güncellenir
    }

    // Sonuçlarýn ekrana yazdýrýlmasý
    printf("Kok: %d\n", root->data);
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    return 0;
}
