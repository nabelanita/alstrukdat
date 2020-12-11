/* NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 10 November 2020
    Topik praktikum	: List dengan double pointer
    Deskripsi		: Realisasi ADT list dgn double pointer */

#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    return((First(L) == Nil) && (Last(L) == Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    /* I.S. L sembarang  */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil. */
    /* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil. */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = (address) malloc(sizeof(ElmtList));
	if(P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
	}
	return P;
}
void Dealokasi (address P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    /* KAMUS */
	boolean found = false;
    address P;
	/* ALGORITMA */
	if(IsEmpty(L)) {
		return Nil;
	} else {
		P = First(L);
        while((P != Nil) && !found) {
            if(Info(P) == X){
                found = true;
            } else {
                P = Next(P);
            }
        }
        if(found){
            return P;
        } else {
            return Nil;
        }
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    /* KAMUS*/
    address P;
     /* ALGORITMA */
    P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L); 
        if (IsEmpty(*L)) {
            Last(*L) = P; 
        } else {
            Prev(First(*L)) = P; 
        }
        First(*L) = P; 
    }
}
void InsVLast (List *L, infotype X) {
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    address P;
     /* ALGORITMA */
    P = Alokasi(X);
    if (P != Nil) {
        Prev(P) = Last(*L); 
        if (!IsEmpty(*L)) {
            Next(Last(*L)) = P; 
        } else {
            First(*L) = P; 
        }
        Last(*L) = P; 
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = First(*L);
    *X = Info(P);
    if (First(*L) == Last(*L)) {
        Last(*L) = Nil;
    } else { 
        Prev(Next(First(*L))) = Nil; 
    }
    First(*L) = Next(First(*L));
    Dealokasi(P);
}
void DelVLast (List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = Last(*L);
    *X = Info(P);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
    } else {
        Next(Prev(Last(*L))) = Nil; 
    }
    Last(*L) = Prev(Last(*L));
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    /* ALGORITMA */
    Next(P) = First(*L);
	if (First(*L) == Nil){
		Last(*L) = P;
		Next(Last(*L)) = Nil;
    } else {
		Prev(First(*L)) = P;
	}
	First(*L) = P;
	Prev(First(*L)) = Nil;
}
void InsertLast (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    /* ALGORITMA */
    Prev(P) = Last(*L);
	if (Last(*L) == Nil) {
		First(*L) = P;
		Prev(First(*L)) = Nil;
    } else {
		Next(Last(*L)) = P;
	}
	Last(*L) = P;
	Next(Last(*L)) = Nil;
}
void InsertAfter (List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    /* ALGORITMA */
    if (Next(Prec) != Nil) { /* Prec bukan elemen terakhir */
        Prev(Next(Prec)) = P;
    } else { /* Prec elemen terakhir */
        Last(*L) = P; 
    }
    Next(P) = Next(Prec); 
    Prev(P) = Prec; 
    Next(Prec) = P;
}
void InsertBefore (List *L, address P, address Succ){
    /* I.S. Succ pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    /* ALGORITMA */
    Next(P) = Succ;
	Prev(P) = Prev(Succ);
	Prev(Succ) = P;
	if (Prev(P) == Nil) {
		First(*L) = P;
		Prev(First(*L)) = Nil;
    } else {
		Next(Prev(P)) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    /* ALGORITMA */
    *P = First(*L);
    if(Next(First(*L)) == Nil){
        CreateEmpty(L);
    } else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
    }
}
void DelLast (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    /* ALGORITMA */
    *P = Last(*L);
	if (Prev(Last(*L)) == Nil) {
		CreateEmpty(L);
    } else {
        Last(*L) = Prev(Last(*L));
		Next(Last(*L)) = Nil;
    }
}
void DelP (List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* maka P dihapus dari list dan didealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    /* KAMUS */
    address P = First(*L);
    address temp;
    boolean found = false;
    /* ALGORITMA */
	while (P != Nil && !found) {
		temp = Next(P);
		if (Info(P) == X) {
            if(P == First(*L)){
                First(*L) = temp;
                Prev(temp) = Nil;
                Prev(Next(First(*L))) = temp;
                Next(P) = Nil;
            } else if (P == Last(*L)) {
                Next(Prev(P)) = Nil;
                Last(*L) = Prev(P);
            } else {
                Next(Prev(P)) = temp;
                Prev(temp) = Prev(P);
                Next(P) = Nil;
            }
			Dealokasi(P);
            found = true;
		}
		P = temp;
	}
}
void DelAfter (List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list. */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    /* KAMUS */
    address P;
    /* ALGORITMA */
	P = Next(Prec);
    *Pdel = Next(Prec);
	if(P != Nil) {
		if (Next(P) == Nil) {
			Last(*L) = Prec;
			Next(Last(*L)) = Nil;
        } else {
			Prev(Next(P)) = Prec;
		}
		Next(Prec) = Next(P);
	}
}
void DelBefore (List *L, address *Pdel, address Succ){
    /* I.S. List tidak kosong. Succ adalah anggota list. */
    /* F.S. Menghapus Prev(Succ): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    /* KAMUS */
    address P;
    /* ALGORITMA */
	P = Prev(Succ);
    *Pdel = Prev(Succ);
	if(P != Nil) {
		if(Prev(P) == Nil) {
			First(*L) = Succ;
			Prev(First(*L)) = Nil;
        } else {
			Next(Prev(P)) = Succ;
		}
		Prev(Succ) = Prev(P);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
    /* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
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
        while(P != Nil){
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");

}
void PrintBackward (List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
    /* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    if(IsEmpty(L)) {
        printf("[]");
    } else {
        printf("[");
        P = Last(L);
        while(P != Nil){
            if(P == First(L)){
                printf("%d]", Info(P));
            } else {
                printf("%d,", Info(P));
            }
            P = Prev(P);
        }
    }
}