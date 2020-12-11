/* NAMA	: NABELANITA UTAMI
NIM	: 13519104 
TANGGAL	: 2 SEPTEMBER 2020*/

#include <stdio.h>
#include "jam.c"
#include "jam.h"
#include "boolean.h"

int main(void) {
	/* KAMUS */
	JAM J1, J2;
	/* ALGORITMA */
	printf("Masukkan jam pertama:\n");
	BacaJAM(*J1);
	printf("Jam yang Anda masukkan adalah:\n");
	TulisJAM(J1);
	printf("Masukkan jam kedua:\n");
	BacaJAM(*J2);
	printf("Jam yang Anda masukkan adalah:\n");
	TulisJAM(J2);

	if(JEQ(J1, J2)) {
		printf("Jam pertama sama dengan jam kedua\n");
	} else {
		printf("Jam pertama tidak sama dengan jam kedua\n");
	}

	if(JLT(J1,J2)){
		printf("Jam pertama lebih awal dari jam kedua\n");
		printf("Durasi dari jam pertama ke jam kedua adalah %ld\n", Durasi(J1, J2) );
	} else {
		printf("Jam kedua lebih awal dari jam pertama\n");
		printf("Durasi dari jam kedua ke jam pertama adalah %ld\n", Durasi(J2, J1) );
	}

	



	return 0;
}