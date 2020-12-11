/* NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 18 November 2020
    Topik praktikum	: List Rekursif
    Deskripsi		: Implementasi listrek.h */

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
    maka Info(P) = X, Next(P) = Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = (address) malloc(sizeof(infotype));
    if (P != Nil) {
      Info(P) = X;
      Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    /* ALGORITMA */
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L) {
    /* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    /* ALGORITMA */
    return (L == Nil);
}
int IsOneElmt(List L) {
    /* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    /* ALGORITMA */
    if (IsEmpty(L)) {
		  return 0;
    } else {
		  return Next(L) == Nil;
    }
}

/* *** Selektor *** */
infotype FirstElmt (List L) {
    /* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
    /* ALGORITMA */
    return Info(L);
}
List Tail(List L) {
    /* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
    /* ALGORITMA */
    return Next(L);
}

/* *** Konstruktor *** */
List Konso(infotype e, List L){
    /* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
    e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = Alokasi(e);
    if (P == Nil) {
      return L;
    } else {
      Next(P) = L;
      return P;
    }
}
List KonsB(List L, infotype e) {
    /* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
    /* e harus dialokasi terlebih dahulu */
    /* Jika alokasi e gagal, mengirimkan L */ 
    /* KAMUS */
    address P, Q, Last;
    /* ALGORITMA */
    P = Alokasi(e);
    if (P != Nil) {
      if (IsEmpty(L)) {
        return P;
      } else {
        Q = L;
        Last = Nil;
        while (Q != Nil) {
          Last = Q;
          Q = Next(Q);
        }
        Next(Last) = P;
      }
    }
    return L;
}

/* *** Operasi Lain *** */
List Copy (List L) {
    /* Mengirimkan salinan list L (menjadi list baru) */
    /* Jika ada alokasi gagal, mengirimkan L */ 
    /* ALGORITMA */
    if (IsEmpty(L)) {
		  return Nil;
    } else {
		  return Konso(Info(L), Tail(L));
    }
}
void MCopy (List Lin, List *Lout) {
    /* I.S. Lin terdefinisi */
    /* F.S. Lout berisi salinan dari Lin */
    /* Proses : menyalin Lin ke Lout */
    /* ALGORITMA */
    List cp = Copy(Lin);
	  *Lout = cp;
}
List Concat (List L1, List L2) {
    /* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
    /* Jika ada alokasi gagal, menghasilkan Nil */
    /* ALGORITMA */
    if (IsEmpty(L1)) {
		  return L2;
    } else if (IsEmpty(L2)) {
		  return L1;
    } else {
		  return Concat(KonsB(L1, Info(L2)), Tail(L2));
    }
}
void MConcat (List L1, List L2, List *LHsl) {
    /* I.S. L1, L2 terdefinisi */
    /* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
    /* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
    /* ALGORITMA */
    *LHsl = Concat(L1,L2);
}
void PrintList (List L) {
    /* I.S. L terdefinisi. */
    /* F.S. Setiap elemen list dicetak. */
    if (!IsEmpty(L)) {
      printf("%d\n", FirstElmt(L));
      PrintList(Tail(L));
  	}
}
int NbElmtList (List L) {
    /* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
    /* ALGORITMA */
    if (IsEmpty(L)) {
		  return 0;
    } else {
		  return 1 + NbElmtList(Tail(L));
    }
}
boolean Search (List L, infotype X) {
    /* Mengirim true jika X adalah anggota list, false jika tidak */
    if (IsEmpty(L)) {
      return false;
    } else if (Info(L) == X) {
		  return true;
    } else {
		  return Search(Tail(L), X);
    }
}

