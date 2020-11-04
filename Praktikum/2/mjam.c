/*  NIM		: 13519104
    Nama	: Nabelanita Utami
    Tanggal	: 3 September 2020
    Topik praktikum	:
    Deskripsi		:
 */

#include<stdio.h>
#include "jam.h"


int main(){
    /* membaca beberapa pasangan JAM yang merepresentasikan waktu mulai dan waktu selesai pembicaraan 
    telepon di suatu perusahaan penyedia layanan telepon, misalnya <J1, J2>. Selanjutnya untuk masing-masing pasangan, 
    dituliskan durasi pembicaraan telepon dalam detik.*/
    /* KAMUS */
    int i,a, Jaw, Jakh;
    int hour, minute, second;
    JAM J1, J2;
    /* ALGORITMA */
    scanf("%d", &a);
    Jaw = 0;
    Jakh = 0;
    for(i = 0; i < a; i ++) {
        scanf("%d %d %d", &hour, &minute, &second);
        while (!IsJAMValid(hour, minute, second)) {
            printf("Jam tidak valid\n");
            scanf("%d %d %d\n", &hour, &minute, &second);
        }
        J1 = MakeJAM(hour, minute, second);
        scanf("%d %d %d", &hour, &minute, &second);
        while (!IsJAMValid(hour, minute, second)) {
            printf("Jam tidak valid\n");
            scanf("%d %d %d\n", &hour, &minute, &second);
        }
        J2 = MakeJAM(hour, minute, second);



        if(Jaw == 0 && Jakh == 0){
            if(JAMToDetik(J1) >= JAMToDetik(J2)){
                Jaw = JAMToDetik(J2);
                Jakh = JAMToDetik(J1);
            } else {
                Jaw = JAMToDetik(J1);
                Jakh = JAMToDetik(J2);
            }
        } else {
            if(JAMToDetik(J1) >= JAMToDetik(J2)) {
                if(JAMToDetik(J1) >= Jakh) {
                    Jakh = JAMToDetik(J1);
                }

                if(JAMToDetik(J2) <= Jaw) {
                    Jaw = JAMToDetik(J2);
                }
            } else {
                if(JAMToDetik(J2) >= Jakh) {
                    Jakh = JAMToDetik(J2);
                }

                if(JAMToDetik(J1) <= Jaw) {
                    Jaw = JAMToDetik(J1);
                }
                
            }
        }
    }

    printf("0\n");
    J1 = DetikToJAM(Jaw);
    J2 = DetikToJAM(Jakh);

    printf("%d:%d:%d\n", Hour(J1), Minute(J1), Second(J1));
    printf("%d:%d:%d\n", Hour(J2), Minute(J2), Second(J2));

    return 0;
}