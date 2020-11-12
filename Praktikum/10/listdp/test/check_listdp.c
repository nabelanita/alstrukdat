/* NIM			        : 13519104
    Nama		        : Nabelanita Utami
    Tanggal		      : 11 November 2020
    Topik praktikum	: ADT List double pointer
    Deskripsi		    : File check_listdp.c */

#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listdp.h"

void CreateEmptyTest(List *L);
address AlokasiTest(infotype X);
void InsVLastTest(List *L, infotype X);
void PrintForwardTest(List L);
void IsiListTest(List *L);
int NbElmtTest(List L);

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
START_TEST(CreateEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_ptr_eq(First(L), Nil);
} END_TEST

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
START_TEST(IsEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_int_eq(1, IsEmpty(L));
  InsVLastTest(&L, 100);
  ck_assert_int_eq(0, IsEmpty(L));
} END_TEST

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
} END_TEST

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = AlokasiTest(X);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
} END_TEST

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
START_TEST(Search_T1) {
  List L;
  infotype search = 2;
  IsiListTest(&L);
  address P = Search(L, search);
  ck_assert_ptr_ne(P, Nil);
} END_TEST

START_TEST(Search_T2) {
  List L;
  infotype search = 6;
  IsiListTest(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
} END_TEST

START_TEST(Search_T3) {
  List L;
  infotype search = 1;
  CreateEmptyTest(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
} END_TEST

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
START_TEST(InsVFirst_T1) {
  List L;
  infotype X = 1;
  CreateEmptyTest(&L);
  InsVFirst(&L, X);
  ck_assert_int_eq(NbElmtTest(L), 1);
  ck_assert_int_eq(Info(First(L)), 1);
} END_TEST

START_TEST(InsVFirst_T2) {
  List L;
  infotype X = 0;

  IsiListTest(&L);
  InsVFirst(&L, X);

  ck_assert_int_eq(NbElmtTest(L), 4);

  int i = 0;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
START_TEST(InsVLast_T1) {
  List L;
  infotype X = 1;
  CreateEmptyTest(&L);
  InsVLast(&L, X);
  ck_assert_int_eq(NbElmtTest(L), 1);
  ck_assert_int_eq(Info(First(L)), 1);
} END_TEST

START_TEST(InsVLast_T2) {
  List L;
  infotype X = 4;

  IsiListTest(&L);
  InsVLast(&L, X);

  ck_assert_int_eq(NbElmtTest(L), 4);

  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
START_TEST(DelVFirst_T1) {
  List L;
  infotype X;

  IsiListTest(&L);
  DelVFirst(&L, &X);

  ck_assert_int_eq(X, 1);
  ck_assert_int_eq(NbElmtTest(L), 2);

  int i = 2;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
START_TEST(DelVLast_T1) {
  List L;
  infotype X;

  IsiListTest(&L);
  DelVLast(&L, &X);

  ck_assert_int_eq(X, 3);
  ck_assert_int_eq(NbElmtTest(L), 2);

  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
START_TEST(InsertFirst_T1) {
  List L;
  CreateEmptyTest(&L);

  address P3 = AlokasiTest(3);
  InsertFirst(&L, P3);
  address P2 = AlokasiTest(2);
  InsertFirst(&L, P2);
  address P1 = AlokasiTest(1);
  InsertFirst(&L, P1);
  
  ck_assert_int_eq(NbElmtTest(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
START_TEST(InsertAfter_T1) {
  List L;
  CreateEmptyTest(&L);

  address P3 = AlokasiTest(3);
  InsertFirst(&L, P3);
  address P1 = AlokasiTest(1);
  InsertFirst(&L, P1);

  address P2 = AlokasiTest(2);
  InsertAfter(&L, P2, P1);
  
  ck_assert_int_eq(NbElmtTest(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
START_TEST(InsertLast_T1) {
  List L;
  CreateEmptyTest(&L);

  address P1 = AlokasiTest(1);
  InsertLast(&L, P1);
  address P2 = AlokasiTest(2);
  InsertLast(&L, P2);
  address P3 = AlokasiTest(3);
  InsertLast(&L, P3);
  
  ck_assert_int_eq(NbElmtTest(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
START_TEST(DelFirst_T1) {
  List L;
  IsiListTest(&L);

  address PFirst;
  DelFirst(&L, &PFirst);
  
  ck_assert_int_eq(NbElmtTest(L), 2);
  ck_assert_int_eq(Info(PFirst), 1);

  int i = 2;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(DelFirst_T2) {
  List L;

  CreateEmptyTest(&L);
  InsVLastTest(&L, 123);

  address PFirst;
  DelFirst(&L, &PFirst);
  
  ck_assert_int_eq(NbElmtTest(L), 0);
  ck_assert_int_eq(Info(PFirst), 123);
} END_TEST

START_TEST(DelFirst_T3) {
  List L;
  IsiListTest(&L);

  address PFirst1;
  DelFirst(&L, &PFirst1);

  ck_assert_int_eq(NbElmtTest(L), 2);
  ck_assert_int_eq(Info(PFirst1), 1);

  address PFirst2;
  DelFirst(&L, &PFirst2);

  ck_assert_int_eq(NbElmtTest(L), 1);
  ck_assert_int_eq(Info(PFirst2), 2);

  address PFirst3;
  DelFirst(&L, &PFirst3);

  ck_assert_int_eq(NbElmtTest(L), 0);
  ck_assert_int_eq(Info(PFirst3), 3);
} END_TEST


/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
START_TEST(DelP_T1) {
  List L;
  IsiListTest(&L);
  DelP(&L, 3);
  
  ck_assert_int_eq(NbElmtTest(L), 2);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(DelP_T2) {
  List L;
  IsiListTest(&L);
  DelP(&L, 4);
  
  ck_assert_int_eq(NbElmtTest(L), 3);
  int i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(DelP_T3) {
  List L;
  CreateEmptyTest(&L);
  DelP(&L, 1);
  
  ck_assert_int_eq(NbElmtTest(L), 0);
} END_TEST


/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
START_TEST(DelLast_T1) {
  List L;
  IsiListTest(&L);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 3);
  ck_assert_ptr_eq(Next(P), Nil);
  ck_assert_int_eq(NbElmtTest(L), 2);

  int i = 1;
  P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(DelLast_T2) {
  List L;
  CreateEmptyTest(&L);
  InsVLastTest(&L, 1);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 1);
  ck_assert_ptr_eq(Next(P), Nil);
  ck_assert_int_eq(NbElmtTest(L), 0);
} END_TEST

/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
START_TEST(DelAfter_T1) {
  List L;
  address Prec, Pdel;
  IsiListTest(&L);
  Prec = First(L);
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmtTest(L), 2);
  ck_assert_int_eq(Info(Prec), 1);
  ck_assert_int_eq(Info(Pdel), 2);
} END_TEST

START_TEST(DelAfter_T2) {
  List L;
  int i;

  address Prec, Pdel;
  IsiListTest(&L);
  for (i = 4; i <= 8; i++) {
    InsVLastTest(&L, i);
  }

  Prec = First(L);
  for (i = 1; i < 3; i++) {
    Prec = Next(Prec);
  }
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmtTest(L), 7);
  ck_assert_int_eq(Info(Prec), 3);
  ck_assert_int_eq(Info(Pdel), 4);

  i = 1;
  address P = First(L);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
    if (i == 4) {
      i++;
    }
  }
} END_TEST

START_TEST(PrintForward_T1) {
  List L;
  int i;
  IsiListTest(&L);
  for (i = 4; i <= 8; i++) {
    InsVLastTest(&L, i);
  }
  PrintForward(L);
} END_TEST

START_TEST(PrintBackward_T1) {
  List L;
  int i;
  IsiListTest(&L);
  for (i = 4; i <= 8; i++) {
    InsVLastTest(&L, i);
  }
  PrintBackward(L);
} END_TEST

/****************** FUNGSI PADA TEST ******************/

void CreateEmptyTest(List *L) {
  First(*L) = Nil;
  Last(*L) = Nil;
}


address AlokasiTest (infotype X) {
  address P = (address) malloc (sizeof(ElmtList));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
		Prev(P) = Nil;
  }

  return P;
}

void InsVLastTest (List *L, infotype X) {
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = AlokasiTest(X);
    if (P != Nil) {
        Prev(P) = Last(*L); 
        if (!IsEmpty(*L)) {
            Next(Last(*L)) = P; 
        } else {
            First(*L) = P; 
        }
        Last(*L) = P; 
    }
}

void DelVLastTest (List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    address P;
    /* ALGORITMA */
    P = Last(*L);
    *X = Info(P);
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
    } else {
        Next(Prev(Last(*L))) = Nil; 
    }
    Last(*L) = Prev(Last(*L));
    Dealokasi(P);
}

void PrintForwardTest(List L) {
  printf("[");
  address P = First(L);
  while (P != Nil) {
    printf("%d", Info(P));
    P = Next(P);
    if (P != Nil) {
      printf(",");
    }
  }
  printf("]");
}

void PrintBackwardTest(List L){
  /* KAMUS */
  address P;
  /* ALGORITMA */
  printf("[");
  P = Last(L);
  if(!IsEmpty(L)){
      printf("%d", Info(Last(L)));
      P = Prev(Last(L));
      while (P != Nil) {
          printf("%d,", Info(P));
          P = Prev(P);
      }
  }
  printf("]\n");
}

void IsiListTest(List *L) {
  /* I.S. L kosong */
  /* F.S. Terbentuk list L dengan 3 elemen pertama berupa 1, 2, dan 3 */
  CreateEmptyTest(L);
  InsVLastTest(L, 1);
  InsVLastTest(L, 2);
  InsVLastTest(L, 3);
}

int NbElmtTest(List L) {
  int cnt = 0;
  address P;

  if (!IsEmpty(L)) {
    P = First(L);
    while (P != Nil) {
      cnt++;
      P = Next(P);
    }
  }

  return cnt;
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listdp_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List Double Pointer");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, CreateEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_T1);
  tcase_add_test(tc_search, Search_T2);
  tcase_add_test(tc_search, Search_T3);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, InsVFirst_T1);
  tcase_add_test(tc_primitif, InsVFirst_T2);
  tcase_add_test(tc_primitif, InsVLast_T1);
  tcase_add_test(tc_primitif, InsVLast_T2);
  tcase_add_test(tc_primitif, DelVFirst_T1);
  tcase_add_test(tc_primitif, DelVLast_T1);
  tcase_add_test(tc_primitif, InsertFirst_T1);
  tcase_add_test(tc_primitif, InsertAfter_T1);
  tcase_add_test(tc_primitif, InsertLast_T1);
  tcase_add_test(tc_primitif, DelFirst_T1);
  tcase_add_test(tc_primitif, DelFirst_T2);
  tcase_add_test(tc_primitif, DelFirst_T3);
  tcase_add_test(tc_primitif, DelP_T1);
  tcase_add_test(tc_primitif, DelP_T2);
  tcase_add_test(tc_primitif, DelP_T3);
  tcase_add_test(tc_primitif, DelLast_T1);
  tcase_add_test(tc_primitif, DelLast_T2);
  tcase_add_test(tc_primitif, DelAfter_T1);
  tcase_add_test(tc_primitif, DelAfter_T2);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintForward_T1);
  tcase_add_test(tc_proses, PrintBackward_T1);
  suite_add_tcase(s, tc_proses);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listdp_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}