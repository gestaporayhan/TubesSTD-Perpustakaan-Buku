#include "list_child.h"

/** Gery Nugroho
    1301170116 **/
void createList_child(List_child &L) {
    first(L) = NULL;
}

/** Gery Nugroho
    1301170116 **/
address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    return P;
}

/** Gery Nugroho
    1301170116 **/
void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        first(L) = P;
    } else {
        next(P)=first(L);
        first(L)=P;
    }
}

/** Gery Nugroho
    1301170116 **/
void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<"ID genre  :"<<info(P).ID<<endl;
        cout<<"Genre     :"<<info(P).Genre<<endl;
        P = next(P);
    }
}

/** Gery Nugroho
    1301170116 **/
address_child findElmName(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).Genre==x.Genre) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

/** Gery Nugroho
    1301170116 **/
address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).ID==x.ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

/** Gery Nugroho
    1301170116 **/
void insertAfter(List_child &L,address_child &Prec, address_child P) {
    if (Prec!=NULL) {
        next(P)=next(Prec);
        next(Prec)=P;
    }
}

/** Gery Nugroho
    1301170116 **/
void insertLast(List_child &L, address_child P) {
    address_child Q;
    Q=first(L);
    if (first(L)==NULL) {
        insertFirst(L,P);
    } else {
        while (next(Q)!=NULL) {
            Q=next(Q);
        }
        next(Q)=P;
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteLast(List_child &L, address_child &P) {
    address_child Q;
    Q=first(L);
    while (next(next(Q))!=NULL) {
        Q=next(Q);
    }
    P=next(Q);
    next(Q)=NULL;
}

/** Gery Nugroho
    1301170116 **/
void deleteFirst(List_child &L, address_child &P) {
    if (first(L)!=NULL) {
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteAfter(List_child &L,address_child Prec, address_child &P) {
    if (Prec!=NULL) {
        P=next(Prec);
        next(Prec)=next(P);
        next(P)=NULL;
    }
}

/** Gery Nugroho
    1301170116 **/
void dealokasi(address_child &P) {
    delete P;
}
