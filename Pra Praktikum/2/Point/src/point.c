/* Nama: Nabelanita Utami
NIM : 13519104
File: point.c 
Tanggal: 1 September 2020 */

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <math.h>
#include "boolean.h"

typedef struct {
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT(float X, float Y){
    /* Membentuk point dengan absis X dan koordinat Y */
    /* KAMUS */
    POINT P;
    /* ALGORITMA */
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT(POINT * P){
    /* Membaca nilai x dan y masukan lalu mengubahnya menjadi point */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    scanf("%f", &x);
    scanf("%f", &y);

    *P = MakePOINT(x, y);

}

void TulisPOINT(POINT P){
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    printf("(%f, %f)\n", Absis(P), Ordinat(P));
}



/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2){
    /* Memeriksa apakah point P1 sama dengan point P2 dan mengembalikan true jika benar */
    /* ALGORITMA */
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ(POINT P1, POINT P2){
    /* Memeriksa apakah point P1 tidak sama dengan point P2 dan mengembalikan true jika benar */
    /* ALGORITMA */
    return !EQ(P1, P2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin(POINT P){
    /* Memeriksa apakah point P merupakan titik asal dengan X = 0 dan Y = 0 */
    /* ALGORITMA */
    return Absis(P) == 0 && Ordinat(P) == 0;

}

boolean IsOnSbX(POINT P){
    /* Memeriksa apakah point P berada di atas sumbu X */
    /* ALGORITMA */
    return Ordinat(P) == 0;
    
}

boolean IsOnSbY(POINT P){
    /* Memeriksa apakah point P berada di atas sumbu Y */
    /* ALGORITMA */
    return Absis(P) == 0;
}

int Kuadran(POINT P){
    /* Menentukan kuadran point P berada */
    /* ALGORITMA */
    if(Absis(P) > 0) {
        if (Ordinat(P) > 0) {
            return 1;
        } else if(Ordinat(P) < 0){
            return 4;
        } else {
            return -1;
        }
    } else if(Absis(P) < 0) {
        if (Ordinat(P) > 0) {
            return 2;
        } else if(Ordinat(P) < 0){
            return 3;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P){
    /* Menghasilkan salinan P dengan nilai absis ditambah satu */
    /* ALGORITMA */
    return MakePOINT(Absis(P) + 1, Ordinat(P));
}

POINT NextY(POINT P){
    /* Menghasilkan salinan P dengan nilai ordinat ditambah satu */
    /* ALGORITMA */
    return MakePOINT(Absis(P), Ordinat(P) + 1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    /* ALGORITMA */
    return MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY);
}

POINT MirrorOf(POINT P, boolean SbX) {
    /* Mengirim salinan P yang dicerminkan oleh sumbu x bila SbX true, oleh sumbu y bila SbX false */
    /* KAMUS */
    POINT P2;
    float X2, Y2;
    /* ALGORITMA */
    if(SbX) {
        if(Ordinat(P) ==  0) {
            Y2 = 0;
        } else {
            Y2 = - Ordinat(P);
        }
        X2 = Absis(P);
    } else {
        if(Absis(P) == 0) {
           X2 = 0;
        } else {
           X2 = - Absis(P);
        }
        Y2 = Ordinat(P);
    }

    P2 = MakePOINT(X2, Y2);
    return P2;

}

float Jarak0 (POINT P) {
    /* Menghitung jarak P ke titik origin */
    /* ALGORITMA */
    return (float)sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
    /* Mengembalikan panjang garis yang terbentuk dengan menghubungkan P1 dan P2 */
    /* KAMUS */
    /* ALGORITMA */
    return (float)sqrt((Absis(P1) - Absis(P2))*(Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2))*(Ordinat(P1) - Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY){
    /* Mengembalikan point yang absisnya telah digeser sebesar deltaX dan ordinatnya telah digeser sebesar deltaY */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    x = Absis(*P) + deltaX;
    y = Ordinat(*P) + deltaY;
    *P = MakePOINT(x, y);
}

void GeserKeSbX (POINT *P){
    /* Menggeser point sehingga kini point berada di atas sumbu x */
    /* ALGORITMA */
    *P =  MakePOINT(Absis(*P), 0);
}

void GeserKeSbY (POINT *P){
    /* Menggeser point sehingga kini point berada di atas sumbu y */
    /* ALGORITMA */
    *P = MakePOINT(0, Ordinat(*P));
}

void Mirror (POINT *P, boolean SbX) {
    /* Mencerminkan point, apabila SbX true maka akan dicerminkan terhadap sumbu x, jika false maka akan dicerminkan terhadap sumbu y */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    if(SbX) {
        x = Absis(*P);
        y = -Ordinat(*P);
    } else {
        x = -Absis(*P);
        y = Ordinat(*P);
    }

    *P = MakePOINT(x, y);
}

void Putar (POINT *P, float Sudut){
    /* Point P akan digeser sejauh Sudut derajat searah jarum jam dengan sumbu titik (0,0) */
    /* KAMUS */
    float x, y;
    /* ALGORITMA */
    x = Absis(*P)*cos(Sudut*(-0.0174533)) - Ordinat(*P)*sin(Sudut*(-0.0174533));
    y = Absis(*P)*sin(Sudut*(-0.0174533)) + Ordinat(*P)*cos(Sudut*(-0.0174533));


    *P = MakePOINT(x,y);
}

#endif
