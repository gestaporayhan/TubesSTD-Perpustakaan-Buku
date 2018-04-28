#include "list_relasi.h"

/**List RELASI berupa SINGLE */

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void createList_relasi(List_relasi &L) {
    first(L) = NULL;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
address_relasi alokasi(address_parent P, address_child C) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
address_relasi dealokasi_relasi(address_relasi &P){
    delete P;
    return NULL;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"Judul Buku   : "<<info(parent(P)).JudulBuku<<endl
            <<"Genre Buku   : "<<info(child(P)).Genre<<endl;
        cout<<endl;
        P = next(P);
    }
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void insertFirst(List_relasi &L, address_relasi P) {
    first(L) = P;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void insertLast(List_relasi &L, address_relasi P) {
    address_relasi Q = first(L);
    while(next(Q)!= NULL) {
        Q = next(Q);
    }
    next(Q)=P;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void deleteFirst(List_relasi &L, address_relasi &P){
    if(first(L)!= NULL){
        P=first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void deleteLast(List_relasi &L, address_relasi &P){
    address_relasi Q = first(L);
    while(next(next(Q)) != P){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
address_relasi findElm(List_relasi L, address_parent P, address_child C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void dealokasi(address_relasi &P) {
    delete P;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void DeleteR (List_relasi &L, address_relasi &P) {
    if(first(L) != NULL){
        if(P == first(L) && next(first(L))==NULL){
            deleteFirst(L,P);
        } else {
            if (P==first(L)) {
                first(L)=next(first(L));
            }
            address_relasi Q = first(L);
            while(next(Q) != NULL){
                if(next(Q) == P){
                    next(Q) = next(P);
                    break;
                }
                Q = next(Q);
            }
        }
    }
}
