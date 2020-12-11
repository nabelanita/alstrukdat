/* NAMA : NABELANITA UTAMI
   NIM  : 13519104 */

/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int Length;
} Kata;

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void SalinKata(){
    /* Mengakuisisi kata, menyimpan dalam CKata
    I.S. : CC adalah karakter pertama dari kata
    F.S. : CKata berisi kata yang sudah diakuisisi; 
            CC = BLANK atau CC = MARK; 
            CC adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /* KAMUS */
    int i = 0;
    /* ALGORITMA */
    while((CC != BLANK) && (CC != MARK)){
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i;
}

void IgnoreBlank(){
   /* Mengabaikan satu atau beberapa BLANK
      I.S. : CC sembarang 
      F.S. : CC ≠ BLANK atau CC = MARK */
   /* KAMUS */
   /* ALGORITMA */  
   while(CC == BLANK){
       ADV();
   }    
} 

void ADVKATA(){
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
    F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
            CC adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika CC = MARK, EndKata = true.		  
    Proses : Akuisisi kata menggunakan procedure SalinKata */
    /* KAMUS */
    /* ALGORITMA */
    IgnoreBlank();
    if(CC == MARK){
        EndKata = true;
    } else {
        SalinKata();
    }
}


void STARTKATA(){
    /* I.S. : CC sembarang 
    F.S. : EndKata = true, dan CC = MARK; 
            atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
            CC karakter pertama sesudah karakter terakhir kata */
    /* KAMUS */
    /* ALGORITMA */
    START();
    IgnoreBlank();
    if(CC == MARK){
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }

}

#endif
