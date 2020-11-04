// NIM	: 13519104
// Nama	: Nabelanita Utami
// Tanggal	: 27 Agustus 2020
// Topik praktikum	: Control flow
// Deskripsi		: Program akan menentukan beasiswa yang didapatkan oleh mahasiswa

#include<stdio.h>

/* SPESIFIKASI 
Nama program    : beasiswa.c
Program akan menentukan beasiswa yang diterima oleh mahasiswa */

int main(){
    
    // KAMUS
    float ip;
    float pot;
    
    // ALGORITMA
    scanf("%f", &ip);
    scanf("%f", &pot);
    
    if (ip >= 3.5) {
        printf("4");
    } else if (pot < 1) {
        printf("1");
    } else if (pot >= 1 && pot < 5) {
        if (ip >= 2) {
            printf("3");
        } else {
            printf("2");
        }
    } else {
        printf("0");
    }
}