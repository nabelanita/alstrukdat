/*  NIM     : Nabelanita Utami
    Nama    : 13519104
    Tanggal : 21 September 2020
    Topik praktikum : ADT Matriks
    Deskripsi       : Mengelola data nilai mahasiswa pada beberapa mata kuliah 
                      di suatu kelas dengan memanfaatkan ADT Matriks yang sudah dimodifikasi */

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX(MATRIKS M, indeks j, ElType X){
    indeks i;
    int p = 0;
    p = CountXKol(M, j, X);

    if(p == 0){
        printf("[]");
    } else {
        printf("[");
        for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            if(Elmt(M, i, j) == X){
                if(p == 1){
                    printf("%d]", i);
                } else {
                    printf("%d,", i);
                    p--;
                }
            }
        }

    }
}

void TulisStatistikMhs(MATRIKS M, indeks i){
    float mean = RataBrs(M, i);
    int max, min;
    MaxMinBrs(M, i, &max, &min);
    printf("[%d] %.2f %d %d\n", i, mean, max, min);
}

void TulisStatistikMK(MATRIKS M, indeks j){
    float mean = RataKol(M, j);
    ElType max = 0, min = 0;
    MaxMinKol(M, j, &max, &min);
    indeks i;
    int p = 0, q = 0;
    p = CountXKol(M, j, max);
    q = CountXKol(M, j, min);

    printf("[%d] %.2f [%d %d ", j, mean, max, p);
    TulisNilaiX(M, j, max);
    printf("] [%d %d ", min, q);
    TulisNilaiX(M, j, min);
    printf("]\n");

}

int main() {
    int row, col;
    indeks i, j;
    MATRIKS M;
    scanf("%d", &row);
    scanf("%d", &col);
    BacaMATRIKS(&M, row, col);

    printf("STATISTIK PER MAHASISWA\n");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        TulisStatistikMhs(M, i);
        
    }

    printf("STATISTIK PER MATA KULIAH\n");
    for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
        TulisStatistikMK(M, j);

    }

    return 0;
}