/* NIM				: 13519104
Nama				: Nabelanita Utami
Tanggal				: 22 Oktober 2020
Topik praktikum		: Stack
Deskripsi praktikum	: Sebuah program dalam file bernama ekspresi.c yang 
membaca sebuah pita karakter yang hanya berisi bilangan positif dan 0 
serta operator ’+’, ’-’, ’*’, ’/’, dan ’^’ yang membentuk sebuah ekspresi 
aritmatika dalam notasi postfix dan mengevaluasi ekspresi yang terdapat pada pita 
karakter tersebut.*/

#include<stdio.h>
#include "stackt.h"
#include "mesintoken.h"
#include "math.h"

int IsOperator(char CC){
    if(CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^'){
        return 1;
    } else {
        return 0;
    }
}

int Hitung(int a, int b, char op){
    if(op == '+'){
        return a+b;
    } else if(op == '-'){
        return a-b;
    } else if(op == '*'){
        return a*b;
    } else if(op == '/'){
        return a/b;
    } else {
        return pow(a, b);
    }
}

int main(){
    Stack S;
    int op1, op2;
    int result = 0, count = 0, total;

    STARTTOKEN;
    CreateEmpty(&S);
    while(CC != MARK){
        IgnoreBlank;
        if(IsOperator(CC)){
            Pop(&S, &op2);
            Pop(&S, &op1);
            printf("%d %c %d\n", op1, op2, CC);
            result = Hitung(op1, op2, CC);
            printf("%d\n", result);
            Push(&S, result);
        } else {
            printf("%d\n", CToken.val);
            Push(&S, CToken.val);
        }
        ADVTOKEN;
        count++;
    }

    Pop(&S, &total);

    if(!count){
        printf("Ekspresi kosong.\n");
    }else{
        printf("Hasil=%d\n", total);
    }
    return 0;
}