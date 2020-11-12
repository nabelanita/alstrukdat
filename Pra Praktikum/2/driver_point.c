/* NAMA		: NABELANITA UTAMI
NIM			: 13519104
TANGGAL 	: 2 SEPTEMBER 2020 */

#include<stdio.h>
#include "point.c"
#include "point.h"
#include "boolean.h"

int main(void) {
	/* KAMUS */
	POINT P1, P2;
	int deltaX, deltaY;
	/*	ALGORITMA */
	printf("Masukkan point 1 (x, y dipisahkan dengan spasi): \n");
	BacaPOINT(*P1);
	printf("Point yang Anda masukkan adalah: \n");
	TulisPOINT(P1);

	printf("Masukkan point 2 (x, y dipisahkan dengan spasi): \n");
	BacaPOINT(*P2);
	printf("Point yang Anda masukkan adalah: \n");
	TulisPOINT(P2);

	if(EQ(P1,P2)) {
		printf("Point 1 sama dengan Point 2\n");
	} else {
		printf("Point 1 tidak sama dengan Point 2\n");
	}

	if(IsOrigin(P1)) {
		printf("Point 1 merupakan titik origin");
	}

	if(IsOrigin(P1)) {
		printf("Point 2 merupakan titik origin\n");
	}

	if(IsOnSbX(P1)) {
		printf("Point 1 berada di atas sumbu x\n");
	}

	if(IsOnSbY(P1)) {
		printf("Point 1 berada di atas sumbu y\n");
	}

	if(IsOnSbX(P2)) {
		printf("Point 2 berada di atas sumbu x\n");
	}

	if(IsOnSbY(P2)) {
		printf("Point 2 berada di atas sumbu y\n");
	}

	printf("Point 1 berada di kuadran %d\n", Kuadran(P1) );
	printf("Point 2 berada di kuadran %d\n", Kuadran(P2) );

	printf("Point yang nilai absisnya lebih 1 dari point 1 adalah: \n");
	TulisPOINT(NextX(P1));
	printf("Point yang nilai ordinatnya lebih 1 dari point 1 adalah: \n");
	TulisPOINT(NextY(P1));
	printf("Point yang nilai absisnya lebih 1 dari point 2 adalah: \n");
	TulisPOINT(NextX(P2));
	printf("Point yang nilai ordinatnya lebih 1 dari point 2 adalah: \n");
	TulisPOINT(NextY(P2));

	printf("Masukkan nilai x: \n")
	scanf("%f", &deltaX);
	printf("Masukkan nilai y: \n")
	scanf("%f", &deltaY);

	printf("Hasil point 1 ditambah x = %f dan y = %f adalah: \n", x, y);
	TulisPOINT(PlusDelta(P1, x, y));
	printf("Hasil point 2 ditambah x = %f dan y = %f adalah: \n ", x, y);
	TulisPOINT(PlusDelta(P2, x, y));

	printf("Hasil mirror point 1 terhadap sumbu x adalah:\n")
	TulisPOINT(Mirror(P1), true);
	printf("Hasil mirror point 2 terhadap sumbu y adalah:\n")
	TulisPOINT(Mirror(P2), false);

	printf("Jarak point 1 ke origin adalah sejauh %f\n", Jarak0(P1));
	printf("Jarak point 1 ke origin adalah sejauh %f\n", Jarak0(P2));

	printf("Panjang garis P1-P2 adalah %f\n", Panjang(P1, P2) );

	return 0;
}