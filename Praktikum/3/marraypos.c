/* NIM      : 13519104
Nama        : NABELANITA UTAMI
Tanggal     : 10 SEPTEMBER 2020
Topik praktikum : ADT LIST
Deskripsi       : Menulis list dan searching */ 

#include <stdio.h>
#include "boolean.h"
#include "arraypos.c"

int main(){
    /* KAMUS */
    TabInt T;
    ElType a, max, min;

    /* ALGORITMA */
    MakeEmpty(&T);
    BacaIsi(&T);
    printf("\n");
    scanf("%d", &a);
    TulisIsiTab(T);
    if(Search1(T, a) == IdxUndef){
        printf("tidak ada\n");
    } else {
        printf("\n");
        printf("%d", Search1(T, a));
        MaxMin(T, &max, &min);
        if(max == a){
            printf("maksimum\n");
        }
        if(min == a){
            printf("minimum\n");
        }

        Sort(&T, true);
        if(!(NbElmt(T) % 2)){
            if(Search1(T, a) == (NbElmt(T)/2)){
                printf("median\n");
            }

        } else {
            if(Search1(T, a) == (NbElmt(T)/2) + 1){
                printf("median\n");
            }

        }

    }
    
    return 0;
}