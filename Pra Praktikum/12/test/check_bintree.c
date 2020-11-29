#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/boolean.h"
#include "../src/listrek.h"
#include "../src/bintree.h"

void ClearTree(BinTree *T);

/****************** Manajemen Memory ******************/
START_TEST(AlokNode_TC1) {
    infotype X = 2;
    addrNode P = AlokNode(X);
    ck_assert_int_eq(Info(P), X);
    ck_assert_ptr_eq(Left(P), Nil);
    ck_assert_ptr_eq(Right(P), Nil);
} END_TEST

START_TEST(DealokNode_TC1) {
    infotype X = 2;
    addrNode P = AlokNode(X);
    // Delokasi, seems impossible to be tested, so just check if no runtime error
    DealokNode(P);
} END_TEST

/****************** Konstruktor ******************/
START_TEST(Tree_TC1) {
    infotype Akar = 10;
    BinTree T1;

    T1 = Tree(Akar, Nil, Nil);
    ck_assert_int_eq(Akar(T1), 10);
    ck_assert_ptr_null(Left(T1));
    ck_assert_ptr_null(Right(T1));
} END_TEST

START_TEST(MakeTree_TC1) {
    infotype Akar = 10;
    BinTree T1, T2, T3;

    MakeTree(Akar, Nil, Nil, &T1);
    MakeTree(Akar, Nil, Nil, &T3);

    MakeTree(Akar, T1, T3, &T2);
    ck_assert_int_eq(Akar(T2), 10);
    ck_assert_ptr_eq(Left(T2), T1);
    ck_assert_ptr_eq(Right(T2), T3);
} END_TEST

/****************** Manajemen Memory ******************/
START_TEST(IsTreeEmpty_TC1) {
    BinTree T1;
    T1 = Nil;
    ck_assert_int_eq(IsTreeEmpty(T1), true);

    T1 = Tree(2, Nil, Nil);
    ck_assert_int_eq(IsTreeEmpty(T1), false);
} END_TEST

START_TEST(IsTreeOneElmt_TC1) {
    BinTree T1, T2;
    T1 = Nil;
    ck_assert_int_eq(IsTreeOneElmt(T1), false);

    T1 = Tree(2, Nil, Nil);
    ck_assert_int_eq(IsTreeOneElmt(T1), true);
    ClearTree(&T1);

    T2 = Tree(2, Nil, Nil);
    T1 = Tree(2, T2, T2);
    ck_assert_int_eq(IsTreeOneElmt(T1), false);
} END_TEST

START_TEST(IsUnerLeft_TC1) {
    BinTree T1, T2, T3, T4;
    T1 = Nil;
    ck_assert_int_eq(IsUnerLeft(T1), false);

    T2 = Tree(2, Nil, Nil);
    T4 = Tree(4, Nil, Nil);
    T1 = Tree(2, T4, T2);
    ck_assert_int_eq(IsUnerLeft(T1), false);

    T3 = Tree(3, T2, Nil);
    T1 = Tree(2, T3, Nil);
    ck_assert_int_eq(IsUnerLeft(T1), true);
} END_TEST

START_TEST(IsUnerRight_TC1) {
    BinTree T1, T2, T3, T4;
    T1 = Nil;
    ck_assert_int_eq(IsUnerRight(T1), false);

    T2 = Tree(2, Nil, Nil);
    T4 = Tree(4, Nil, Nil);
    T1 = Tree(2, T4, T2);
    ck_assert_int_eq(IsUnerRight(T1), false);
    ClearTree(&T1);

    T3 = Tree(3, Nil, T2);
    T1 = Tree(2, Nil, T3);
    ck_assert_int_eq(IsUnerRight(T1), true);
} END_TEST

START_TEST(IsBiner_TC1) {
    BinTree T1, T2, T3, T4;
    T1 = Nil;
    ck_assert_int_eq(IsBiner(T1), false);

    T2 = Tree(2, Nil, Nil);
    T4 = Tree(4, Nil, Nil);
    T1 = Tree(2, T4, T2);
    ck_assert_int_eq(IsBiner(T1), true);

    T3 = Tree(3, Nil, T2);
    T1 = Tree(2, Nil, T3);
    ck_assert_int_eq(IsBiner(T1), false);

    T3 = Tree(3, T2, Nil);
    T1 = Tree(2, T3, Nil);
    ck_assert_int_eq(IsBiner(T1), false);
} END_TEST

