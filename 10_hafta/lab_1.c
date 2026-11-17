#include <stdio.h>
#include <stdlib.h>


const char* sehirler[] = {"Istanbul", "Ankara", "Izmir", "Bursa", "Antalya"};


int graf[5][5] = {
    // Ist, Ank, Izm, Bur, Ant
    {0,   1,   0,   1,   0}, 
    {1,   0,   1,   0,   1}, 
    {0,   1,   0,   0,   0}, 
    {1,   0,   0,   0,   1}, 
    {0,   1,   0,   1,   0}  
};


int ziyaret_edildi_dfs[5] = {0};
int ziyaret_edildi_bfs[5] = {0};
int i;

void DFS(int dugum) {
    printf("%s ", sehirler[dugum]);
    ziyaret_edildi_dfs[dugum] = 1; 

    for ( i = 0; i < 5; i++) {
        
        if (graf[dugum][i] == 1 && !ziyaret_edildi_dfs[i]) {
            DFS(i);
        }
    }
}


void BFS(int baslangic) {
    int kuyruk[5];
    int bas = 0, son = 0;

    
    kuyruk[son++] = baslangic;
    ziyaret_edildi_bfs[baslangic] = 1;

    while (bas < son) {
        
        int mevcut_dugum = kuyruk[bas++];
        printf("%s ", sehirler[mevcut_dugum]);

        
        for ( i = 0; i < 5; i++) {
            if (graf[mevcut_dugum][i] == 1 && !ziyaret_edildi_bfs[i]) {
                kuyruk[son++] = i; 
                ziyaret_edildi_bfs[i] = 1; 
            }
        }
    }
}

int main() {
    
    
    printf("BFS (Genislik Oncelikli Arama) Dolasimi (Istanbul'dan baslayarak):\n");
    BFS(0);
    printf("\n\n");

    printf("DFS (Derinlik Oncelikli Arama) Dolasimi (Istanbul'dan baslayarak):\n");
    DFS(0);
    printf("\n");

    return;
}
