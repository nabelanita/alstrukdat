/* Nama     : Nabelanita Utami
NIM         : 13519104 
Tanggal     : 16 September 2020
Topik       : Array Dinamis
Deskripsi   : Implementasi fungsi arraydin.h */

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#ifndef ARRAYDIN_H
#define ARRAYDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"
#include "boolean.h"

/*  Kamus Umum */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef int ElType;  /* type elemen tabel */
typedef struct
{
  ElType *TI; /* memori tempat penyimpan elemen (container) */
  int Neff;   /* >=0, banyaknya elemen efektif */
  int MaxEl;  /* ukuran elemen */
} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    /* ALGORITMA */
    TI(*T) = malloc(maxel * sizeof(int));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
    
}

void Dealokasi(TabInt *T){
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    /* ALGORITMA */
    free(TI(*T));
    MaxEl(*T) = 0;
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* ALGORITMA */
    return Neff(T);
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /* KAMUS */
    /* ALGORITMA */
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */
    /* KAMUS */
    IdxType i = 0;
    /* ALGORITMA */
    while(!Elmt(T, i)){
        i++;
    }
    return i;
}
IdxType GetLastIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    /* ALGORITMA */
    return(GetFirstIdx(T) + Neff(T) - 1);

}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* ALGORITMA */
    return (i >= 0 && i < MaxElement(T));
}
boolean IsIdxEff(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    /* ALGORITMA */
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return(Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (Neff(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
        IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */
    /* KAMUS */
    int N;
    IdxType i;
    /* ALGORITMA */
    scanf("%d", &N);
    while(N < 0 || N > MaxElement(*T)){
        scanf("%d", &N);
    }

    if(N == 0){
        Neff(*T) = 0;
    } else {
        for(i = IdxMin; i < N; i++){
            scanf("%d", &Elmt(*T, i));
            Neff(*T) += 1;
        }
    }

}
void TulisIsiTab(TabInt T){
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
        printf("[]\n");
    } else {
        for(i = 0; i <= GetLastIdx(T); i++){
            if(i == GetFirstIdx(T)){
                printf("[%d,", Elmt(T, i));
            } else if(i == GetLastIdx(T)){
                printf("%d]\n", Elmt(T, i));
            } else {
                printf("%d,", Elmt(T, i));
            }
        }
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt total;
    IdxType i = GetFirstIdx(T1), j = GetFirstIdx(T2), k;
    /* ALGORITMA */
    MakeEmpty(&total, Neff(T1));
    for(k = 0; k < Neff(total); k++){
        Elmt(total, k) = Elmt(T1, i) + Elmt(T2, j);
        i++;
        j++;
    }

    return total;
    

}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    /* KAMUS */
    boolean equal = true;
    int i = GetFirstIdx(T1);
    /* ALGORITMA */
    if(Neff(T1)==Neff(T2)){
        while(i < Neff(T1) && equal){
            if(Elmt(T1, i) == Elmt(T2, i)){
                i++;
            } else {
                equal = false;
            }
        }
        return equal;
    } else {
        return false;
    }

}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS */
    IdxType i = IdxMin;
    boolean found = false;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return IdxUndef;
    } else {
        while(i <= GetLastIdx(T) && !found){
            if(Elmt(T, i) == X) {
                found = true;
            } else {
                i++;
            }
        }

        if(found){
            return i;
        } else {
            return IdxUndef;
        }
    }
    
}
boolean SearchB(TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */
    /* ALGORITMA */
    return(Search1(T, X) != IdxUndef);
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
            Min berisi nilai minimum T */
    /* KAMUS */
    IdxType i = GetFirstIdx(T);
    /* ALGORITMA */
    *Max = Elmt(T, i);
    *Max = Elmt(T, i);

    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T, i) >= *Max){
            *Max = Elmt(T, i);
        }

        if(Elmt(T,i) <= *Min) {
            *Min = Elmt(T, i);
        }
    }

}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
    /* Proses : Menyalin isi Tin ke Tout */
    /* KAMUS */
    IdxType i, k = GetFirstIdx(Tin);
    /* ALGORITMA */
    MakeEmpty(Tout, MaxEl(Tin));
    MaxEl(*Tout) = MaxEl(Tin);
    Neff(*Tout) = Neff(Tin);
    
    for(i = 0; i < Neff(*Tout); i++){
        Elmt(*Tout, i) = Elmt(Tin, k);
        k++;
    }
}
ElType SumTab(TabInt T){
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */
    /* KAMUS */
    IdxType i;
    ElType total = 0;
    /* ALGORITMA */
    if(IsEmpty(T)){
        return 0;
    } else {
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            total += Elmt(T,i);
        }
    }

    return total;
}
int CountX(TabInt T, ElType X){
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */
    /* KAMUS */
    int count = 0;
    IdxType i;
    /* ALGORITMA */
    if(IsEmpty(T) || !SearchB(T, X)){
        return 0;
    } else {
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            if(Elmt(T,i) == X){
                count++;
            }
        }
        return count;
    }
}
boolean IsAllGenap(TabInt T){
    /* Menghailkan true jika semua elemen T genap. T boleh kosong */
    /* KAMUS */
    boolean odd = true;
    IdxType i = GetFirstIdx(T);
    /* ALGORITMA */
    if(IsEmpty(T)){
        return odd;
    } else {
        while(i <= GetLastIdx(T) && odd){
            if(!((Elmt(T, i) % 2))){
                i++;
            } else {
                odd = false;
            }
        }
        return odd;
    }
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
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
void AddAsLastEl(TabInt *T, ElType X){
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */
    /* KAMUS */
    /* ALGORITMA */
    if(!IsFull(*T)){
        // Neff(*T) += 1;
        Elmt(*T, GetLastIdx(*T)+1) = X;
        Neff(*T) += 1;
    }

}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */
    /* KAMUS */
    /* ALGORITMA */
    if(Neff(*T) == 1){
        *X = Elmt(*T, 0);
        MakeEmpty(T, MaxEl(*T));
    } else {
        *X = Elmt(*T, GetLastIdx(*T));
        Neff(*T) -= 1;

    }

}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num) {
    /* Proses : Menambahkan max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi */
    /* F.S. Ukuran tabel bertambah sebanyak num */
    TI(*T) = realloc(TI(*T), MaxEl(*T) + num);
    MaxEl(*T) += num;

}

void ShrinkTab(TabInt *T, int num){
    /* Proses : Mengurangi max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
    /* F.S. Ukuran tabel berkurang sebanyak num. */
    /* ALGORITMA */
    TI(*T) = realloc(TI(*T), MaxEl(*T) - num);
    MaxEl(*T) -= num;
    


}

void CompactTab(TabInt *T){
    /* Proses : Mengurangi max element sehingga Neff = MaxEl */
    /* I.S. Tabel tidak kosong */
    /* F.S. Ukuran MaxEl = Neff */
   ShrinkTab(T, MaxEl(*T) - Neff(*T));
    
    
}

#endif
