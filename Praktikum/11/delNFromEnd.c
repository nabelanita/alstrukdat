/* NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 19 November 2020
    Topik praktikum	: List rekursif
    Deskripsi		: Implementasi fungsi delNFromEnd */

#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

void Delete(List *L, int *X, int *count, int N){
    /* KAMUS LOKAL */
    int Prec;
    List P;
    /* ALGORITMA */
	if (!IsEmpty(*L)) {
		P = Tail(*L);
		Prec = (*X);
		(*X)++;
		(*count)++;
		Delete(&P, X, count, N);

		if ((*count) - Prec == N + 1) { 
			SetNext((*L),Next(P));
			Dealokasi(P);
		}
	}
}


List delNFromEnd(List L, int n) {
    /* L terdefinisi, tidak mungkin kosong. */
    /* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
    lalu mengembalikan head dari list
    misal L = [1, 2, 3, 4, 5] dan n = 2
            L akan menjadi [1, 2, 3, 5] */

    /* KAMUS LOKAL */
    int sum = 0;
    int Q = 0;
	List P;
    /* ALGORITMA */
	Delete(&L, &Q, &sum, n);
    
	if (n == sum){
		P = Tail(L);
		Dealokasi(L);
		return P;
	} else {
		return L;
	}
    

}