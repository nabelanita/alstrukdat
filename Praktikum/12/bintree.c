/*  NIM			    : 13519104
    Nama		    : Nabelanita Utami
    Tanggal		    : 25 November 2020
    Topik praktikum	: Binary tree
    Deskripsi		: Implementasi file bintree.h */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    /* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
    /* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    /* ALGORITMA */
    BinTree P = AlokNode(Akar);
    if(P != Nil){
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    /* I.S. Akar, L, R terdefinisi. P Sembarang */
    /* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
            jika alokasi berhasil. P = Nil jika alokasi gagal. */
    /* ALGORITMA */
    BinTree X = Tree(Akar, L, R);
    *P = X;
}
BinTree BuildBalanceTree(int n) {
    /* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
    /* KAMUS */
	int X;
	infotype Q;
    BinTree left, right;
    /* ALGORITMA */
	if (n == 0) {
        return Nil;
	} else {
        scanf("%d", &X);
        left = BuildBalanceTree(n/2);
        right = BuildBalanceTree(n - n/2 - 1);
        return Tree(X, left, right);
	}
}

/* Manajemen Memory */
addrNode AlokNode(infotype X) {
    /* Mengirimkan addrNode hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
    maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    addrNode P = (addrNode) malloc(sizeof(Node));
    if (P != Nil) {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}
void DealokNode(addrNode P) {
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addrNode P */
    /* ALGORITMA */
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P) {
    /* Mengirimkan true jika P adalah pohon biner kosong */
    /* ALGORITMA */
    return P == Nil;
}
boolean IsTreeOneElmt(BinTree P) {
    /* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    /* ALGORITMA */
    if(IsTreeEmpty(P)){
        return false;
    } else {
        return((Left(P) == Nil) && (Right(P) == Nil));
    }
}
boolean IsUnerLeft(BinTree P) {
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (!IsTreeEmpty(Right(P))){
            return false;
        } else {
            return (!IsTreeEmpty(Left(P)));
        }
    }
}
boolean IsUnerRight(BinTree P) {
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (!IsTreeEmpty(Left(P))){
            return false;
        } else {
            return (!IsTreeEmpty(Right(P)));
        }
    }
}
boolean IsBiner(BinTree P) {
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    /* ALGORITMA */
    if (IsTreeEmpty(P)) { 
		return false;
	} else {
		return (!IsTreeEmpty(Right(P))) && (!IsTreeEmpty(Left(P)));
    }
}

