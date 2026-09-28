#include <stdio.h>9

//1. sorý: 10 elemanlý dizi ve karmaýklýk Analizi
int main() {
    int n = 10;
    int dizi[10];
    int i;
    
    // Kullanýcýdan elemanlarý alma
    for(i = 0; i < n; i++) {
        printf("%d. elemani giriniz: ", i + 1);
        scanf("%d", &dizi[i]);
    }
    
    // Elemanlarý ekrana yazdýrma
    printf("Girilen elemanlar: ");
    for(i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    
    return 0;
}
/*
      T(n) Zaman Maliyeti:
 Zaman maliyeti, programdaki her bir iþlemin çalýþma sayýsýnýn toplanmasýyla elde edilir.
Deðiþken tanýmlamalarý(n,dizi,i):c1 maliyeti,1 ke çalýþýr
 1. Döngü atamasý(i=0):c2 maliyeti,1 kez çalýþýr.
 1. Döngü koþulu(i<n):c3 maliyet,n+1 kez çalýþýr.
 1. Döngü içi iþlemler(printf ve scanf):c4 maliyet,n kez çalýþýr.
 1. Döngü artýrýmý(i++):c5maliyet,n kez çalýþýr.
Araya girilen yazdýrma iþlemi:c6 maliyet,n kez çalýþýr.
 1. Döngü atamasý(i=0):c7 maliyet,1 kez çalýþýr.
 1. Döngü koþulu(i < n):c8 maliyet,n +1 kez çalýþýr.
 1. Döngü içi iþlemler (printf):c9 maliyeti,n kez çalýþýr.
 1. Döngü artýrýmý(i++):c10 maliyet,n kez çalýþýr.

Sabit maliyetleri(a ve b katsayýlarý) gruplandýgýmýzda dogrusal bir denklem elde edilir:
T(n) = a.n + b
         O(n) zaman Karmaþýklýðý
   T(n)=a.n + b denkelminde katsayýlar(a) ve sabitler(b) göz ardý edilir.
  Sadece en yüksek dereceli büyüme terimi dikkate alýnýr.
Zaman karmaþýklýgý: O(n)
*/

//2.soru: Palindrom Sayý Kontrolü
#include <stdio.h>

int main() {
    int sayi, orijinalSayi, kalan, ters = 0;
    
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &sayi);
    
    orijinalSayi = sayi;
    
    while (sayi != 0) {
        kalan = sayi % 10;           // 1. Son basamaðý bul
        ters = (ters * 10) + kalan;  // 2. Ters sayýyý güncelle
        sayi = sayi / 10;            // 3. Son basamaðý at
    }
    
    if (orijinalSayi == ters) {
        printf("%d bir palindrom sayidir.\n", orijinalSayi);
    } else {
        printf("%d bir palindrom sayi degildir.\n", orijinalSayi);
    }
    
    return 0;
}

