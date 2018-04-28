#include "list_parent.h"

/** Gery Nugroho
    1301170116 **/
void createList_parent(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
    last(L) =NULL;
}

/** Gery Nugroho
    1301170116 **/
address_parent alokasi_parent(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P)=x;
    next(P) = NULL;
    prev(P)=NULL;
    return P;
}

/** Gery Nugroho
    1301170116 **/
void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L) == NULL) {
        first(L) = P;
        last(L)=P;
        next(first(L)) = first(L);
        prev(first(L)) = first(L);
    } else {
        next(last(L))=P;
        prev(P)=last(L);
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;

    }
}

/** Gery Nugroho
    1301170116 **/
void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"ID Buku    :"<<info(P).ID<<endl;
            cout<<"Judul Buku :"<<info(P).JudulBuku<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

/** Gery Nugroho
    1301170116 **/
address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if (first(L)!=NULL) {
        do {
            if(info(P).ID== x.ID) {
                return P;
            }
            P = next(P);
        } while(P != first(L));

    }
    return NULL;
}

/** Gery Nugroho
    1301170116 **/
address_parent findElmName(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if (first(L)!=NULL) {
        do {
            if(info(P).JudulBuku== x.JudulBuku) {
                return P;
            }
            P = next(P);
        } while(P != first(L));

    }
    return NULL;
}
/** Gery Nugroho
    1301170116 **/
void insertLast(List_parent &L, address_parent P) {
    if (first(L)==NULL) {
        insertFirst(L,P);
    } else {
        next(last(L))=P;
        prev(first(L))=P;
        next(P)=first(L);
        prev(P)=last(L);
        last(L)=P;
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteFirst(List_parent &L, address_parent &P) {
    if (first(L)!=NULL) {
        if (next(first(L))==first(L)) {
            P=first(L);
            next(P)=NULL;
            prev(P)=NULL;
            first(L)=NULL;
        } else {
            P=first(L);
            next(last(L))=next(P);
            prev(next(P))=last(L);
            first(L)=next(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteLast(List_parent &L, address_parent &P) {
    if (first(L)!=NULL) {
        if (next(first(L))==first(L)) {
            deleteFirst(L,P);
        } else {
            P=last(L);
            next(prev(P))=first(L);
            prev(first(L))=prev(P);
            last(L)=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

/** Gery Nugroho
    1301170116 **/
void insertAfter(List_parent &L, address_parent Prec, address_parent P) {
    if (Prec!=NULL) {
        if (next(Prec)==Prec) {
            insertLast(L,P);
        } else {
            next(P)=next(Prec);
            prev(P)=Prec;
            prev(next(Prec))=P;
            next(Prec)=P;
        }
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteAfter(List_parent &L,address_parent Prec,address_parent &P) {
    if (Prec!=NULL) {
        if (Prec==first(L) && next(Prec)==first(L)){
            deleteFirst(L,P);
        } else if (next(Prec)==last(L)) {
            deleteLast(L,P);
        } else if (Prec==last(L)) {
            deleteFirst(L,P);
        } else {
            address_parent Q=next(Prec);
            prev(next(Q))=Q;
            next(Prec)=next(Q);
            next(Q)=NULL;
            prev(Q)=NULL;
        }
    }
}

/** Gery Nugroho
    1301170116 **/
void dealokasi(address_parent &P) {
    delete P;
}