/* *** Traversal *** */
void PrintPreorder(BinTree P) {
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (A()()) adalah pohon dengan 1 elemen dengan akar A
    (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
    /* ALGORITMA */
    printf("(");
	if (!IsTreeEmpty(P)) {
		printf("%d", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}
void PrintInorder(BinTree P) {
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (()A()) adalah pohon dengan 1 elemen dengan akar A
    ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
    /* ALGORITMA */
    printf("(");
	if (!IsTreeEmpty(P)) {
		PrintInorder(Left(P));
		printf("%d", Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}
void PrintPostorder(BinTree P) {
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
    Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
    Pohon kosong ditandai dengan ().
    Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh: 
    (()()A) adalah pohon dengan 1 elemen dengan akar A
    ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
    /* ALGORITMA */
    printf("(");
	if (!IsTreeEmpty(P)) {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d", Akar(P));
	}
	printf(")");
}
void function(BinTree P, int h, int n){
    printf("%d\n", Akar(P));
    if (!IsTreeEmpty(Left(P))) {
        for (int i = 0; i < h*n; i++) {
            printf(" ");
        }
        function(Left(P),h,n+1);
    }
    if (!IsTreeEmpty(Right(P))) {
        for (int i = 0; i < h*n; i++) {
            printf(" ");
        }
        function(Right(P),h,n+1);
    }
}
void PrintTree(BinTree P, int h) {
    /* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
    /* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
    /* Penulisan akar selalu pada baris baru (diakhiri newline) */
    /* Contoh, jika h = 2: 
    1) Pohon preorder: (A()()) akan ditulis sbb:
    A
    2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
    A
    B
    C
    3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
    A
    B
        D
    C
        E
    */
   /* ALGORITMA */
    function(P,h,1);
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X) {
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        if (Akar(P) == X) {
            return true;
        } else {
            return SearchTree(Left(P),X) || SearchTree(Right(P),X);
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P) {
    /* Mengirimkan banyaknya elemen (node) pohon biner P */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return 0;
    } else {
		return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
    }
}
int NbDaun(BinTree P) {
    /* Mengirimkan banyaknya daun (node) pohon biner P */
    /* Prekondisi: P tidak kosong */
    /* ALGORITMA */
    if (IsTreeOneElmt(P)) {
		return 1;
    } else if (IsTreeEmpty(P)) {
		return 0;
    } else {
		if(IsUnerLeft(P)){
            return NbDaun(Left(P));
        } else if (IsUnerRight(P)) {
            return NbDaun(Right(P));
        } else {
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
    }
}
boolean IsSkewLeft(BinTree P) {
    /* Mengirimkan true jika P adalah pohon condong kiri */
    /* Pohon kosong adalah pohon condong kiri */
    if (IsTreeEmpty(P)) {
		return true;
    } else if (IsTreeOneElmt(P)) {
        return true;
    } else if (!IsUnerLeft(P)) {
		return false;
    } else {
        return(IsSkewLeft(Left(P)));
    }
}
boolean IsSkewRight(BinTree P) {
    /* Mengirimkan true jika P adalah pohon condong kanan */
    /* Pohon kosong adalah pohon condong kanan */
    /* ALGORITMA */
   if (IsTreeEmpty(P)) {
		return true;
    } else if (IsTreeOneElmt(P)) {
        return true;
    } else if (!IsUnerRight(P)) {
		return false;
    } else {
        return(IsSkewRight(Right(P)));
    }
}
int Level(BinTree P, infotype X) {
    /* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
    Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
    /* KAMUS */
    int left, right;
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return -1;
    } else if (Akar(P) == X) {
        return 1;
    }
    left = Level(Left(P), X);
    right = Level(Right(P), X);
    
    if(right == -1 && left == -1) {
        return -1;
    } else if (right == -1) {
        return 1 + left;
    } else if(left == -1) {
        return 1 + right;
    } else {
        if (left < right) {
            return 1 + left;
        } else {
            return 1 + right;
        }
    }
}
int Tinggi(BinTree P) {
    /* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
    Mengirim "height" yaitu tinggi dari pohon */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return 0;
	} else {
        int a = Tinggi(Right(P)), b = Tinggi(Left(P));
        if (a > b) {
            return 1 + a;
        } else {
            return 1 + b;
        }
    }
}   

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X) {
    /* I.S. P boleh kosong */
    /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
    /* ALGORITMA */
    if (IsTreeEmpty(*P)) {
		*P = AlokNode(X);
    } else {
		AddDaunTerkiri(&Left(*P), X);
    }
}
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
    /* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
    /* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
            sebagai anak Kanan X (jika Kiri = false) */
    /*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
    /* ALGORITMA */
    if (Akar(*P) == X && IsTreeOneElmt(*P)) {
        if (Kiri) {
            Left(*P) = AlokNode(Y);
        } else {
            Right(*P) = AlokNode(Y);
        }
    } 

    if (SearchTree(Left(*P), X)) {
        AddDaun(&Left(*P), X, Y, Kiri);
    } else if (SearchTree(Right(*P), X)) {
        AddDaun(&Right(*P), X, Y, Kiri);
    }
}
void DelDaunTerkiri(BinTree *P, infotype *X) {
    /* I.S. P tidak kosong */
    /* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
            disimpan pada daun terkiri yang dihapus */
    /* KAMUS */
    addrNode N;
    /* ALGORIMA */
    if (!IsTreeEmpty(*P)) {
        if (IsTreeOneElmt(*P)) {
            *X = Akar(*P);
            addrNode N = *P;
            *P = Nil;
            DealokNode(N);
        } else {
            if (IsUnerRight(*P)) {
                DelDaunTerkiri(&Right(*P), X);
            } else {
                DelDaunTerkiri(&Left(*P), X);
            }
        }
    }
}
void DelDaun(BinTree *P, infotype X) {
    /* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
    /* F.S. Semua daun bernilai X dihapus dari P. */
    /* ALGORITMA */
    if (!IsTreeEmpty(*P)) {
		if (IsTreeOneElmt(*P)) {
			if (Akar(*P) == X) {
				*P = Nil;
            }
		} else {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
	} 
} 
List MakeListDaun(BinTree P) {
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
    jika semua alokasi list berhasil.
    Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
    Menghasilkan list kosong jika ada alokasi yang gagal. */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return Nil;
    } else if (IsTreeOneElmt(P)) {
		return Alokasi(Akar(P));
    } else {
		return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
    }
}
List MakeListPreorder(BinTree P) {
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
    dengan urutan preorder, jika semua alokasi berhasil.   
    Menghasilkan list kosong jika ada alokasi yang gagal. */
    /* KAMUS */
    address E;
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
		return Nil;
    } else {
        E = Alokasi(Akar(P));
        if (E != Nil) {
            Next(E) = MakeListPreorder(Left(P));
            return Concat(E, MakeListPreorder(Right(P)));
        } else {
            return Nil;
        }
    }
}

List MakeListLevel(BinTree P, int N) {
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
    yang levelnya=N, jika semua alokasi berhasil. 
    Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
    Menghasilkan list kosong jika ada alokasi yang gagal. */
    /*  KAMUS */
    List left, right;
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return Nil;
    } else if (N == 1) {
		return Alokasi(Akar(P));
    }
    left = MakeListLevel(Left(P), N - 1);
    right = MakeListLevel(Right(P), N - 1);

    if(left == Nil) {
        return right;
    } else if (right == Nil) {
        return left;
    } else {
        Concat(left, right);
    }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X) {
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    /* ALGORITMA */
    if (IsTreeEmpty(P)) {
        return false;
    } else {
        if (Akar(P) == X) {
            return true;
        } else {
            if (Akar(P) < X) {
                return BSearch(Right(P), X);
            } else {
                return BSearch(Left(P), X);
            }
        }
    }
}

