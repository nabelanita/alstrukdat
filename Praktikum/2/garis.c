/*  NIM		: 13519104
    Nama	: Nabelanita Utami
    Tanggal	: 3 September 2020
    Topik praktikum	: ADT
    Deskripsi		: Implementasi file garis.h
 */

#include<stdio.h>

/* File: garis.h */
/* Tanggal: 29 Agustus 2019 */
/* Definisi ADT GARIS, menggunakan ADT point */
#ifndef GARIS_H
#define GARIS_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "boolean.h"
#include "point.h"
#include <math.h>

/* *** Definisi TYPE GARIS *** */
typedef struct {
  POINT PAw;  /* Titik Awal  */
  POINT PAkh; /* Titik Akhir */
} GARIS;

/* *** Selektor GARIS *** */
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh
        
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L){
    /* I.S. P1 dan P2 terdefinisi */
    /* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
    /* Membentuk sebuah L dari komponen-komponennya */
    /* KAMUS */
    GARIS a;
    /* ALGORITMA */
    PAwal(a) = P1;
    PAkhir(a) = P2;

    *L = a;

}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L){
    /* I.S. sembarang */
    /* F.S. L terdefinisi sebagai GARIS yang valid */
    /* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
    membentuk GARIS yang valid 
    GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
    /* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
    "Garis tidak valid" */
    /* Contoh:
    2 3
    2 3
    Garis tidak valid
    2 3
    3 3 
    --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
    /* KAMUS */
    GARIS a;
    /* ALGORITMA */
    BacaPOINT(P1);
    BacaPOINT(P2);
    while(P1 == P2){
        printf("Garis tidak valid\n");
        BacaPOINT(P1);
        BacaPOINT(P2);
    }
    MakeGaris(P1, P2, *a)
    *L = a;

}
void TulisGARIS (GARIS L){
    /* I.S. L terdefinisi */
    /* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
    tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
    termasuk spasi dan enter */
    printf("((%f,%f),(%f,%f))\n", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)) );

}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
    /* Menghitung panjang garis L : berikan rumusnya */
    return (float)sqrt((Absis(PAwal(L)) - Absis(PAkhir(L)))*(Absis(PAwal(L)) - Absis(PAkhir(L))) + (Ordinat(PAwal(L)) - Ordinat(PAkhir(L)))*(Ordinat(PAwal(L)) - Ordinat(PAkhir(L))));

}
float Gradien (GARIS L){
    /* Mengembalikan Gradien (m) dari L */
    /* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
    /* Prekondisi : x1 != x2 */
    return (float)(Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))/(float)(Absis(PAkhir(L) - Absis(PAwal(L)));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    /* I.S. L terdefinisi */
    /* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
    /* Proses : PAw dan PAkh digeser. */
    MakeGARIS(MakePOINT(Absis(PAwal(*L)) + deltaX, Ordinat(PAwal(*L)) + deltaY ), MakePOINT(Absis(PAkhir(*L)) + deltaX, Ordinat(PAkhir(*L)) + deltaY), *L);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2) {
    /* Menghasilkan true jika L1 tegak lurus terhadap L2 */
    /* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
    return Gradien(L1) * Gradien(L2) == -1;
}
boolean IsSejajar (GARIS L1, GARIS L2){
    /* Menghasilkan true jika L "sejajar" terhadap L1 */
    /* Dua garis saling sejajar jika memiliki gradien yang sama */
    return Gradien(L1) == Gradien(L2);
}

#endif
