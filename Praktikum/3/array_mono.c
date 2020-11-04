/* NIM      : 13519104
Nama        : NABELANITA UTAMI
Tanggal     : 10 SEPTEMBER 2020
Topik praktikum : ADT LIST
Deskripsi       : Mencari jenis array*/ 

#include <stdio.h>
#include "arraypos.c"
#include "boolean.h"

boolean IsSame(TabInt T){
    int i = GetFirstIdx(T), j = i + 11;
    while(Elmt(T,i) == Elmt(T, j) && j <= GetLastIdx(T)){
        j++;
    }
    return(j == GetLastIdx(T));
}

boolean IsGreater(TabInt T){
    int i = GetFirstIdx(T), j = i + 1;
    while(Elmt(T, i) <= Elmt(T, j) && j <= GetLastIdx(T)){
        i++;
        j++;
    }

    return(j == GetLastIdx(T));
}

boolean IsLess(TabInt T){
    int i = GetFirstIdx(T), j = i + 1;
    while(Elmt(T, i) >= Elmt(T, j) && j <= GetLastIdx(T)){
        i++;
        j++;
    }

    return(j == GetLastIdx(T));
}

int main(){
    TabInt T;
    BacaIsi(&T);

    if(IsSame(T)){
        printf("Array monotonik tidak mengecil\n");

    }else if(IsLess(T)){
        printf("Array monotonik tidak membesar\n");
    }else if(IsGreater(T)){
        printf("Array monotonik tidak mengecil\n");
    } else {
        printf("Array tidak monotonik\n");
    }

    return 0;
}