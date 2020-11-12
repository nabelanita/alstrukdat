/* NIM     : 13519104
   Nama    : Nabelanita Utami
   Tanggal : 5 November 2020
   Topik praktikum : List linier
   Deskripsi       : Cache menyimpan daftar nilai, terurut dari yang paling baru digunakan, sampai yang paling lama digunakan.
*/

#include <stdio.h>
#include "listlinier.h"


int main(){
    /* KAMUS */
    int N, op, i, temp;
    List L;
    infotype X;
    address Prec, Pdel;
    /* ALGORITMA */
    scanf("%d", &N);
    scanf("%d", &op);

    CreateEmpty(&L);
    for(i = 1; i <= N; i++){
        InsVLast(&L, i);
    }

    for(i = 0; i < op; i++){
        scanf("%d", &temp);
        if(Search(L, temp) != Nil){
            if(Search(L, temp) != First(L)){
                Prec = SearchPrec(L, temp);
                if(Prec != First(L)){
                    DelAfter(&L, &Pdel, Prec);
                    InsertFirst(&L, Pdel);
                } 
            }
            printf("hit ");
            PrintInfo(L);
        } else {
            DelVLast(&L, &X);
            InsVFirst(&L, temp);
            printf("miss ");
            PrintInfo(L);
        }
    }

    return 0;
}