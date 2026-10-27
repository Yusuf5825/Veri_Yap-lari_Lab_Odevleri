#include <stdio.h>
#include <stdlib.h>

// Düðüm (Node) yapýsý
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Yeni düðüm oluþturma (Bellekten yer ayýrma)
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ýkili Arama Aðacýna (BST) eleman ekleme (Rekürsif)
TreeNode* insert(TreeNode* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    
    return node;
}

// Hazine Arama Fonksiyonu (Rekürsif)
int searchTreasure(TreeNode* node, int target) {
    // Aðacýn sonuna gelindi ve bulunamadý
    if (node == NULL) {
        return 0; // C'de 0 false kabul edilir
    }

    // Bonus 1: Her adýmda ziyaret edilen düðümü ekrana yaz
    printf("Ziyaret edilen dugum: %d\n", node->value);

    // Hazine bulundu
    if (node->value == target) {
        return 1; // C'de 1 true kabul edilir
    }

    // Aranan deðer düðümden küçükse sola, büyükse saða dallan
    if (target < node->value) {
        return searchTreasure(node->left, target);
    } else {
        return searchTreasure(node->right, target);
    }
}

// Bonus 2: Hazineyi bulmak için en kötü durumda kaç adým gerekir? (Aðaç yüksekliði)
int calculateHeight(TreeNode* node) {
    if (node == NULL) {
        return 0; 
    }
    
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    // Daha derin olan alt aðacýn yüksekliðine +1 ekle
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Kullanýlan belleði iþletim sistemine iade etme (Temizlik)
void freeTree(TreeNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    TreeNode* root = NULL;

    // Aðacý örnek hazine deðerleriyle doldurma
    int hazineler[] = {50, 30, 70, 20, 40, 60, 80, 10, 25};
    int n = sizeof(hazineler) / sizeof(hazineler[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert(root, hazineler[i]);
    }

    printf("--- Hazine Agaci Oyununa