/****************** Traversal ******************/
void Print_TC1() {
    BinTree T1, T2, T3, T4;

    T4 = Tree(4, Nil, Nil);
    T3 = Tree(3, Nil, T4);
    T2 = Tree(2, Nil, Nil);
    T1 = Tree(1, T2, T3);

    PrintTree(T1, 4);
    PrintPreorder(T1);
    puts("");
    PrintInorder(T1);
    puts("");
    PrintPostorder(T1);
    puts("");
}

/****************** Searching ******************/
START_TEST(SearchTree_TC1) {
    BinTree T1, T2, T3, T4;

    T4 = Tree(4, Nil, Nil);
    T3 = Tree(3, Nil, T4);
    T2 = Tree(2, Nil, Nil);
    T1 = Tree(1, T2, T3);

    ck_assert_uint_eq(SearchTree(T1, 4), true);
    ck_assert_uint_eq(SearchTree(T1, 3), true);
    ck_assert_uint_eq(SearchTree(T1, 2), true);
    ck_assert_uint_eq(SearchTree(T1, 1), true);
    ck_assert_uint_eq(SearchTree(T1, 8), false);
    ck_assert_uint_eq(SearchTree(T1, 7), false);
    ck_assert_uint_eq(SearchTree(T1, 6), false);
    ck_assert_uint_eq(SearchTree(T1, 5), false);
} END_TEST

/****************** Fungsi-Fungsi lain ******************/
START_TEST(NbElmt_TC1) {
    BinTree T;

    T = Nil;
    ck_assert_int_eq(NbElmt(T), 0);
    T = Tree(1, Nil, Nil);
    ck_assert_int_eq(NbElmt(T), 1);
} END_TEST

START_TEST(NbDaun_TC1) {
    BinTree T;

    T = Nil;
    ck_assert_int_eq(NbDaun(T), 0);
    T = Tree(1, Nil, Nil);
    ck_assert_int_eq(NbDaun(T), 1);
    ClearTree(&T);

    T = Tree(1, Nil, Nil);
    AddDaunTerkiri(&T, 2);
    AddDaunTerkiri(&T, 3);
    ck_assert_int_eq(NbDaun(T), 1);
    ClearTree(&T);

    BinTree T2, T3;
    T = Tree(1, Nil, Nil);
    T2 = Tree(2, Nil, T);
    T3 = Tree(3, Nil, T2);
    ck_assert_int_eq(NbDaun(T3), 1);
} END_TEST

START_TEST(IsSkewLeft_TC1) {
    BinTree T1, T2, T3, T4;
    T1 = Nil;
    ck_assert_int_eq(IsSkewLeft(T1), true);

    T1 = Tree(2, Nil, Nil);
    ck_assert_int_eq(IsSkewLeft(T1), true);
    ClearTree(&T1);

    T2 = Tree(2, Nil, Nil);
    T4 = Tree(4, Nil, Nil);
    T1 = Tree(2, T4, T2);
    ck_assert_int_eq(IsSkewLeft(T1), false);

    T3 = Tree(3, T2, Nil);
    T1 = Tree(2, T3, Nil);
    ck_assert_int_eq(IsSkewLeft(T1), true);
} END_TEST

START_TEST(IsSkewRight_TC1) {
    BinTree T1, T2, T3, T4;
    T1 = Nil;
    ck_assert_int_eq(IsSkewRight(T1), true);

    T1 = Tree(2, Nil, Nil);
    ck_assert_int_eq(IsSkewRight(T1), true);
    ClearTree(&T1);

    T2 = Tree(2, Nil, Nil);
    T4 = Tree(4, Nil, Nil);
    T1 = Tree(2, T4, T2);
    ck_assert_int_eq(IsSkewRight(T1), false);

    T3 = Tree(3, Nil, T2);
    T1 = Tree(2, Nil, T3);
    ck_assert_int_eq(IsSkewRight(T1), true);
} END_TEST

START_TEST(Level_TC1) {
    BinTree T1, T2, T3, T4;

    T4 = Tree(4, Nil, Nil);
    T3 = Tree(3, Nil, T4);
    T2 = Tree(2, Nil, Nil);
    T1 = Tree(1, T2, T3);

    ck_assert_int_eq(Level(T1, 1), 1);
    ck_assert_int_eq(Level(T1, 2), 2);
    ck_assert_int_eq(Level(T1, 3), 2);
    ck_assert_int_eq(Level(T1, 4), 3);
} END_TEST

