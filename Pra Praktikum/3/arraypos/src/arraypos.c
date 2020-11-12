/* Nama : Nabelanita Utami
NIM : 13519104 */


/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#ifndef ARRAYPOS_H
#define ARRAYPOS_H

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

/*  Kamus Umum */
#define IdxMax 99
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef -1
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Indeks ke-0 tidak digunakan */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T[i] untuk mengakses elemen ke-i */
/* Definisi : 
   Tabel kosong: semua elemen bernilai ValUndef
   Definisi elemen pertama : T[i] dengan i=1 */
  
/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
    /* I.S. T sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    /* ALGORITMA */
    for (int i = IdxMin; i <= IdxMax; i++){
        Elmt(*T, i) = ValUndef;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* *** Daya tampung container *** */
    /* KAMUS */
    int count = 0;
    IdxType i;
    /* ALGORITMA */
    for(i = IdxMin; i <= IdxMax; i++){
        if(Elmt(T,i) != ValUndef){
            count += 1;
        }
    }

    return count;
}
int MaxNbEl (TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /* *** Selektor INDEKS *** */
    /* ALGORITMA */
    return IdxMax+1;

}

IdxType GetFirstIdx (TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    /* KAMUS */
    IdxType i = IdxMin;
    /* ALGORITMA */
    while(Elmt(T, i) == ValUndef){
        i++;
    }

    return i;

}

IdxType GetLastIdx (TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    /* KAMUS */
    IdxType i =  GetFirstIdx(T);
    /* ALGORITMA */
    while(Elmt(T,i+1) != ValUndef){
        i++;
    }

    return i;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */
    return(i >= IdxMin && i <= IdxMax);  
}
boolean IsIdxEff (TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    /* ALGORITMA */
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    /* *** Test tabel penuh *** */
    /* ALGORITMA */
    return (NbElmt(T) == 0);
}
boolean IsFull (TabInt T){
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    /* ALGORITMA */
    return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    /* I.S. T sembarang */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
        IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */
    /* KAMUS */
    IdxType N, i;
    /* ALGORITMA */
    scanf("%d", &N);
    while(N > MaxNbEl(*T) && N < 0){
        scanf("%d", &N);
    }

    if(N > 0){
        for(i = 0; i <  N; i++){
            scanf("%d", &Elmt(*T, i));
        }
    } else {
        MakeEmpty(T);
    }
}
void TulisIsiTab (TabInt T){
    /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */
    /* KAMUS */
    IdxType i;
    /* ALGORITMA */
    if(IsEmpty(T)){
        printf("[]");
    } else {
        for(i = GetFirstIdx(T); i < GetLastIdx(T) + 1; i++){
            printf("[");
            if(i == GetLastIdx(T)){
                printf("%d]", Elmt(T, i));
            } else {
                printf("%d,", Elmt(T, i));
            }

        }

    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    /* KAMUS */
    IdxType i, k = 0;
    TabInt *total;
    MakeEmpty(total);
    /* ALGORITMA */
    if(NbElmt(T1) == NbElmt(T2) && !IsEmpty(T1) && !IsEmpty(T2)){
        for(i = GetFirstIdx(T1); i <= GetLastIdx(T1) + 1; i++){
            if(plus){
                Elmt(*total, k) = Elmt(T1, i) + Elmt(T2, i);
            } else {
                Elmt(*total, k) = Elmt(T1, i) - Elmt(T2, i);
            }
            k++;
        }
        return *total;
 
    } 

    if(IsEmpty(T1) && !IsEmpty(T2)){
        return T2;
    }

    if(IsEmpty(T2) && !IsEmpty(T1)){
        return T1;
    }

    if(IsEmpty(T1) && IsEmpty(T2)){
        return *total;
    }

}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
    /* KAMUS */
    IdxType i = GetFirstIdx(T1), k = GetFirstIdx(T2);
    int num = 0;
    /* ALGORITMA */
    if(NbElmt(T1) == NbElmt(T2)){
        while(i <= GetLastIdx(T1) && k <= GetLastIdx(T2) && Elmt(T1, i) == Elmt(T2, k)){
            num++;
            i++;
            k++;
        }

        return !(num < NbElmt(T1));
    } else {
        return false;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS */
    IdxType i;
    boolean found;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return IdxUndef;
    } else {
        i = GetFirstIdx(T);
        found = (Elmt(T,i) == X);
        while(i <= GetLastIdx(T) && !found){
            i++;
            found = (Elmt(T,i) == X);
        }

        if(found){
            return i;
        }else{
            return IdxUndef;
        }

    }


}
boolean SearchB (TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    /* ALGORITMA */
    return Search1(T, X) != IdxUndef;

}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min){
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
            Min berisi nilai minimum T */
    /* KAMUS */
    IdxType i;
    /* ALGORITMA */
    if(IsEmpty(T)){
        *Max = 0;
        *Min = 0;
    } else {
        *Max = Elmt(T, GetFirstIdx(T));
        *Min = Elmt(T, GetFirstIdx(T));

        for(i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++){
            if(Elmt(T,i) >= *Max){
                *Max = Elmt(T, i);
            }

            if(Elmt(T,i) <= *Min){
                *Min = Elmt(T, i);
            }
        }

    }
    
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T){
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */
    /* KAMUS */
    ElType total = 0;
    IdxType i;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return 0;
    } else {
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            total+= Elmt(T, i);
        }
        return total;
    }   

}

