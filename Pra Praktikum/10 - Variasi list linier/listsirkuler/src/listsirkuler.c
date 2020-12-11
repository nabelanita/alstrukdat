/*  NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 10 November 2020
    Topik praktikum	: List sirkuler
    Deskripsi		: Realisasi ADT list sirkuler */

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    return(First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    /* I.S. L sembarang             */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    /* ALGORITMA */
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
        return P;
	} else {
        return Nil;
    }
}
void Dealokasi (address P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    /* ALGORITMA */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    /* KAMUS */
    address P;
    boolean found = false;
    /* ALGORITMA */
    if(!IsEmpty(L)) {
		P = First(L);
        do {
            if(Info(P) == X) {
                found = true;
            } else {
                P = Next(P);
            }
        } while((P != First(L)) && !found);
        
		if(found){
            return P;
        } else {
            return Nil;
        }
	} else
		return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    /* KAMUS */
    address P = Alokasi(X);
    /* ALGORITMA */
	if(P != Nil){
		InsertFirst(L, P);
    }
}
void InsVLast (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    address P = Alokasi(X);
    /* ALGORITMA */
	if(P != Nil){
		InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
	DelFirst(L, &P);
	*X = Info(P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype * X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
	DelLast(L, &P);
	*X = Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    /* ALGORITMA */
    InsertLast(L, P);
    First(*L) = P;
}
void InsertLast (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    /* KAMUS */
    address Last;
    /* ALGORITMA */
    if (IsEmpty(*L)) {
		First(*L) = P;
		Next(P) = P;
	} else {
		Last = First(*L);
		while(Next(Last) != First(*L)){
			Last = Next(Last);
        }
		InsertAfter(L, P, Last);
	}
}
void InsertAfter (List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    /* KAMUS */
    /* ALGORITMA */
    Next(P) = Next(Prec);
	Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    /* KAMUS */
    address Last = First(*L);
    /* ALGORITMA */
	if(Next(First(*L)) == First(*L)){
        (*P) = First(*L);
		CreateEmpty(L);
    } else {
		while(Next(Last) != First(*L)){
			Last = Next(Last);
        }
		DelAfter(L, P, Last);
	}
}
void DelLast (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, */
    /* jika ada */
    /* KAMUS */
    address Last =  First(*L);
    /* ALGORITMA */
    if (Next(Last) == First(*L)) {
		(*P) = First(*L);
		CreateEmpty(Nil);
	} else {
		while (Next(Next(Last)) != First(*L)) {
			Last = Next(Last);
		}
		DelAfter(L, P, Last);
	}
}
void DelAfter (List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    /* ALGORITMA */
	if (Next(First(*L)) == First(*L)){
		CreateEmpty(L);
    } else {
		if (Next(Prec) == First(*L)) {
			First(*L) = Next(Next(Prec));
        }
        (*Pdel) = Next(Prec);
		Next(Prec) = Next(Next(Prec));
	}
}
void DelP (List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    /* KAMUS */
    address P = Search(*L, X);
    address Prec = First(*L);
    /* ALGORITMA */
	if(P != Nil){
        if(Next(Prec) == First(*L)){
            CreateEmpty(L);
        } else {
            while(Next(Prec) != P){
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
            Dealokasi(P);
        }
    }
	
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    printf("[");
    if(!IsEmpty(L)){
        printf("%d", Info(First(L)));
        P = Next(First(L));
        while(P != First(L)){
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
