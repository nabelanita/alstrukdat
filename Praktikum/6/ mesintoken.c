/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */
/* NAMA : NABELANITA UTAMI */
/* NIM  : 13519104 */
#include <stdio.h>
#include "boolean.h"
#include "mesinkar.c"
#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : CC sembarang 
    F.S. : CC ≠ BLANK atau CC = MARK */
   while(CC == BLANK){
       ADV();
   }  
}

void STARTTOKEN(){
    /* I.S. : CC sembarang 
    F.S. : EndToken = true, dan CC = MARK; 
            atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
            CC karakter pertama sesudah karakter terakhir Token */
    START();
    IgnoreBlank();
    if(CC == MARK){
        EndToken = true;
    } else {
        EndToken = false;
        SalinToken();
    }

}

void ADVTOKEN(){
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
    F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
            CC adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika CC = MARK, maka EndToken = true		  
    Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    if(CC == MARK){
        EndToken = true;
    } else {
        SalinToken();
        IgnoreBlank();
    }

}

void SalinToken(){
    /* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
    I.S. : CC adalah karakter pertama dari Token
    F.S. : CToken berisi Token yang sudah diakuisisi; 
            CC = BLANK atau CC = MARK; 
            CC adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /* ALGORITMA */
    int tokens;
    int i = 0;
    int value = 0;
    IgnoreBlank();
    while((CC != MARK) && (CC != BLANK) && i < NMax){
        if(CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^'){
            CToken.tkn = CC;
            CToken.val = -1;
            ADVTOKEN();
        } else {
            CToken.tkn = 'b';
            CToken.val = (int) CC;
            i++;
            ADV();
        }
        
    }
    

}