int CountX (TabInt T, ElType X){
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */
    /* KAMUS */
    int count = 0;
    IdxType i;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return 0;
    } else {
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            if(Elmt(T, i) == X){
                count++;
            }
        }
        return count;
    }

    

}
boolean IsAllGenap (TabInt T){
    /* Menghailkan true jika semua elemen T genap */
    /* KAMUS */
    IdxType i = GetFirstIdx(T);
    boolean genap = true;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return true;
    } else {
        while(i <=  GetLastIdx(T) && genap){
            genap = ((Elmt(T, i) % 2) == 0);
            i++;
        }

        return genap;
    }
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc){
    /* I.S. T boleh kosong */
    /* F.S. Jika asc = true, T terurut membesar */
    /*      Jika asc = false, T terurut mengecil */
    /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
    algoritma bebas */
    /* KAMUS */
    IdxType i, j;
    IdxType min = GetFirstIdx(*T), max = GetFirstIdx(*T);
    ElType temp;
    /* ALGORITMA */
    if(!IsEmpty(*T)){
        if(asc){
            for(i = GetFirstIdx(*T); i < GetLastIdx(*T); i++){
                min = i;
                for(j = i+1; j<= GetLastIdx(*T); j++){
                    if(Elmt(*T, j) < Elmt(*T, min)){
                        min = j;
                    }
                }

                temp = Elmt(*T, min);
                Elmt(*T,min) = Elmt(*T, i);
                Elmt(*T, i) = temp;

            }

        } else {
            for(i = GetFirstIdx(*T); i < GetLastIdx(*T); i++){
                max = i;
                for(j = i+1; j<= GetLastIdx(*T); j++){
                    if(Elmt(*T, j) > Elmt(*T, max)){
                        max = j;
                    }
                }

                temp = Elmt(*T, max);
                Elmt(*T,max) = Elmt(*T, i);
                Elmt(*T, i) = temp;

            }
        }

    }


}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    /* ********** MENGHAPUS ELEMEN ********** */
    /* KAMUS */
    IdxType i = GetLastIdx(*T);
    /* ALGORITMA */
    if(!IsEmpty(*T) && !(IsFull(*T))){
        Elmt(*T, i+1) = X;
    }

    if(IsEmpty(*T)){
        Elmt(*T, IdxMin) = X;
    }
    
}
void DelLastEl (TabInt * T, ElType * X){
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */
    /* KAMUS */
    IdxType i = GetLastIdx(*T);
    /* ALGORITMA */
    if(NbElmt(*T) == 1){
        MakeEmpty(T);
    } else {
        *X = Elmt(*T,i);
        Elmt(*T, i) = ValUndef;
        
    }

}

#endif