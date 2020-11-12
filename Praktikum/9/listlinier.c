/*  NIM     : 13519104
   Nama    : Nabelanita Utami
   Tanggal : 5 November 2020
   Topik praktikum : List linier
   Deskripsi       : Realisasi listlinier.h
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
 
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
   /* Mengirim true jika list kosong */
   return(First(L) == NULL);
}
 
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
   /* I.S. sembarang             */
   /* F.S. Terbentuk list kosong */
   First(*L) = Nil;
}
 
/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
   /* Mengirimkan address hasil alokasi sebuah elemen */
   /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
   /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
   /* Jika alokasi gagal, mengirimkan Nil */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   P = (ElmtList *) malloc(sizeof(ElmtList));
   if (P!= Nil) {
       Info(P) = X;
       Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P){
   /* I.S. P terdefinisi */
   /* F.S. P dikembalikan ke sistem */
   /* Melakukan dealokasi/pengembalian address P */
   free(*P);
}
 
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
   /* Mencari apakah ada elemen list dengan Info(P)= X */
   /* Jika ada, mengirimkan address elemen tersebut. */
   /* Jika tidak ada, mengirimkan Nil */
   /* KAMUS */
   address P = First(L);
   boolean found = false;
   /* ALGORITMA */
   while(!found && (P != Nil)) {
       if (Info(P) == X) {
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

boolean FSearch (List L, address P) {
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */   
    /* KAMUS */
    address P1 = First(L);
    boolean found = false;
    /* ALGORITMA */
    while((!found) && (P1 != Nil)) {
        if (P1 == P) {
            found = true;
        } else {
            P1 = Next(P1);
        }
    }

    return found;
}

address SearchPrec (List L, infotype X){
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain */
    /* KAMUS */
    boolean found;
    address P = First(L), prec = Nil;
    /* Algoritma */
    while((!found) && (P != Nil)){
        if (Info(P) == X) {
            found = true;
        } else {
            prec = P;
            P = Next(P);
        }
    }

    if(found){
        return prec;
    } else {
        return Nil;
    }
}
 
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
   /* I.S. L mungkin kosong */
   /* F.S. Melakukan alokasi sebuah elemen dan */
   /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
   /* KAMUS */
   address P = Alokasi(X);
   /* ALGORITMA */
   if(P != Nil) {
       Next(P) = First(*L);
       First(*L) = P;
    }
}
void InsVLast (List *L, infotype X){
   /* I.S. L mungkin kosong */
   /* F.S. Melakukan alokasi sebuah elemen dan */
   /* menambahkan elemen list di akhir: elemen terakhir yang baru */
   /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   P = Alokasi(X);
   if(P != Nil) {
       InsertLast(L,P);
    }
}
 
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
   /* I.S. List L tidak kosong  */
   /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
   /*      dan alamat elemen pertama di-dealokasi */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   DelFirst(L, &P);
   *X = Info(P);
   Dealokasi(&P);
}
void DelVLast (List *L, infotype *X){
   /* I.S. list tidak kosong */
   /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
   /*      dan alamat elemen terakhir di-dealokasi */
   /* KAMUS */
   address P;
   /* ALGORITMA */
   DelLast(L, &P);
   *X = Info(P);
   Dealokasi(&P);
}
 
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
   /* I.S. Sembarang, P sudah dialokasi  */
   /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
   /* ALGORITMA */
   Next(P) = First(*L);
   First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
   /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
   /*      P sudah dialokasi  */
   /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
   /* ALGORITMA */
   Next(P) = Next(Prec);
   Next(Prec) = P;
}
void InsertLast (List *L, address P){
   /* I.S. Sembarang, P sudah dialokasi  */
   /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
   /* KAMUS */
   address last;
   /* ALGORITMA */
    if(IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
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
   First(*L) = Next(First(*L));
   Next(*P) = Nil;
}
void DelP (List *L, infotype X){
   /* I.S. Sembarang */
   /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
   /* Maka P dihapus dari list dan di-dealokasi */
   /* Jika ada lebih dari satu elemen list dengan Info bernilai X */
   /* maka yang dihapus hanya elemen pertama dengan Info = X */
   /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
   /* List mungkin menjadi kosong karena penghapusan */
   /* KAMUS */
   address P = First(*L), del, prec = Nil;
   boolean found = false;
   /* ALGORITMA */
   while((P != Nil) && (!found)) {
       if (Info(P) == X) {
           found = true;
       } else {
           prec = P;
           P = Next(P);
       }
    }
 
   if(found) {
        if (prec == Nil) {
            DelFirst(L, &del);
        } else {
            DelAfter(L, &del, prec);
        }
        Dealokasi(&del);
    }
}
 
void DelLast (List *L, address *P){
	/* I.S. List tidak kosong */
	/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/* Last element baru adalah predesesor elemen terakhir yg lama, */
	/* jika ada */
	/* KAMUS */
	address last = First(*L), precLast = Nil;
	/* KAMUS */
    while(Next(last) != Nil) {
        precLast = last;
        last = Next(last);
    }

    if(precLast == Nil) {
        DelFirst(L, P);
    } else {
        DelAfter(L, P, precLast);
    }

}

void DelAfter (List *L, address *Pdel, address Prec) {
	/* I.S. List tidak kosong. Prec adalah anggota list  */
	/* F.S. Menghapus Next(Prec): */
	/*      Pdel adalah alamat elemen list yang dihapus  */
	/* KAMUS */
	address P = First(*L);
	boolean found = false;
	/* ALGORITMA  */
	while((P != Nil) && (!found)) {
        if (P == Prec) {
            found = true;
        } else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}
 
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	/* KAMUS */
	address P;
	/* ALGORITMA */
	if(IsEmpty(L)){
        printf("[]\n");
    } else { 
        P = First(L);
        printf("[%d", Info(P));
        P = Next(P);
        while(P != Nil) {
            printf(",%d", Info(P));
            P = Next(P);
        }
        printf("]\n");
    }
}

int NbElmt (List L){
	/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
	/* KAMUS */
	address P;
	int count = 0;
	/* ALGORITMA */
	if(IsEmpty(L)){
		return 0;
	} else {
		P = First(L);
		while(P != Nil){
			count++;
			P = Next(P);
		}
		return count;
	}
}
 
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
	/* Mengirimkan nilai Info(P) yang maksimum */
	/* KAMUS */
	address P = Next(First(L));
	infotype maximum = Info(First(L));
	/* ALGORITMA */
	while(P != Nil){
        if(maximum < Info(P)) {
            maximum = Info(P);
        }
        P = Next(P);
    }
    return maximum;
}
 
