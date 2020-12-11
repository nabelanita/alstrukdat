/*  NIM     : Nabelanita Utami
    Nama    : 13519104
    Tanggal : 21 September 2020
    Topik praktikum : ADT Matriks
    Deskripsi       : Implementasi primitif ADT Matriks */

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "matriks.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    /* KAMUS */
    MATRIKS A;
    /* ALGORITMA */
    A.NBrsEff = NB;
    A.NKolEff = NK;
    *M = A;


}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    /* KAMUS */
    /* ALGORITMA */
    return(i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terbesar M */
    return NBrsEff(M) - 1;
}
indeks GetLastIdxKol (MATRIKS M){
    /* Mengirimkan indeks kolom terbesar M */
    return NKolEff(M) - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return(i >= BrsMin && i <= GetLastIdxBrs(M) && j >= KolMin && j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    /* Melakukan assignment MHsl  MIn */
    /* KAMUS */
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for(i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
        for(j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    /* I.S. IsIdxValid(NB,NK) */ 
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 
    */
   /* KAMUS */
   indeks i, j;
   /* ALGORITMA */
    MakeMATRIKS(NB, NK, M);
    for(i = BrsMin; i < NB; i++){
        for(j = KolMin; j < NK; j++){
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}
void TulisMATRIKS (MATRIKS M){
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
    dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
   /* KAMUS */
   indeks i, j;
   /* ALGORITMA */
   for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
       for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
           if(j == GetLastIdxKol(M)){
               if(i == GetLastIdxBrs(M)){
                   printf("%d", Elmt(M, i, j));
               } else {
                   printf("%d\n", Elmt(M, i, j));
               }
           }else{
               printf("%d ", Elmt(M, i, j));
           }
       }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : M1  berukuran sama dengan M2 */
    /* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
    /* KAMUS */
    MATRIKS total;
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &total);
    for(i = GetFirstIdxBrs(total); i <= GetLastIdxBrs(total); i++){
        for(j = GetFirstIdxKol(total); j <= GetLastIdxKol(total); j++){
            Elmt(total, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }

    return total;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : M berukuran sama dengan M */
    /* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
    /* KAMUS */
    MATRIKS diff;
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &diff);
    for(i = GetFirstIdxBrs(diff); i <= GetLastIdxBrs(diff); i++){
        for(j = GetFirstIdxKol(diff); j <= GetLastIdxKol(diff); j++){
            Elmt(diff, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }

    return diff;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
    /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    /* KAMUS */
    MATRIKS result;
    indeks i, j, k;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &result);
    for(i = GetFirstIdxBrs(result); i <= GetLastIdxBrs(result); i++){
        for(j = GetFirstIdxKol(result); j <= GetLastIdxKol(result); j++){
            Elmt(result, i, j) = 0;
            for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
                Elmt(result, i, j) += (Elmt(M1, i, k) * Elmt(M2, k, j));
            }
        }
    }
    return result;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
    /* Mengirim hasil perkalian setiap elemen M dengan X */
    /* KAMUS */
    MATRIKS result;
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &result);
    CopyMATRIKS(M, &result);
    for(i = GetFirstIdxBrs(result); i <= GetLastIdxBrs(result); i++){
        for(j = GetFirstIdxKol(result); j <= GetLastIdxKol(result); j++){
            Elmt(result, i, j) *= X;
        }
    }
    return result;  
}
void PKaliKons (MATRIKS * M, ElType K){
    /* I.S. M terdefinisi, K terdefinisi */
    /* F.S. Mengalikan setiap elemen M dengan K */
    /* KAMUS */
    indeks i, j;
    /* ALGORITMA */
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) *= K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    /* KAMUS */
    boolean equal = true;
    indeks i, j;
    /* ALGORITMA */
    if(NBrsEff(M1)*NKolEff(M1) == NBrsEff(M2)*NKolEff(M2)){
        i = GetFirstIdxBrs(M1);
        j = GetFirstIdxKol(M1);
        while(equal && i <= GetLastIdxBrs(M1)){
            while(equal && j <= GetLastIdxKol(M1)){
                if(Elmt(M1, i, j) == Elmt(M2, i, j)){
                    j++;
                } else {
                    equal = false;
                }
            }
            if(equal){
                i++;
                j = GetFirstIdxKol(M1);
            }
        }

        return equal;
    } else {
        return false;
    }

}
boolean NEQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 tidak sama dengan M2 */
    /* ALGORITMA */
    return !EQ(M1, M2);
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    /* ALGORTIMA */
    return((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    /* Mengirimkan banyaknya elemen M */
    return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return(NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
    dan untuk setiap elemen M, M(i,j)=M(j,i) */
    /* KAMUS */
    boolean equal = true;
    indeks i, j;
    /* ALGORITMA */
    if(IsBujurSangkar(M)){
        i = GetFirstIdxBrs(M);
        j = GetFirstIdxKol(M);
        while(equal && i <= GetLastIdxBrs(M)){
            while(equal && j <= GetLastIdxKol(M)){
                if(Elmt(M, i, j) == Elmt(M, j, i)){
                    j++;
                } else {
                    equal = false;
                }
            }
            if(equal){
                i++;
                j = GetFirstIdxKol(M);
            }
        }
        return equal;
    }else{
        return false;
    }

}
boolean IsSatuan (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
    setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
    /* KAMUS */
    indeks i, j;
    boolean satuan = true;
    /* ALGORITMA */
    if(IsBujurSangkar(M)){
        i = GetFirstIdxBrs(M);
        j = GetFirstIdxKol(M);
        while(satuan && i <= GetLastIdxBrs(M)){
            while(satuan && j <= GetLastIdxKol(M)){
                if(i == j){
                    if(Elmt(M, i, j) == 1){
                        j++;
                    } else {
                        satuan = false;
                    }
                } else {
                    if(Elmt(M, i, j) == 0) {
                        j++;
                    } else {
                        satuan = false;
                    }
                }
            }
            if(satuan){
                i++;
                j = GetFirstIdxKol(M);
            }
        }
        return satuan;
    } else {
        return false;
    }
}
boolean IsSparse (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
    /* KAMUS */
    int count = 0;
    indeks i, j;
    /* ALGORITMA */
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if(Elmt(M, i, j) != 0){
                count++;
            }
        }
    }

    return(count <= (0.05 * NBElmt(M)));

}
MATRIKS Inverse1 (MATRIKS M){
    /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* KAMUS */
    MATRIKS result;
    indeks i, j;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &result);
    CopyMATRIKS(M, &result);
    for(i = GetFirstIdxBrs(result); i <= GetLastIdxBrs(result); i++){
        for(j = GetFirstIdxKol(result); j <= GetLastIdxKol(result); j++){
            Elmt(result, i, j) *= -1;
        }
    }
    return result;
}
float Determinan (MATRIKS M){
    /* Prekondisi: IsBujurSangkar(M) */
    /* Menghitung nilai determinan M */
    /* KAMUS */
    float det;
    int sign;
    indeks i, p, q, a, b;
    MATRIKS cof;
    /* ALGORITMA */
    if(NBElmt(M) == 1){
        return Elmt(M, 0, 0);
    }
    
    if(NBElmt(M) == 4){
        return (Elmt(M, 0, 0)*Elmt(M, 1, 1) - Elmt(M, 0, 1)*Elmt(M, 1, 0));
    } 

    det = 0;
    MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) -1, &cof);
    sign = 1;
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){

        // Cari kofaktor tiap baris
        a = GetFirstIdxBrs(cof);
        for(p = GetFirstIdxBrs(M); p <= GetLastIdxBrs(M); p++){
            b = GetFirstIdxKol(cof);
            if(p != i){
                for(q = GetFirstIdxKol(M) + 1; q <= GetLastIdxKol(M); q++){
                    Elmt(cof, a, b) = Elmt(M, p, q);
                    b++;
                }
                a++;
            }
        }

        // Cari determinan
        det = det + (sign * Elmt(M, i, 0) * Determinan(cof));
        sign = -sign;


    }
    
    return det;
    
}
void PInverse1 (MATRIKS * M){
    /* I.S. M terdefinisi */
    /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* KAMUS */
    indeks i, j;
    /* ALGORITMA */
    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(*M, i, j) *= -1;
        }
    }
}
void Transpose (MATRIKS * M){
    /* I.S. M terdefinisi dan IsBujursangkar(M) */
    /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    /* KAMUS */
    indeks i, j;
    MATRIKS temp;
    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(*M), NKolEff(*M), &temp);
    CopyMATRIKS(*M, &temp);
    for(i = GetFirstIdxBrs(temp); i <= GetLastIdxBrs(temp); i++){
        for(j = GetFirstIdxKol(temp); j <= GetLastIdxKol(temp); j++){
            Elmt(temp, i, j) = Elmt(*M, j, i);
        }
    }
    *M = temp;
}

#endif