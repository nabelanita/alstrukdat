/* Nama     : Nabelanita Utami
NIM         : 13519104 
Tanggal     : 17 September 2020
Topik       : Array Dinamis
Deskripsi   : Realisasi fungsi */

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#ifndef ARRAYDINPOS_H
#define ARRAYDINPOS_H

#include "boolean.h"
#include "arraydinpos.h"
#include <stdio.h>
#include <stdlib.h>


/*  Kamus Umum */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -1
/* Indeks tak terdefinisi*/
#define ValUndef -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef int ElType;  /* type elemen tabel */
typedef struct
{
  ElType *TI; /* memori tempat penyimpan elemen (container) */
  int MaxEl;  /* ukuran elemen */
} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl-1] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
                                             sehingga T.TI[i] != ValUndef */

/* ********** SELEKTOR ********** */
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    TI(*T) = malloc(maxel * sizeof(int));
    MaxEl(*T) = maxel;
    for (int i = IdxMin; i < MaxEl(*T); i++){
        Elmt(*T, i) = ValUndef;
    }
    
}

void Dealokasi(TabInt *T){
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */              
    free(T);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    /* KAMUS */
    int count = 0;
    IdxType i;
    /* ALGORITMA */
    for(i = IdxMin; i < MaxEl(T); i++){
        if(Elmt(T,i) != ValUndef){
            count += 1;
        }
    }

    return count;

}
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return MaxEl(T);

}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
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

IdxType GetLastIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */
    /* KAMUS */
    IdxType i =  MaxEl(T)-1;
    /* ALGORITMA */
    while(Elmt(T,i) == ValUndef){
        i--;
    }

    return i;

}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return(i >= IdxMin && i < MaxEl(T));  
}
boolean IsIdxEff(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    /* *** Test tabel penuh *** */
    return(NbElmt(T) == 0);


}
boolean IsFull(TabInt T){
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */ 
    return(NbElmt(T) == MaxEl(T));
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
    IdxType N, i;
    /* ALGORITMA */
    scanf("%d", &N);
    while(N > MaxEl(*T) && N < 0){
        scanf("%d", &N);
    }

    if(N > 0){
        for(i = 0; i <  N; i++){
            scanf("%d", &Elmt(*T, i));
        }
    } else {
        MakeEmpty(T, MaxEl(*T));
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
    /*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    /* KAMUS */
    TabInt total;
    IdxType i = GetFirstIdx(T1), j = GetFirstIdx(T2), k;
    /* ALGORITMA */
    MakeEmpty(&total, GetLastIdx(T1));
    for(k = IdxMin; k < MaxEl(total); k++){
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
    if(NbElmt(T1) == NbElmt(T2)){
        while(i < NbElmt(T1) && equal){
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
    /* Jika tidak ada, mengirimkan ValUndef */
    /* Menghasilkan indeks tak terdefinisi (ValUndef) jika tabel T kosong */
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
    
    for(i = 0; i < GetLastIdx(*Tout); i++){
        Elmt(*Tout, i) = Elmt(Tin, k);
        k++;
    }

}
ElType SumTab(TabInt T){
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
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
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
    /* ALGORITMA */
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
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */
    /* ALGORITMA */
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    /* Proses : Menambahkan max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi */
    /* F.S. Ukuran tabel bertambah sebanyak num */
    /* Proses : Menambahkan max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi */
    /* F.S. Ukuran tabel bertambah sebanyak num */
    TabInt temp;
    int i;
    /* ALGORITMA */
    CopyTab(*T, &temp);
    TI(*T) = realloc(TI(*T), MaxEl(*T) + num);
    MaxEl(*T) += num;
    for(i = 0; i < GetLastIdx(temp); i++){
        Elmt(*T, i) = Elmt(temp, i);
    }
    Dealokasi(&temp);
}

void ShrinkTab(TabInt *T, int num){
    /* Proses : Mengurangi max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
    /* F.S. Ukuran tabel berkurang sebanyak num. */
    /* KAMUS */
    TabInt temp;
    int i;
    /* ALGORITMA */
    CopyTab(*T, &temp);
    TI(*T) = realloc(TI(*T), MaxEl(*T) - num);
    MaxEl(*T) -= num;
    for(i = 0; i < GetLastIdx(temp); i++){
        Elmt(*T, i) = Elmt(temp, i);
    }
    Dealokasi(&temp);

}

void CompactTab(TabInt *T){
    /* Proses : Mengurangi max element sehingga Neff = MaxEl */
    /* I.S. Tabel tidak kosong */
    /* F.S. Ukuran MaxEl = Neff */
    ShrinkTab(T, MaxEl(*T) - NbElmt(*T));

}

#endif