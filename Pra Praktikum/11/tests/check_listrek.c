/* NIM			        : 13519104
    Nama		        : Nabelanita Utami
    Tanggal		      : 18 November 2020
    Topik praktikum	: List Rekursif
    Deskripsi		    : File check_listrek.c */

#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/boolean.h"
#include "../src/listrek.h"

void CreateList(List *L, int data[], int count);

START_TEST(IsEmpty_TC1) {
  List L;
  L = Nil;
  ck_assert_int_eq(IsEmpty(L), 1);
  L = KonsB(L, 100);
  ck_assert_int_eq(IsEmpty(L), 0);
} END_TEST

START_TEST(IsOneElmt_TC1) {
  List L;
  L = Nil;
  ck_assert_int_eq(0, IsOneElmt(L));
  L = KonsB(L, 100);
  ck_assert_int_eq(1, IsOneElmt(L));
  L = KonsB(L, 420);
  ck_assert_int_eq(0, IsOneElmt(L));
} END_TEST

START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
} END_TEST

START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
} END_TEST

START_TEST(FirstElmt_TC1) {
  List L;
  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  infotype ans = FirstElmt(L);
  ck_assert_int_eq(ans, 1);
} END_TEST

START_TEST(Tail_TC1) {
  List L, LTest;
  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);

  LTest = Tail(L);

  int i = 2;
  List P = LTest;
  ck_assert_ptr_ne(Next(L), Nil);
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(Search_TC1) {
  List L;
  infotype search = 2;
  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  boolean ans = Search(L, search);
  ck_assert_int_eq(ans, true);
} END_TEST

START_TEST(Search_TC2) {
  List L;
  infotype search = 2;
  int data[] = {1};
  CreateList(&L, data, 1);
  boolean ans = Search(L, search);
  ck_assert_int_eq(ans, false);
} END_TEST

START_TEST(Search_TC3) {
  List L;
  infotype search = 1;
  L = Nil;
  boolean ans = Search(L, search);
  ck_assert_int_eq(ans, false);
} END_TEST
 

START_TEST(Konso_TC1) {
  List L;
  L = Nil;
  infotype X = 1;

  L = Konso(X, L);
  ck_assert_int_eq(Info(L), 1);
} END_TEST

START_TEST(Konso_TC2) {
  List L;
  infotype X = 0;

  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  L = Konso(X, L);

  int i = 0;
  List P = L;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(KonsB_TC1) {
  List L;
  infotype X = 1;
  L = Nil;
  L = KonsB(L, X);
  ck_assert_int_eq(Info(L), 1);
} END_TEST

START_TEST(KonsB_TC2) {
  List L;
  infotype X = 6;

  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  L = KonsB(L, X);

  int i = 1;
  address P = L;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(Copy_TC1) {
  List L, LTest;
  
  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  LTest = Copy(L);

  int i = 1;
  address P = LTest;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(MCopy_TC1) {
  List L, LTest;
  LTest = Nil;
  
  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  MCopy(L, &LTest);

  int i = 1;
  address P = LTest;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(Concat_TC1) {
  List L1, L2, LTest;
  
  int data1[] = {1, 2, 3, 4, 5};
  int data2[] = {6, 7, 8, 9, 10};
  CreateList(&L1, data1, 5);
  CreateList(&L2, data2, 5);
  LTest = Concat(L1, L2);

  int i = 1;
  address P = LTest;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(MConcat_TC1) {
  List L1, L2, LTest;
  
  int data1[] = {1, 2, 3, 4, 5};
  int data2[] = {6, 7, 8, 9, 10};
  CreateList(&L1, data1, 5);
  CreateList(&L2, data2, 5);
  MConcat(L1, L2, &LTest);

  int i = 1;
  address P = LTest;
  while (P != Nil) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
} END_TEST

START_TEST(NbElmtList_TC1) {
  List L;
  infotype ans;

  int data[] = {1, 2, 3, 4, 5};
  CreateList(&L, data, 5);
  ans = NbElmtList(L);
  ck_assert_int_eq(ans, 5);

  L = KonsB(L, 6);
  ans = NbElmtList(L);
  ck_assert_int_eq(ans, 6);
} END_TEST

START_TEST(PrintList_TC1) {
  List L;
  int i;
  int data[] = {1, 2, 3};
  CreateList(&L, data, 3);
  for (i = 4; i <= 8; i++) {
    L = KonsB(L, i);
  }
} END_TEST


/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listrek_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List Rekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, FirstElmt_TC1);
  tcase_add_test(tc_prototype, Tail_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_TC1);
  tcase_add_test(tc_search, Search_TC2);
  tcase_add_test(tc_search, Search_TC3);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, Konso_TC1);
  tcase_add_test(tc_primitif, Konso_TC2);
  tcase_add_test(tc_primitif, KonsB_TC1);
  tcase_add_test(tc_primitif, KonsB_TC2);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintList_TC1);
  tcase_add_test(tc_proses, Copy_TC1);
  tcase_add_test(tc_proses, MCopy_TC1);
  tcase_add_test(tc_proses, Concat_TC1);
  tcase_add_test(tc_proses, MConcat_TC1);
  tcase_add_test(tc_proses, NbElmtList_TC1);
  suite_add_tcase(s, tc_proses);

  return s;
} 

void CreateList(List *L, int data[], int count){
  int i;
  *L = Nil;
  for(i = 0; i < count; i++){
    *L = KonsB(*L, data[i]);
  }
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listrek_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
