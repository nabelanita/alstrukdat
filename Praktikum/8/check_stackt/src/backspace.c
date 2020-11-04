/* NIM				: 13519104
Nama				: Nabelanita Utami
Tanggal				: 22 Oktober 2020
Topik praktikum		: Stack
Deskripsi praktikum	: Diberikan dua buah sequence A dan B yang merepresentasikan urutan 
pengetikan karakter pada layar. Sequence terdiri dari angka 1-9 dan angka 0 yang merepresentasikan 
backspace (penghapusan satu karakter). Tentukan apakah A dan B menghasilkan sequence yang sama 
jika diketikkan ke layar..*/
#include <stdio.h>
#include "stackt.h"

int main(){
    int a, b, i, n, X;
    int s1, s2;
    Stack P, Q;
    int same = 1;

    CreateEmpty(&P);
    CreateEmpty(&Q);


    scanf("%d %d", &a, &b);
    for(i = 0; i < a; i++){
        scanf("%d", &n);
        if(n != 0){
            Push(&P, n);
        } else {
            if(!IsEmpty(P)){
                Pop(&P, &X);
            }
        }
    }

    for(i = 0; i < b; i++){
        scanf("%d", &n);
        if(n != 0){
            Push(&Q, n);
        } else {
            if(!IsEmpty(P)){
                Pop(&Q, &X);
            }
        }
    }
    if(IsEmpty(P) && IsEmpty(Q)){
        printf("Sama\n");
    } else if(IsEmpty(P) || IsEmpty(Q)){
        printf("Tidak sama\n");
    } else {
        while(same && !IsEmpty(P) && !IsEmpty(Q)){
            Pop(&P, &s1);
            Pop(&Q, &s2);
            if(s1 != s2){
                same = 0;
            }
        }

        if(same){
            printf("Sama\n");
        } else {
            printf("Tidak sama\n");
        }
    }

    return 0;
}