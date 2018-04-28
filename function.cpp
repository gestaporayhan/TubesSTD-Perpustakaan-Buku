#include <iostream>

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <string>





using namespace std;
#include "list_child.h"
#include "list_relasi.h"
#include "list_parent.h"
#include <conio.h>

    address_parent A,B;
    infotype_parent W,Y,Z;
    address_child S;
    address_parent Q,DP;
    address_relasi I,DPP,PP;
    char X[100];
    bool t,PD;
    char g,o;
    int qwe,po,po1,po2;

/** Gery Nugroho
    1301170116 **/
void inputdataParent (List_parent &P) {
    infotype_parent X;
    cout<<"Masukkan ID    :  ";
    cin>>X.ID;
    cout<<"Masukkan Judul Buku  :  ";
    cin.ignore();
    getline(cin,X.JudulBuku);
    address_parent W=findElmName(P,X);
    address_parent R=alokasi_parent(X);
    address_parent Q=findElm(P,X);
    if (Q==NULL && W==NULL) {
        insertLast(P,R);
    } else {
        cout<<"ID atau Nama duplikat"<<endl;
    }

}

/** Gery Nugroho
    1301170116 **/
void inputdataChild (List_child &C) {
    infotype_child X;
    cout<<"Masukkan ID    :  ";
    cin>>X.ID;
    cout<<"Masukkan Genre Buku  :  ";
    cin.ignore();
    getline(cin,X.Genre);
    address_child R=alokasi(X);
    address_child Q=findElm(C,X);
    address_child W=findElmName(C,X);
    if (Q==NULL && W==NULL) {
        insertLast(C,R);
    } else {
        cout<<"ID duplikat atau Nama duplikat"<<endl;
    }

}

/** Gery Nugroho
    1301170116 **/
void deleteBuku (List_parent &P, List_relasi &R) {
    infotype_parent x;
    address_parent A;
    address_relasi S,W1;
    cout<<"Nama Buku yang dihapus : ";
    cin.ignore();
    getline(cin,x.JudulBuku);
    address_parent Q=findElmName(P,x);
    if (Q!=NULL) {
            S=first(R);
            while (S!=NULL) {
                address_relasi tmp=NULL;
                if (parent(S)==Q) {
                    DeleteR(R,S);
                    tmp=S;
                }
                S=next(S);
                if (tmp==NULL) {
                    dealokasi(tmp);
                }
            }
            deleteAfter(P,prev(Q),A);
            dealokasi(A);
    } else {
        cout<<"Buku tidak DITEMUKAN"<<endl;
    }


}

/** Gery Nugroho
    1301170116 **/
void deleteGenre (List_child &P, List_relasi &R) {
    infotype_child x;
    address_child A,B,D;
    address_relasi Z,S;
    cout<<"Genre Buku yang dihapus : ";
    cin.ignore();
    getline(cin,x.Genre);
    address_child Q=findElmName(P,x);
    if (Q!=NULL) {
            S=first(R);
            while (S!=NULL) {
                address_relasi tmp=NULL;
                if (child(S)==Q) {
                    DeleteR(R,S);
                    tmp=S;
                }
                S=next(S);
                if (tmp==NULL) {
                    dealokasi(tmp);
                }
            }
            B=first(P);
            if (first(P)==Q) {
                deleteFirst(P,A);
            } else {
                while (next(B)!=Q) {
                    B=next(B);
                }
                deleteAfter(P,B,A);
                dealokasi(A);
            }
    } else {
        cout<<"Genre tidak DITEMUKAN"<<endl;
    }


}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void tambahRelasi (List_relasi &R, List_child &C,List_parent &P) {
    infotype_child W;
    infotype_parent X;
    address_parent Q;
    address_child E;
    address_relasi S,T;
    cout<<"Judul Buku yang direlasikan : ";
    cin.ignore();
    getline(cin,X.JudulBuku);
    Q=findElmName(P,X);
    cout<<"Genre Buku yang direlasikan : ";
    getline(cin,W.Genre);
    E=findElmName(C,W);
    if (E!=NULL && Q!=NULL) {
        T=findElm(R,Q,E);
        S=alokasi(Q,E);
        if (T==NULL) {
            if (first(R)==NULL) {
                insertFirst(R,S);
            } else {
                insertLast(R,S);
            }
        } else {
            cout<<endl;
            cout<<"==============="<<endl;
            cout<<"Relasi Duplikasi"<<endl;
            cout<<"================"<<endl;
        }
    } else {
        cout<<endl;
        cout<<"salah satu node tidak ditemukan"<<endl;
    }
}

/** Gery Nugroho
    1301170116 **/
