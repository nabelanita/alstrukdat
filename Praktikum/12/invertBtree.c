/* NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 26 November 2020
    Topik praktikum	: Tree
    Deskripsi		: implementasi InvertBtree */

#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

void InvertBtree(BinTree *P) {
    /* I.S. Pohon P terdefinisi */
    /* F.S. Pohon P diflip secara vertikal */
    /*      Contoh:
            1
            2   5
            3 4 6
            Menjadi:
            1
            5   2
            6 4 3 */
    /* ALGORITMA */
    if (!IsTreeEmpty(*P)) {
        InvertBtree(&Left(*P));
        InvertBtree(&Right(*P));
        *P = Tree(Akar(*P), Right(*P), Left(*P));
    }
}
