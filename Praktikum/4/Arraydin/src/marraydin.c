/* Nama     : Nabelanita Utami
NIM         : 13519104 
Tanggal     : 17 September 2020
Topik       : Array Dinamis
Deskripsi   : Pengolahan array*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main() {
    /* Sebuah program yang digunakan untuk membaca sebuah TabInt, misalnya T, dengan kapasitas awal 
    MaxEl (MaxEl dibaca dari keyboard), lalu membaca elemen-elemen T dari keyboard sebanyak N. 
    N harus bernilai 0 <= N <= MaxNbEl(T). Program akan melakukan operasi sesuai dengan menu yang dipilih oleh user. */
    /* KAMUS */
    int max, N, op, num, Q, m;
    IdxType i;
    TabInt T, temp;
    /* ALGORITMA */
    scanf("%d", &max);
    MakeEmpty(&T, max);

    BacaIsi(&T);
    TulisIsiTab(T);

    scanf("%d", &Q);
    m = 0;

    while(m < Q){
        scanf("%d", &op);
        if(op == 1){
            if(IsFull(T)){
                printf("array sudah penuh\n");
            }else{
                scanf("%d", &num);
                AddAsLastEl(&T, num);
                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
            }

        } else if(op == 2){
            scanf("%d", &num);
            CopyTab(T, &temp);
            GrowTab(&T, num);
            for(i = 0; i < Neff(temp); i++){
                Elmt(T, i) = Elmt(temp, i);
            }
            Dealokasi(&temp);
            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
        } else if(op == 3){
            scanf("%d", &num);
                if(MaxEl(T) < num){
                    printf("array terlalu kecil\n");
                } else {
                    CopyTab(T, &temp);
                    ShrinkTab(&T, num);
                    for(i = 0; i < Neff(temp); i++){
                        Elmt(T, i) = Elmt(temp, i);
                    }
                    Dealokasi(&temp);
                }
                printf("%d ", MaxEl(T));
                TulisIsiTab(T);
        } else {
            CompactTab(&T);
            printf("%d ", MaxEl(T));
            TulisIsiTab(T);
        }

        m++;
            
    }


    return 0;
}