START_TEST(Tinggi_TC1) {
    BinTree T1, T2, T3, T4;

    T4 = Tree(4, Nil, Nil);
    T3 = Tree(3, Nil, T4);
    T2 = Tree(2, Nil, Nil);
    T1 = Tree(1, T2, T3);

    ck_assert_int_eq(Tinggi(T1), 3);
    ck_assert_int_eq(Tinggi(T2), 1);
    ck_assert_int_eq(Tinggi(T3), 2);
    ck_assert_int_eq(Tinggi(T4), 1);
} END_TEST

/****************** Operasi lain ******************/
START_TEST(AddDaunTerkiri_TC1) {
    BinTree T;

    T = Nil;
    AddDaunTerkiri(&T, 1);
    ck_assert_int_eq(Info(T), 1);
    ck_assert_ptr_null(Left(T));
    ck_assert_ptr_null(Right(T));

    AddDaunTerkiri(&T, 2);
    ck_assert_int_eq(Info(Left(T)), 2);
    ck_assert_ptr_nonnull(Left(T));
    ck_assert_ptr_null(Right(Left(T)));
} END_TEST

START_TEST(AddDaun_TC1) {
    BinTree T;

    MakeTree(1, Nil, Nil, &T);

    AddDaun(&T, 1, 3, false);
    ck_assert_int_eq(Akar(Right(T)), 3);
    AddDaun(&T, 3, 4, true);
    ck_assert_ptr_null(Right(Right(T)));
    ck_assert_ptr_nonnull(Left(Right(T)));
    ck_assert_int_eq(Akar(Left(Right(T))), 4);
} END_TEST

START_TEST(DelDaunTerkiri_TC1) {
    BinTree T;
    infotype A;

    T = Tree(0, Nil, Nil);
    AddDaunTerkiri(&T, 1);
    AddDaunTerkiri(&T, 2);
    AddDaunTerkiri(&T, 3);

    DelDaunTerkiri(&T, &A);
    ck_assert_int_eq(A, 3);
    DelDaunTerkiri(&T, &A);
    ck_assert_int_eq(A, 2);
    DelDaunTerkiri(&T, &A);
    ck_assert_int_eq(A, 1);

    T = Nil;
    AddDaunTerkiri(&T, 1);
    AddDaunTerkiri(&T, 2);
    AddDaun(&T, 2, 3, false);
    AddDaun(&T, 3, 4, true);

    DelDaunTerkiri(&T, &A);
    ck_assert_int_eq(A, 4);
} END_TEST

START_TEST(MakeListDaun_TC1) {
    List L;
    BinTree T;

    T = Nil;
    L = MakeListDaun(T);
    ck_assert_int_eq(IsEmpty(L), true);

    AddDaunTerkiri(&T, 1);
    L = MakeListDaun(T);
    ck_assert_int_eq(IsOneElmt(L), true);

    AddDaunTerkiri(&T, 2);
    L = MakeListDaun(T);
    ck_assert_ptr_null(Next(L));
    ck_assert_int_eq(FirstElmt(L), 2);
} END_TEST

START_TEST(MakeListPreorder_TC1) {
    List L;
    BinTree T;

    T = Nil;
    L = MakeListPreorder(T);
    ck_assert_int_eq(IsEmpty(L), true);

    AddDaunTerkiri(&T, 1);
    L = MakeListPreorder(T);
    ck_assert_int_eq(IsOneElmt(L), true);

    AddDaunTerkiri(&T, 2);
    L = MakeListPreorder(T);
    ck_assert_ptr_nonnull(Next(L));
    ck_assert_int_eq(FirstElmt(L), 1);
    ck_assert_int_eq(FirstElmt(Next(L)), 2);
} END_TEST
 
/****************** Binary Search Tree ******************/
START_TEST(InsSearch_TC1) { /* BSearch dipke di InsSearch */
    BinTree Bst1;

    Bst1 = Nil;
    InsSearch(&Bst1, 8);
    ck_assert_ptr_nonnull(Bst1);
    ck_assert_int_eq(IsTreeOneElmt(Bst1), true);

    InsSearch(&Bst1, 4);
    InsSearch(&Bst1, 9);
    ck_assert_int_eq(IsTreeOneElmt(Bst1), false);
    ck_assert_int_eq(Akar(Left(Bst1)), 4);
    ck_assert_int_eq(Akar(Right(Bst1)), 9);

    InsSearch(&Bst1, 3);
    InsSearch(&Bst1, 5);
    ck_assert_int_eq(Akar(Left(Left(Bst1))), 3);
    ck_assert_int_eq(Akar(Right(Left(Bst1))), 5);
} END_TEST