address AdrMax (List L){
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    /* ALGORITMA */
    return Search(L, Max(L));
}

infotype Min (List L){
	/* Mengirimkan nilai Info(P) yang minimum */
	/* KAMUS */
    address P = Next(First(L));
	infotype minimum = Info(First(L));
	/* ALGORITMA */
    while(P != Nil){
        if(minimum > Info(P)) {
            minimum = Info(P);
        }
        P = Next(P);
    }
    return minimum;
}
address AdrMin (List L){
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    /* ALGORITMA */
    return(Search(L, Min(L)));
}

float Average (List L){
    /* Mengirimkan nilai rata-rata info(P) */
    /* KAMUS */
    address P = First(L);
    infotype total = 0;
    int count = 0;
    /* ALGORITMA */
    while(P != Nil){
        total = Info(P);
        count++;
        P = Next(P);
    }

    return((float)total/(float)count);
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L){
    /* Delete semua elemen list dan alamat elemen di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    while(!IsEmpty(*L)){
        DelFirst(L, &P);
        Dealokasi(&P);
    }
}

void InversList (List *L){
    /* Mengirimkan list baru, hasil invers dari L */
    /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
    /* Jika alokasi gagal, hasilnya list kosong */
    /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS */
    address P = First(*L), last, prec = Nil;
    /* ALGORITMA */
    while(P != Nil){
        last = P;
        P = Next(P);
        Next(last) = prec;
        prec = last;
    }
    
    First(*L) = last;
}

