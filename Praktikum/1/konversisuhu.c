// NIM	: 13519104
// Nama	: Nabelanita Utami
// Tanggal	: 27 Agustus 2020
// Topik praktikum	: Control flow
// Deskripsi		: Program akan memprint konversi suhu

#include<stdio.h>
/* SPESIFIKASI
Nama Program: konversisuhu.c
Program akan mengkonversi suhu sesuai masukan user */

int main(){
    // KAMUS
    double temp;
    char unit;
    double R;
    double K;
    double F;
    
    // ALGORITMA
    scanf("%lf", &temp);
    scanf(" %c", &unit);
    
    
    if (unit == 'R') {
        R = (double)4 / 5 * temp;
        printf("%.2f", R);
    } else if (unit == 'K') {
        K = temp + 273.15;
        printf("%.2f", K);
    } else {
        F = ((double)9 / 5 * temp) + 32;
        printf("%.2f", F);
    }
    
    return 0;
    
}