/* NIM				: 13519104
Nama				: Nabelanita Utami
Tanggal				: 8 Oktober 2020
Topik praktikum		: Queue
Deskripsi praktikum	: Program yang mensimulasikan penerimaan packet. */

#include "prioqueuechar.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* KAMUS */
    int N, i, count;
    infotype Elmt, print;
    PrioQueueChar Q;
    /* ALGORITMA */
    scanf("%d", &N);
    count = 1;
    MakeEmpty(&Q, 100);
    for(i = 0; i < N; i++){
        scanf("%d %c", &Prio(Elmt), &Info(Elmt));
        Enqueue(&Q, Elmt);
        while(Prio(Elmt(Q, Head(Q))) == count){
            Dequeue(&Q, &print);
            printf("%d %c\n", i+1, Info(print));
            count++;
        }
    }
    return 0;
}