void CopyList (List *L1, List *L2) {
    /* I.S. L1 sembarang. F.S. L2=L1 */
    /* L1 dan L2 "menunjuk" kepada list yang sama.*/
    /* Tidak ada alokasi/dealokasi elemen */
    First(*L2) = First(*L1);
}

List FCopyList (List L) {
    /* Mengirimkan list yang merupakan salinan L */
    /* dengan melakukan alokasi. */
    /* Jika ada alokasi gagal, hasilnya list kosong dan */
    /* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS */
    boolean fail = false;
    List copy;
    address P = First(L), P1;
    /* ALGORITMA */
    CreateEmpty(&copy);
    while((P != Nil) && (!fail)) {
        P1 = Alokasi(Info(P));
        if(P1 == Nil){
            fail = true;
            DelAll(&copy);
        } else {
            InsertLast(&copy, P1);
            P = Next(P);
        }
    }
    return copy;
}

void CpAlokList (List Lin, List *Lout){
    /* I.S. Lin sembarang. */
    /* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
    /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
    /* dengan melakukan alokasi elemen. */
    /* Lout adalah list kosong jika ada alokasi elemen yang gagal */
    /* ALGORITMA */
    *Lout = FCopyList(Lin);
}

List FInversList (List L){
    /* Mengirimkan list baru, hasil invers dari L */
    /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
    /* Jika alokasi gagal, hasilnya list kosong */
    /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS */
    List invers;
    /* ALGORITMA */
    CpAlokList(L, &invers);
    InversList(&invers);
    return invers;
}

void Konkat (List L1, List L2, List * L3){
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
    /* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
    /* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
    /* harus di-dealokasi dan L3=Nil*/
    /* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
    /* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
    /* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
    /* dan semua elemen yang pernah dialokasi didealokasi */
    /* KAMUS */
    address last;
    /* ALGORITMA */
    if(IsEmpty(L1)){
        CpAlokList(L2, L3);
    } else {
        CpAlokList(L1, L3);
        last = First(*L3);
        while(Next(last) != Nil){
            last = Next(last);
        }

        Next(last) = First(L2);
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
	/* I.S. L1 dan L2 sembarang */
	/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
	/* Konkatenasi dua buah list : L1 dan L2    */
	/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
	/* dan L1 serta L2 menjadi list kosong.*/
	/* Tidak ada alokasi/dealokasi pada prosedur ini */
	/* KAMUS */
	address P;
	/* ALGORITMA */
    if(IsEmpty(*L1)) {
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    } else if(IsEmpty(*L2)) {
        First(*L3) = First(*L1);
        First(*L1) = Nil;
    } else if(IsEmpty(*L1) && IsEmpty(*L2)) {
		First(*L3) = Nil;
	} else {
        First(*L3) = First(*L1);
        P = First(*L3);
        while(Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);

        First(*L1) = Nil;
        First(*L2) = Nil;
	}
}


void PecahList (List *L1, List *L2, List L){
    /* I.S. L mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
    /* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
    /* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
    /* KAMUS */
    address P;
    int i;
    /* ALGORITMA */
    CpAlokList(L, L1);
    CpAlokList(L, L2);
    if((NbElmt(L) % 2)) {
        for (i = 0; i < ((NbElmt(L)) /2); i++) {
            DelLast(L1, &P);
        }
        
        for (i = 0; i < ((NbElmt(L) + 1) /2); i++) {
            DelFirst(L2, &P);
        }
    } else {
        for (i = 1; i < ((NbElmt(L)) /2); i++) {
            DelLast(L1, &P);
            DelFirst(L2, &P);
        }
    }
}



