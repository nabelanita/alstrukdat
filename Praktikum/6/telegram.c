/* NAMA : NABELANITA UTAMI */
/* NIM  : 13519104 */
#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
/* function IsKataSama (K1, K2 : Kata) ? boolean

 { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. Dua kata kosong adalah kata yang sama. } */
Kata titik, koma;

boolean isKataSama(Kata A, Kata B){
    boolean result = (A.Length == B.Length);
    if(result){
        int i;
        for(i = 0; i < A.Length; i++){
            if(A.TabKata[i] != B.TabKata[i]){
                result = false;
            }
        }
    }
    return result;
}

int main(){
    STARTKATA();
    int reg = 0, longWord = 0;
    boolean first = true;

    char dot[] = "TITIK";
    char comma[] = "KOMA";
    int k, l;
    for(k = 0; k < 5; k++){
        titik.TabKata[k] = dot[k];
    }

    for(l = 0; l < 4; l++){
        koma.TabKata[l] = comma[k];
    }

    titik.Length = 5;
    koma.Length = 4;

    while(!EndKata){
        if(!isKataSama(CKata, koma) && !isKataSama(CKata, titik)){
            if(!first && CKata.Length > 0){
                printf(" ");
            }
            first = false;
            if(CKata.Length < 10){
                reg += 1;
            } else {
                reg += 0;
            }
            if(CKata.Length >= 10){
                longWord += 1;
            } else {
                longWord += 0;
            }

            int m;
            for(m = 0; m < CKata.Length; m++){
                printf("%c", CKata.TabKata[m]);
            } 

        }else if(isKataSama(CKata, koma)){
                printf(",");
        }else if(isKataSama(CKata, titik)){
            printf(".");
        }
        ADVKATA();
    }


    int pay = 10;
    if((reg + longWord) > 10){
        pay *= 900;
    } else {
        pay *= 1000;
    }

    int temp = longWord;

    if((reg+longWord) > 10){
        temp *= 1350;
    } else {
        temp *= 1500;
    }
    
    pay += temp;

    printf("\n%d\n%d\n%d\n", reg, longWord, pay);
    return 0;
}