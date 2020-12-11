// NIM	: 13519104
// Nama	: Nabelanita Utami
// Tanggal	: 27 Agustus 2020
// Topik praktikum	: Looping
// Deskripsi		: Program akan mengolah IP Mahasiswa
#include<stdio.h>
/* SPESIFIKASI
Nama program    : ipmahasiswa.c
Program akan mengolah data IP mahasiswa yang diinputkan */

int main(){
    
    // KAMUS
    float ip;
    int pass = 0;
    int fail = 0;
    int input = 0;
    float total = 0;
    float mean = 0;
    
    // fungsi IsWithinRange
    int IsWithinRange(double x) {
        if (x >= 0 && x <= 4) {
            return 1;
        } else {
            return 0;
        }
    }
    
    // ALGORITMA
    scanf("%f", &ip);
    
    while(ip != -999) {
        if (IsWithinRange(ip)) {
            input += 1;
            total += ip;
            if (ip >= 2.75) {
                pass += 1;
            } else {
                fail += 1;
            }
        }
        
        scanf("%f", &ip);
    }
    
    mean = total / input;
    
    printf("%d\n", input);
    printf("%d\n", pass);
    printf("%d\n", fail);
    printf("%.2f\n", mean);
}