#include <stdio.h>
#include <stdbool.h>

#define N 6 // Düðüm sayýsý (1'den 6'ya kadar)

// Kenar ekleme fonksiyonu (Yönsüz graf olduðu için simetrik eklenir)
void kenarEkle(int adj[N][N], int u, int v) {
    adj[u - 1][v - 1] = 1;
    adj[v - 1][u - 1] = 1;
}
int i;
int j;
// 1. Komþuluk Matrisini Yazdýrma
void matrisYazdir(int adj[N][N]) {
    printf("--- Komsuluk Matrisi ---\n   ");
    for ( i = 0; i < N; i++) printf("%d ", i + 1);
    printf("\n");

    for ( i = 0; i < N; i++) {
        printf("%d: ", i + 1);
        for ( j = 0; j < N; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 2. Düðüm Dereceleri ve Grafýn Genel Derecesini Hesaplama
void dereceHesapla(int adj[N][N]) {
    int toplamDerece = 0;
    printf("--- Derece Hesaplamasi ---\n");
    for (i = 0; i < N; i++) {
        int derece = 0;
        for ( j = 0; j < N; j++) {
            derece += adj[i][j];
        }
        toplamDerece += derece;
        printf("Dugum %d derecesi: %d\n", i + 1, derece);
    }
    printf("Grafin Genel (Toplam) Derecesi: %d\n\n", toplamDerece);
}

// 3. Bipartite (Ýki Parçalý) Kontrolü - BFS ve Renklendirme (0: Mavi, 1: Kýrmýzý, -1: Boyanmamýþ)
void bipartiteKontrol(int adj[N][N], int baslangic) {
    int renk[N];
    int uzaklik[N];
    for (i = 0; i < N; i++) {
        renk[i] = -1;
        uzaklik[i] = -1;
    }

    int kuyruk[N];
    int front = 0, rear = 0;

    int startIdx = baslangic - 1;
    renk[startIdx] = 0; // Baþlangýç düðümü 0 (Mavi)
    uzaklik[startIdx] = 0;
    kuyruk[rear++] = startIdx;

    bool isBipartite = true;
    int v;
    while (front < rear) {
        int u = kuyruk[front++];

        for (v = 0; v < N; v++) {
            if (adj[u][v] == 1) {
                // Komþu henüz ziyaret edilmemiþse zýt renge boya ve uzaklýðý artýr
                if (renk[v] == -1) {
                    renk[v] = 1 - renk[u];
                    uzaklik[v] = uzaklik[u] + 1;
                    kuyruk[rear++] = v;
                }
                // Komþu ziyaret edilmiþse ve ayný renkteyse (tek-tek veya çift-çift uzaklýk)
                else if (renk[v] == renk[u]) {
                    isBipartite = false;
                }
            }
        }
    }

    printf("--- Bipartite (Iki Parcali) Kontrolu ---\n");
    for ( i = 0; i < N; i++) {
        printf("Dugum %d -> Uzaklik: %d, Renk: %d (%s)\n",
               i + 1, uzaklik[i], renk[i], renk[i] == 0 ? "Mavi/Cift" : "Kirmizi/Tek");
    }

    if (isBipartite) {
        printf("\nSONUC: Graf IKI PARCALIDIR (Bipartite). Guvenlik politikasi saglandi.\n\n");
    } else {
        printf("\nSONUC: Graf IKI PARCALI DEGILDIR! Ayni kume icinde baglanti tespit edildi.\n\n");
    }
}

int main() {
    int adj[N][N] = {0};

    // Verilen kenar listesi: E = {(1, 2), (1, 4), (2, 3), (3, 4), (3, 6), (4, 5), (5, 6)}
    kenarEkle(adj, 1, 2);
    kenarEkle(adj, 1, 4);
    kenarEkle(adj, 2, 3);
    kenarEkle(adj, 3, 4);
    kenarEkle(adj, 3, 6);
    kenarEkle(adj, 4, 5);
    kenarEkle(adj, 5, 6);

    printf("================ ILK DURUM ================\n");
    matrisYazdir(adj);
    dereceHesapla(adj);
    bipartiteKontrol(adj, 1);

    // 4. Dinamik Test: (2, 4) kenarýný ekleme
    printf("========= DINAMIK TEST: (2, 4) EKLENDI =========\n");
    kenarEkle(adj, 2, 4);
    dereceHesapla(adj);
    bipartiteKontrol(adj, 1);

    return 0;
}


























































































