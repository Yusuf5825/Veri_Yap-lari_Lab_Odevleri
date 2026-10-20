Soru 1: 25 değeri eklenirse hangi düğümün altına yerleşir?

Cevap: 30 düğümünün soluna (left) yerleşir.

Açıklama: Ağacın kökü 40'tır. 25 < 40 olduğu için sola (20'ye) gider. 25 > 20 olduğu için sağa (30'a) gider. 25 < 30 olduğu için 30'un sol çocuğu olarak eklenir.



Soru 2: Inorder fonksiyonunda printf() ilk satıra taşınırsa hangi dolaşma elde edilir?

Cevap: Preorder (Öncelikli) dolaşma elde edilir.

Açıklama: Sıralama printf -> left -> right (yani Kök -> Sol -> Sağ) formuna dönüşeceği için bu yapı Preorder (kökün önce ziyaret edildiği) gezintiyi oluşturur.



Soru 3: findMin() içinde left yerine right takip edilirse hangi değer bulunur?

Cevap: Ağaçtaki en büyük değer (Maksimum değer) bulunur. 

Açıklama: İkili Arama Ağacı'nda (BST) büyük elemanlar daima sağ alt ağaca yerleştirildiği için, sürekli sağa gidildiğinde ağacın en büyük elemanına ulaşılır (Sorudaki ağaç için bu değer 70'tir).
