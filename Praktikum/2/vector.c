/*  NIM		: 13519104
    Nama	: Nabelanita Utami
    Tanggal	: 3 September 2020
    Topik praktikum	: ADT
    Deskripsi		: Membuat implementasi vector
 */

#include<stdio.h>
#include "point.h"

#ifndef VECTOR_H
#define VECTOR_H

/* *** Definisi ABSTRACT DATA TYPE VECTOR *** */
#define VECTOR POINT
/* *** Notasi Akses: Selektor VECTOR *** */
#define AbsisComponent(V) Absis(V)
#define OrdinatComponent(V) Ordinat(V)

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y){
    /* Membentuk sebuah VECTOR dengan komponen absis x dan
    komponen ordinat y */
    /* KAMUS */
    VECTOR V;
    /* ALGORITMA */
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;

    return V;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
    /* Nilai v ditulis ke layar dengan format "<X,Y>"
    tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. v terdefinisi */
    /* F.S. v tertulis di layar dengan format "<X,Y>" */
    printf("<%f,%f>\n", AbsisComponent(v), OrdinatComponent(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
    /* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */

    return AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v);
}
VECTOR Add(VECTOR a, VECTOR b){
    /* Menghasilkan sebuah vector yang merupakan hasil a + b.
    Komponen absis vector hasil adalah vector pertama
    ditambah vector kedua, begitu pula dengan ordinatnya */
    return MakeVector(AbsisComponent(a)+AbsisComponent(b), OrdinatComponent(a)+OrdinatComponent(b));
}
VECTOR Substract(VECTOR a, VECTOR b){
    /* Menghasilkan sebuah vector yang merupakan hasil a - b.
    Komponen absis vector hasil adalah vector pertama
    dikurangi vector kedua, begitu pula dengan ordinatnya */
    return MakeVector(AbsisComponent(a)-AbsisComponent(b), OrdinatComponent(a)-OrdinatComponent(b));
}

float Dot(VECTOR a, VECTOR b){
    /* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
    return AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b);
}

VECTOR Multiply(VECTOR v, float s){
    /* Menghasilkan perkalian skalar vector dengan s, yakni
    (s * a.x, s * a.y) */
    return MakeVector(AbsisComponent(v)*s, OrdinatComponent(v)*s);
}

#endif