void deleteRelasi(List_parent P,List_child C,List_relasi &R) {
    infotype_parent Y;
    infotype_child G;
    address_relasi B;
    cout<<"Masukkan Judul Buku : ";
    cin.ignore();
    getline(cin,Y.JudulBuku);
    cout<<"Masukkan genre Buku : ";
    getline(cin,G.Genre);
    address_child Q=findElmName(C,G);
    address_parent W=findElmName(P,Y);
    if (Q!=NULL && W!=NULL) {
        address_relasi K=findElm(R,W,Q);
        if (K!=NULL) {
            address_relasi O=first(R);
            if (K==first(R)) {
                deleteFirst(R,B);
                dealokasi(B);
            } else {
                while (next(O)!=K) {
                    O=next(O);
                }
                deleteAfter(R,O,B);
                dealokasi(B);
            }
        } else {
            cout<<"tidak ada relasi"<<endl;
        }
    } else {
        cout<<"salah satu atau kedua node tidak ditemukan"<<endl;
    }
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void caribuku (List_parent P,List_child C, List_relasi R) {
            infotype_parent X;
            cout<<"Judul Buku yang dicari : ";
            cin.ignore();
            getline(cin,X.JudulBuku);
            address_relasi Q= first(R);
    int i=0;
        while (Q!=NULL) {
            if (info(parent(Q)).JudulBuku==X.JudulBuku) {
                if (i==0) {
                    cout<<"Judul Buku   : "<<info(parent(Q)).JudulBuku<<endl
                        <<"Genre Buku   : "<<info(child(Q)).Genre;
                } else {
                    cout<<", "<<info(child(Q)).Genre;
                }
            }
            i++;

            Q=next(Q);
        }
    cout<<endl;
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void caribuku2 (List_parent P,List_child C, List_relasi R) {
            infotype_child X;
            cout<<"Genre yang Dicari : ";
            cin.ignore();
            getline(cin,X.Genre);
            address_relasi Q= first(R);
            cout<<"List Buku di Genre "<<X.Genre<<endl;
            int i=0;
            while (Q!=NULL) {
                if (X.Genre==info(child(Q)).Genre) {
                    i++;
                    cout<<i<<". "<<info(parent(Q)).JudulBuku<<endl;
                }

                Q=next(Q);
            }
    cout<<endl;
}

/** Gery Nugroho
    1301170116 **/
void listbygenre (List_parent W,List_child C,List_relasi R,address_child &Z, int &v){
    address_child P=first(C);
    int i;
    v=0;
    if (P!=NULL) {
        while (P!=NULL) {
            cout<<"==========================="<<endl;
            cout<<"Genre "<<info(P).Genre<<" : "<<endl;
            address_relasi Q=first(R);
            i=0;
            while (Q!=NULL) {

                if (P==child(Q)) {
                    i++;
                    cout<<i<<". "<<info(parent(Q)).JudulBuku<<endl;
                }
                Q=next(Q);
            }
            if (v<i) {
                v=i;
                Z=P;
            }
            cout<<endl;
            cout<<"Banyak Buku di Genre "<<info(P).Genre<<" : "<<i<<" Buah"<<endl;
            cout<<endl;
            P=next(P);
        }
    }
}
/** Gery Nugroho
    1301170116 **/
void listbybuku (List_parent W,List_child C,List_relasi R,int &i){
    address_parent P=first(W);
    i=0;
    if (P!=NULL) {
        do {
            cout<<"==========================="<<endl;
            cout<<"Judul Buku : "<<info(P).JudulBuku<<endl;
            address_relasi Q=first(R);
            cout<<"Genre Buku : ";
            while (Q!=NULL) {
                if (P==parent(Q)) {
                    cout<<info(child(Q)).Genre<<", ";
                    i++;
                }
                Q=next(Q);
            }
            cout<<endl;
            cout<<endl;
            P=next(P);
        } while (P!=first(W));
    }
}

/** Gery Nugroho
    1301170116 **/
void checkRelation (List_child C, List_parent P, List_relasi R) {
    infotype_parent Y;
    infotype_child G;
    address_relasi B;
    cout<<"Masukkan Judul Buku : ";
    cin.ignore();
    getline(cin,Y.JudulBuku);
    cout<<"Masukkan genre Buku : ";
    getline(cin,G.Genre);
    address_child Q=findElmName(C,G);
    address_parent W=findElmName(P,Y);
    B=findElm(R,W,Q);

    if (B==NULL) {
        cout<<"Tidak ada Relasi"<<endl;
    } else {
        cout<<"terhubung"<<endl;
    }
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void hitungrata2buku (List_child C, List_parent P, List_relasi R) {
    int i,v;
    address_parent W=first(P);
    i=0;
    if (W!=NULL) {
        do {
            i++;
            W=next(W);
        } while(W!=first(P));
        listbybuku(P,C,R,v);
        system("CLS");
        int Q=v/i;
        cout<<" rata-rata genre per buku adalah  1 berbanding "<<Q<<endl;


        v=0;
    }

}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void genreterbanyak(List_relasi R, List_child C,List_parent P) {
    int i;
    if (first(R)!=NULL) {
        address_child B;
        listbygenre(P,C,R,B,i);
        system("CLS");
        cout<<" Genre "<<info(B).Genre<<" merupakan Genre terbanyak terdapat di semua buku yaitu sebanyak "<<i<<" buah buku"<<endl;
    }
}
