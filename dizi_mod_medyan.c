#include <stdio.h>
// n elemanlı dizinin medyanını ve modunu hesapla
// Medyan için dizinin elemanlarını küçükten büyüğe sırala.Eğer eleman sayısı tek ise ortadaki sayı dizinin medyanıdır.
// Eğer eleman sayısı çift ise ortadaki 2 sayının toplamını yarısı dizinin medyanıdır
// Mod: dizinin en çok tekrar eden elemanıdır
// Örneğin n = 9(tek)  2 1 5 4 5 1 2 3 5  sıralanınca 1 1 2 2 3 4 5 5 5  medyan: 3             mod: 5
// Örneğin n = 6(çift) 2 1 5 7 7 6        sıralanınca 1 2 5 6 7 7        medyan: (5+6)/2=5.5   mod: 7   

int main()
   
{
 
 int i,j;
 int n;
 int gecici;
 
 printf("dizinin eleman sayisini girin: ");
 scanf("%d",&n);
 
 int dizi[n];
 
 for(i = 0 ; i < n ; i++)
 {
  printf("%d.eleman: ",i + 1);
  scanf("%d",&dizi[i]);
 }
 
  for(i = 0 ; i < n ; i++)
  {
    for(j = 0 ; j < n - 1 ; j++)
    {
     if(dizi[j] > dizi[j + 1])
     {
      gecici = dizi[j];
      dizi[j] = dizi[j + 1];
      dizi[j + 1] = gecici;
     }
    }
  }
 
 printf("dizi siralandi: ");
 
 for(i = 0 ; i < n ; i++)
 {
  printf("%d ",dizi[i]);
 }
 
 if(n % 2 == 1) // eleman sayısı tek ise..
 {
  printf("\ndizinin medyani: %d\n",dizi[(n - 1) / 2]);
 }
 
 else // eleman sayısı çift ise..
 {
  printf("\ndizinin medyani: %.2f\n",(dizi[n / 2] + dizi[(n - 1) / 2]) / 2.0);
 }
 
 
 int Max = 0;
 int index;
 // n = 5   1 2 6 6 8  mod: 6     // 1.Adım(i=0)                                                     2.Adım(i=1)                                                         3.Adım(i=2)                                                         4.Adım(i=3)                                                               5.Adım(i=4) 
 for(i = 0 ; i < n ; i++)                     
 {
  int TekrarSayisi = 0;       // TekrarSayisi=0                                                      TekrarSayisi=0                                                     TekrarSayisi=0                                                      TekrarSayisi=0                                                             TekrarSayisi=0
  for(j = i ; j < n - 1 ; j++) // j = 0         j=1             j=2              j=3                 j=0               j=1            j=2            j=3                j=0                 j=1            j=2            j=3               j=0               j=1              j=2               j=3                   j=0                j=1               j=2               j=3
  {  
    if(dizi[i] == dizi[j])                                                                                                                                                                              
    {
     TekrarSayisi++;   // TekrarSayisi=1      TekrarSayisi=1   TekrarSayisi=1  TekrarSayisi=1      TekrarSayisi=0   TekrarSayisi=1  TekrarSayisi=1  TekrarSayisi=1    TekrarSayisi=0     TekrarSayisi=0  TekrarSayisi=1  TekrarSayisi=2    TekrarSayisi=0    TekrarSayisi=0   TekrarSayisi=1    TekrarSayisi=2        TekrarSayisi=0     TekrarSayisi=0    TekrarSayisi=0    TekrarSayisi=0                     
    }
  }
  
  if(TekrarSayisi > Max) // 1 > 0 (true)       1 > 1 (false)        2 > 1 (true)       2 > 2 (false)    0 > 2 (false)
  {
   Max = TekrarSayisi;  // Max = 1                                  Max = 2
   index = i;           // index = 0                                index = 2
  }
 } 
 
 printf("dizinin modu: %d",dizi[index]); // dizi[2] = 6 dizinin modudur
 
 return 0;
 
}