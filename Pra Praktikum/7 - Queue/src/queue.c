/* File : queue.h */
/* NIM				: 13519104
Nama				: Nabelanita Utami
Tanggal				: 5 Oktober 2020
Topik praktikum		: Queue
Deskripsi praktikum	: Implementasi ADT Queue */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */

/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef int infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype * T;   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    /* ALGORITMA */
    return((Head(Q) == Nil) && (Tail(Q) == Nil));
}
int NBElmt (Queue Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    /* ALGORITMA */
    if(IsEmpty(Q)){
        return 0;
    } else if (Tail(Q) == Head(Q)){
        return 1;
    } else {
       if (Head(Q) > Tail(Q)) {
            return ((Tail(Q) + 1) + (MaxEl(Q) - Head(Q)));
        }
        else {
            return Tail(Q) - Head(Q) + 1;
        }

    }
    
}
boolean IsFull (Queue Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    /* ALGORITMA */
    return(NBElmt(Q) == MaxEl(Q));

}

/* *** Kreator *** */
void MakeEmpty (Queue * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    /* ALGORITMA */
    (*Q).T = (infotype*)malloc(Max * sizeof(infotype));
    if((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }

}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    /* ALGORITMA */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (Queue * Q, infotype X){
    /* Proses: Menambahkan X pada Q dengan aturan FIFO */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    /* ALGORITMA */
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        if(Tail(*Q) == MaxEl(*Q) - 1){
            Tail(*Q) = 0;
        } else {
            Tail(*Q)++;
        }
        InfoTail(*Q) = X;
    }
}
void Dequeue (Queue * Q, infotype * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
            Q mungkin kosong */
    /* ALGORITMA */
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if(Head(*Q) == MaxEl(*Q) - 1){
            Head(*Q) = 0;
        } else {
            Head(*Q)++;
        }
    }

}

#endif