void InsSearch(BinTree *P, infotype X) {
    /* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */
    /* ALGORITMA */
    if (IsTreeEmpty(*P)) {
        *P = AlokNode(X);
    } else {
        if (X >= Akar(*P)) {
            InsSearch(&Right(*P), X);
        } else {
            InsSearch(&Left(*P), X);
        }
    } 
}

void DelNode (BinTree *P) {
    /* ALGORITMA */
    if (Right(*P) == Nil) {
        DelNode(&Right(*P));
    } else {
        *P = Left(*P);
    }
}

void DelBtree(BinTree *P, infotype X) {
    /* I.S. Pohon P tidak  kosong */
    /* F.S. Nilai X yang dihapus pasti ada */
    /* Sebuah node dengan nilai X dihapus */
    /* KAMUS */

    /* ALGORITMA */
	if (X < Akar(*P)) {
		DelBtree(&Left(*P), X);
	} else if (X > Akar(*P)) {
		DelBtree(&Right(*P), X);
	} else if (X == Akar(*P)) {
		if (IsTreeOneElmt(*P)) {
			*P = Nil;
		} 
        if (IsUnerLeft(*P)) {
			*P = Left(*P);
		}
        if (IsUnerRight(*P)) {
			*P = Right(*P);
		} 
        if (IsBiner(*P)) {
            DelNode(&Left(*P));
		}
	}
}