START_TEST(DelBTree_TC1) {
    BinTree Bst1;

    Bst1 = Nil;
    InsSearch(&Bst1, 8);
    InsSearch(&Bst1, 4);
    InsSearch(&Bst1, 9);
    InsSearch(&Bst1, 3);
    InsSearch(&Bst1, 5);

    DelBtree(&Bst1, 3);
    ck_assert_ptr_null(Left(Left(Bst1)));
    PrintPreorder(Bst1);
    DelBtree(&Bst1, 4);
    ck_assert_ptr_nonnull(Left(Bst1));
    ck_assert_int_eq(Akar(Left(Bst1)), 5);
} END_TEST

/****************** Helpers ******************/
void ClearTree(BinTree *T) {
    if (IsTreeEmpty(*T));
    else if (IsTreeOneElmt(*T)) {
        *T = Nil;
        DealokNode(*T);
    } else {
        ClearTree(&Left(*T));
        ClearTree(&Right(*T));

        *T = Nil;
        DealokNode(*T);
    }
}

Suite *bintree_suite() {
    Suite *s;
    TCase *tc_mem,
          *tc_konstruk,
          *tc_predikat,
          *tc_searching,
          *tc_fungsiLain,
          *tc_operasiLain,
          *tc_bst;

    s = suite_create("Binary Tree");

    tc_mem = tcase_create("Memori");
    tcase_add_test(tc_mem, AlokNode_TC1);
    tcase_add_test(tc_mem, DealokNode_TC1);
    suite_add_tcase(s, tc_mem);

    tc_konstruk = tcase_create("Konstruktor");
    tcase_add_test(tc_konstruk, MakeTree_TC1);
    tcase_add_test(tc_konstruk, Tree_TC1);
    suite_add_tcase(s, tc_konstruk);

    tc_predikat = tcase_create("Predikat-predikat penting");
    tcase_add_test(tc_predikat, IsTreeEmpty_TC1);
    tcase_add_test(tc_predikat, IsTreeOneElmt_TC1);
    tcase_add_test(tc_predikat, IsUnerLeft_TC1);
    tcase_add_test(tc_predikat, IsUnerRight_TC1);
    tcase_add_test(tc_predikat, IsBiner_TC1);
    suite_add_tcase(s, tc_predikat);

    Print_TC1();

    tc_searching = tcase_create("Searching");
    tcase_add_test(tc_searching, SearchTree_TC1);
    suite_add_tcase(s, tc_searching);

    tc_fungsiLain = tcase_create("Fungsi lain");
    tcase_add_test(tc_fungsiLain, NbElmt_TC1);
    tcase_add_test(tc_fungsiLain, NbDaun_TC1);
    tcase_add_test(tc_fungsiLain, IsSkewLeft_TC1);
    tcase_add_test(tc_fungsiLain, IsSkewRight_TC1);
    tcase_add_test(tc_fungsiLain, Level_TC1);
    tcase_add_test(tc_fungsiLain, Tinggi_TC1);
    suite_add_tcase(s, tc_fungsiLain);

    tc_operasiLain = tcase_create("Operasi lain");
    tcase_add_test(tc_operasiLain, AddDaunTerkiri_TC1);
    tcase_add_test(tc_operasiLain, AddDaun_TC1);
    tcase_add_test(tc_operasiLain, DelDaunTerkiri_TC1);
    tcase_add_test(tc_operasiLain, MakeListDaun_TC1);
    tcase_add_test(tc_operasiLain, MakeListPreorder_TC1);
    suite_add_tcase(s, tc_operasiLain);

    tc_bst = tcase_create("Binary search tree");
    tcase_add_test(tc_bst, InsSearch_TC1);
    tcase_add_test(tc_bst, DelBTree_TC1);
    suite_add_tcase(s, tc_bst);

    return s;
}

int main() {
    int fail_count = 0;
    Suite *s;
    SRunner *runner;

    s = bintree_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    fail_count = srunner_ntests_failed(runner);
    srunner_free(runner);

    return fail_count ? EXIT_FAILURE : EXIT_SUCCESS;
}
