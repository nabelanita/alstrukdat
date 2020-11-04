// NIM	: 13519104
// Nama	: Nabelanita Utami
// Tanggal	: 27 Agustus 2020
// Topik praktikum	: Control flow
// Deskripsi		: Program akan memprint angka terbesar dari 3 angka inputan user

#include<stdio.h>
/* SPESIFIKASI PROGRAM
Program akan mencari nilai tertinggi dari 3 angka yang diinput user kemudian
memprint hasilnya ke layar */

int main(){
	//KAMUS
    int A;
    int B;
    int C;
    
    //ALGORITMA
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    
    if (A >= B) {
        if (A >= C) 
            printf("%d",A);
        else 
            printf("%d",C);
        
    } else {
        if (B >= C) 
            printf("%d",B);
        else
            printf("%d",C);
        
    }
    return 0;
    
}