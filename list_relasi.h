#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

/** list relasi header by
    Muhammad Rayhan Alifinzi
    1301174145              **/

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList_relasi(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi &P);
void printgenre(List_relasi L);
address_relasi findBefore (List_relasi L, address_relasi x);
void DeleteR (List_relasi &L, address_relasi &P);



/** PERLU MODIFIKASI */
address_relasi alokasi( address_parent P, address_child C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);
void printParent(List_relasi L, infotype_parent P);


#endif // LIST_RELASI_H_INCLUDED
