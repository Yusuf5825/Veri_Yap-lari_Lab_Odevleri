
#include <stdio.h>

#define N 6
#define INF 99999

char dugumler[N] = {'A', 'B', 'C', 'D', 'E', 'F'};
int i;
int graf[N][N] = {
    {0,   7,   5,   INF, INF, 1},
    {7,   0,   1,   1,   3,   INF},
    {5,   1,   0,   2,   1,   INF},
    {INF, 1,   2,   0,   INF, 7},
    {INF, 3,   1,   INF, 0,   2},
    {1,   INF, INF, 7,   2,   0}
};

// Dijkstra tablosunu yazdiran fonksiyon
void tabloYazdir(int known[], int distance[],
                 int path[], int adim)
{
    printf("\nAdim %d\n", adim);
    printf("Dugum\tKnown\tDistance\tPath\n");
    printf("-------------------------------------\n");

    for ( i = 0; i < N; i++)
    {
        printf("%c\t%d\t", dugumler[i], known[i]);

        if (distance[i] == INF)
            printf("INF\t\t");
        else
            printf("%d\t\t", distance[i]);

        if (path[i] == -1)
            printf("-\n");
        else
            printf("%c\n", dugumler[path[i]]);
    }
}

// Dijkstra algoritmasi
void dijkstra(int kok, int distance[],
              int path[], int tabloGoster)
{
    int known[N];

    // Baslangic degerleri
    for ( i = 0; i < N; i++)
    {
        known[i] = 0;
        distance[i] = INF;
        path[i] = -1;
    }

    distance[kok] = 0;

    if (tabloGoster)
        tabloYazdir(known, distance, path, 0);
    int adim;
    for (adim = 1; adim <= N; adim++)
    {
        int min = INF;
        int u = -1;

        // Isaretlenmemis en dusuk maliyetli dugumu bul
        for ( i = 0; i < N; i++)
        {
            if (known[i] == 0 && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        known[u] = 1;
        int v;
        // Komsu dugumlerin maliyetlerini guncelle
        for (v = 0; v < N; v++)
        {
            if (known[v] == 0 &&
                graf[u][v] != INF &&
                graf[u][v] != 0)
            {
                int yeniMaliyet =
                    distance[u] + graf[u][v];

                if (yeniMaliyet < distance[v])
                {
                    distance[v] = yeniMaliyet;
                    path[v] = u;
                }
            }
        }

        if (tabloGoster)
            tabloYazdir(known, distance, path, adim);
    }
}

// Tersten okuma yontemi ile rota yazdirma
void rotaYazdir(int kok, int hedef,
                int distance[], int path[])
{
    int rota[N];
    int sayac = 0;
    int mevcut = hedef;

    if (distance[hedef] == INF)
    {
        printf("Hedefe ulasilamiyor.\n");
        return;
    }

    // Hedeften kok dugume dogru ilerle
    while (mevcut != -1)
    {
        rota[sayac] = mevcut;
        sayac++;

        mevcut = path[mevcut];
    }

    printf("\n%c -> %c rotasi: ",
           dugumler[kok], dugumler[hedef]);

    // Diziyi tersten yazdir
    for (i = sayac - 1; i >= 0; i--)
    {
        printf("%c", dugumler[rota[i]]);

        if (i != 0)
            printf(" -> ");
    }

    printf("\nToplam maliyet: %d\n", distance[hedef]);
}

// Merkezi dugumu bulma
void merkeziDugumBul()
{
    int distance[N];
    int path[N];
    int toplamlar[N];
    int minToplam = INF;

    printf("\n===== GOREV 3 =====\n");
    printf("Merkezi Dugum Analizi\n\n");

    printf("Kok\tA\tB\tC\tD\tE\tF\tToplam\n");
    printf("------------------------------------------------------\n");
    int kok;
    // Butun dugumleri sirayla kok kabul et
    for (kok = 0; kok < N; kok++)
    {
        dijkstra(kok, distance, path, 0);

        int toplam = 0;

        printf("%c\t", dugumler[kok]);

        for (i = 0; i < N; i++)
        {
            toplam += distance[i];
            printf("%d\t", distance[i]);
        }

        toplamlar[kok] = toplam;

        printf("%d\n", toplam);

        if (toplam < minToplam)
        {
            minToplam = toplam;
        }
    }

    // Ayni minimum maliyete sahip tum dugumleri bul
    printf("\nEn merkezi dugumler: ");

    for ( i = 0; i < N; i++)
    {
        if (toplamlar[i] == minToplam)
            printf("%c ", dugumler[i]);
    }

    printf("\nEn dusuk toplam maliyet: %d\n",
           minToplam);
}

int main()
{
    char secim;
    int kok;
    int distance[N];
    int path[N];

    // GOREV 1
    printf("===== GOREV 1 =====\n");

    printf("Kok dugumu giriniz (A-F): ");
    scanf(" %c", &secim);

    // Kucuk harf girilirse buyuk harfe cevir
    if (secim >= 'a' && secim <= 'f')
        secim = secim - 'a' + 'A';

    if (secim < 'A' || secim > 'F')
    {
        printf("Gecersiz dugum!\n");
        return 1;
    }

    kok = secim - 'A';

    dijkstra(kok, distance, path, 1);

    // GOREV 2
    printf("\n===== GOREV 2 =====\n");

    // A dugumunu kok kabul et
    dijkstra(0, distance, path, 0);

    rotaYazdir(0, 1, distance, path);
    rotaYazdir(0, 3, distance, path);

    // GOREV 3
    merkeziDugumBul();

    return 0;
}

