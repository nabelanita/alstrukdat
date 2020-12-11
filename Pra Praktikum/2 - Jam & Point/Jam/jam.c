/* NAMA : NABELANITA UTAMI
NIM     : 13519104 */

#ifndef JAM_H
#define JAM_H

#include<stdio.h>
#include "boolean.h"
#include "jam.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* OPERASI ISJAMVALID */
boolean IsJAMValid (int H, int M, int S){
    /* Memeriksa apakah jam valid. Akan mengembalikan true jika valid dan false jika tidak */
    /* ALGORITMA */
    if(H >= 0 && H <=23 && M >= 0 && M <= 59 && S >= 0 && S <= 59) {
        return true;
    } else {
        return false;
    }
}

/* OPERASI MAKEJAM */
JAM MakeJAM (int HH, int MM, int SS){
    /* Membentuk type JAM dari nilai jam, menit dan detik yang diberikan */
    /* KAMUS */
    JAM J;
    /* ALGORITMA */
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;

    return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
/* OPERASI BACA JAM */
void BacaJAM (JAM * J){
    /* I.S. : J tidak terdefinisi */
    /* F.S. : J terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
    /* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
    dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
    diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
    60 3 4
    Jam tidak valid
    1 3 4
    --> akan terbentuk JAM <1,3,4> */
    /* KAMUS */
    int hour, minute, second;
    /* ALGORITMA */
    scanf("%f", &hour);
    scanf("%f", &minute);
    scanf("%f", &second);

    if IsJAMValid(hour, minute, second){
        *J = MakeJAM(hour, minute, second);
    } else {
        printf("Jam tidak valid");
    }

}

/* OPERASI TULISJAM */
void TulisJAM (JAM J){
    //* I.S. : J sembarang */
    /* F.S. :   Nilai J ditulis dg format HH:MM:SS */
    /* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
    tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
    Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
    /* ALGORITMA */
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
/* OPERASI JAMTODETIK */
long JAMToDetik (JAM J){
    /* Mengembalikan hasil konversi jam ke detik */
    /* KAMUS */
    long total;
    /* ALGORITMA */
    total = Hour(J) * 3600 + Minute(J) + 60 + Second(J);

    return total;
}

/* OPERASI DETIKTOJAM */
JAM DetikToJAM (long N){
    /* Mengembalikan type JAM dari detik yang diberikan */
    /* KAMUS */
    JAM J;
    int a;
    /* ALGORITMA */
    N = N % 86400
    Hour(J) = N / 3600;
    a = N % 3600;
    Minute(J) = a / 60;
    Second(J) = a % 60;
}   

/* OPERASI JEQ */
boolean JEQ (JAM J1, JAM J2){
    /* Mengembalikan nilai true jika J1 == J2, false jika tidak */
    if (Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2)) {
        return true; 
    } else {
        return false;
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
/* OPERASI JNEQ */
boolean JNEQ (JAM J1, JAM J2){
    /* Mengembalikan nilai true jika P1 != P2, false jika sebaliknya */
    return !(JEQ(J1, J2));
}

/* OPERASI JLT */
boolean JLT (JAM J1, JAM J2){
    /* Mengembalikan nilai true jika J1 < J2, false jika sebaliknya */
    if(Hour(J1) < Hour(J2)){
        return true;
    } else if(Hour(J1) == Hour(J2)) {
        if(Minute(J1) < Minute(J2)){
            return true;
        } else if(Minute(J1) == Minute(J2)){
            if(Second(J1) < Second(J2)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/* OPERASI JGT */
boolean JGT(JAM J1, JAM J2){
    /* Mengembalikan nilai true jika J1 > J2, false jika sebaliknya */
    return !(JLT(J1, J2));
}

/* OPERASI NEXTDETIK */
JAM NextDetik (JAM J){
    /* Mengirim hasil 1 detik setelah J */
    /* KAMUS */
    int H, M, S;
    /* ALGORITMA */
    H = Hour(J);
    M = Minute(J);
    S = Second(J);
    if(S == 59){
        if(M == 59){
            if(H == 59){
                H = 0;
                M = 0;
                S = 0;
            }
        } else {
            H += 1;
            M = 0;
            S = 0;
        }
    } else {
        S += 1;
    }

    return MakeJAM(H, M, S);
}

/* OPERASI NEXTNDETIK */
JAM NextNDetik (JAM J, int N){
    /* Mengirim hasil N detik setelah J */
    /* KAMUS */
    int H, M, S;
    /* ALGORITMA */
    H = Hour(J);
    M = Minute(J);
    S = Second(J);
    if(S + N > 59){
        if(M == 59){
            if(H == 23) {
                H = 0;
                M = 0;
                S = S + N - 60;
            }
        } else {
            M += 1;
            S = S + N - 60;
        }
    } else {
        S += N;
    }

    return MakeJAM(H, M, S);
    
}

/* OPERASI PREVDETIK */
JAM PrevDetik (JAM J){
    /* Mengirim hasil 1 detik sebelum J */
    /* KAMUS */
    int H, M, S;
    /* ALGORTIMA */
    if(S == 0) {
        if(M == 0){
            if(H == 0){
                H = 23;
                M = 59;
                S = 59;
            } else {
                H -= 1;
                M = 59;
                S = 59;
            }
        } else {
            M -= 1;
            S = 59
        }
    } else {
        S -= 1;
    }

    return MakeJAM(H, M, S);
}

/* OPERASI PREVNDETIK */
JAM PrevNDetik (JAM J, int N){
    /* Mengirim hasil N detik sebelum J */
    /* KAMUS */
    int H, M, S;
    /* ALGORITMA */
    H = Hour(J);
    M = Minute(J);
    S = Second(J);
    if(S - N < 0) {
        if(M - 1 < 0){
            if(H - 1 < 0){
                H = 23;
                M = 59;
                S = 60 - (S - N);
            } else {
                H -= 1;
                M = 59;
                S = 60 - (S - N);
            }
        } else {
            M -= 1;
            S = 60 - (S - N)
        }
    } else {
        S -= N;
    }

    return MakeJAM(H, M, S);
}

/* *** Kelompok Operator Aritmetika *** */
/* OPERASI DURASI */
long Durasi (JAM JAw, JAM JAkh){
    /* Mengirim durasi JAkh - JAw dalam detik (total durasi) */
    /* KAMUS */
    long s1, s2, diff;
    /* ALGORITMA */
    s1 = Hour(JAw) * 3600 + Minute(JAw) * 60 + Minute(JAw);
    s2 = Hour(JAkh) * 3600 + Minute(JAkh) * 60 + Minute(JAkh);
    
    if(s1 > s2) {
        diff = 86400 + s2 - s1
    } else {
        diff = s2 - s1;
    }

    return diff;

}

#endif