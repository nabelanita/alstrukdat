/*  NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 26 November 2020
    Topik praktikum	: Pohon
    Deskripsi		: program merkle.c */

#include <stdio.h>
#include <math.h>
#include "bintree.h"


BinTree BacaMerkle(int n) {
    /* KAMUS LOKAL */
    int N;
    BinTree P;
    /* ALGORITMA */
    if(n){
        P = AlokNode(0);
        Left(P) = BacaMerkle(n - 1);
        Right(P) = BacaMerkle(n - 1);
        Akar(P) = Akar(Right(P)) + Akar(Left(P));

        return P;
    }
    scanf("%d", &N);
    return AlokNode(N);
}

int main() {
    /* KAMUS */
    int N, i, count = 0;
    BinTree T;
    /* ALGORITMA */
    scanf("%d", &N);
    while (pow(2,count) < N) {
        count++;
    }
    if (pow(2,count) == N) {
        T = BacaMerkle(count);
        PrintTree(T, 2);
    } else {
        printf("Jumlah masukan tidak sesuai\n");
    }
    return 0;
}