#include <iostream>

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>





using namespace std;
#include "list_child.h"
#include "list_relasi.h"
#include "list_parent.h"
#include "function.h"
#include <conio.h>
    List_child C;
    List_parent P;
    List_relasi R;
void displayMenu();
void runMenu(int menu);
void greet();

/** Gery Nugroho
    1301170116 **/
int main()
{
    system("color 3f");
    greet();
    system("CLS");
    int menu=-1;
    while (menu!=0) {
        displayMenu();
        cin>>menu;
        runMenu(menu);
        cout<<endl;
        if (menu!=0) {
            cout<<"press any button to back to menu ... ";
            getch();
            system("CLS");
        }

    }
    return 0;

}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void displayMenu () {
    cout<<"DAFTAR BUKU PERPUSTAKAAN"<<endl;
    cout<<endl;
    cout<<"========MENU BUKU========"<<endl;
    cout<<"1.Tambah Buku(parent)"<<endl;
    cout<<"2.Lihat list buku (parent)"<<endl;
    cout<<"3.Delete Buku (parent)"<<endl;
    cout<<"=======MENU GENRE========"<<endl;
    cout<<"4.Tambah Genre (Child)"<<endl;
    cout<<"5.Lihat List Genre(child)"<<endl;
    cout<<"6.Delete Genre (child)"<<endl;
    cout<<"=======MENU RELASI======="<<endl;
    cout<<"7.Hubungkan buku dan genre"<<endl;
    cout<<"8.Lihat List Relasi"<<endl;
    cout<<"9.Delete Relasi"<<endl;
    cout<<"=========LAINNYA========="<<endl;
    cout<<"10.Cari Buku By Judul Buku"<<endl;
    cout<<"11.Cari Buku by Genre"<<endl;
    cout<<"12.Lihat Semua Buku Berdasarkan Genre"<<endl;
    cout<<"13.Check Konensi Buku dan Genre"<<endl;
    cout<<"14.Lihat Semua Buku (child for each Parent)"<<endl;
    cout<<"15. Rata - Rata banyak Genre Per Buku"<<endl;
    cout<<"16. Genre Terbanyak di Semua Buku"<<endl;
    cout<<"=========================="<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"=========================="<<endl;
    cout<<"choose Menu : ";

}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void runMenu (int menu) {
    system("CLS");
    int i,v;
    address_child M;
    switch (menu) {
        case 1 :
            cout<<" Menu Input Data Buku "<<endl;
            cout<<endl;
            inputdataParent(P);
            break;
        case 2 :
            cout<<" Menu Lihat Data Buku "<<endl;
            cout<<endl;
            printInfo(P);
            break;
        case 3 :
            cout<<" Menu Hapus Data Buku"<<endl;
            cout<<endl;
            deleteBuku(P,R);
            break;
        case 4 :
            cout<<" Menu Input Data Genre "<<endl;
            cout<<endl;
            inputdataChild(C);
            break;
        case 5 :
            cout<<" Menu Lihat Data Genre "<<endl;
            cout<<endl;
            printInfo(C);
            break;
        case 6 :
            cout<<" Menu Hapus Data Genre "<<endl;
            cout<<endl;
            deleteGenre(C,R);
            break;
        case 7 :
            cout<<" Menu Hubungkan Buku dan Genre "<<endl;
            cout<<endl;
            tambahRelasi(R,C,P);
            break;
        case 8 :
            cout<<" Menu Lihat Data Relasi "<<endl;
            cout<<endl;
            printInfo(R);
            break;
        case 9 :
            cout<<" Menu Putuskan Hubungan Buku dan Genre "<<endl;
            cout<<endl;
            deleteRelasi(P,C,R);
            break;
        case 10 :
            cout<<" Menu Cari Buku "<<endl;
            cout<<endl;
            caribuku(P,C,R);
            break;
        case 11 :
            cout<<" Menu Cari Buku By Genre "<<endl;
            cout<<endl;
            caribuku2(P,C,R);
            break;
        case 12 :
            cout<< " Menu List Semua Buku Berdasarkan Genre "<<endl;
            cout<<endl;
            listbygenre(P,C,R,M,v);
            break;
        case 13 :
            cout<< " Check Relasi "<<endl;
            cout<<endl;
            checkRelation(C,P,R);
        case 14 :
            listbybuku(P,C,R,i);
            break;
        case 15 :
            hitungrata2buku(C,P,R);
            break;
        case 16 :
            genreterbanyak(R,C,P);
            break;
        default :
            cout<<"Pilihan Salah!! <ULANGI>"<<endl;
            break;
    }
}

/** Muhammad Rayhan Alifinzi
    1301174145              **/
void greet (){
    cout<<"    Selamat datang di aplikasi  Perpustakaan Buku"<<endl;
    cout<<"    Aplikasi ini memuat data Buku dan dihubungkan dengan genre Buku"<<endl;
    cout<<"    Setiap data buku bisa memiliki banyak genre dan setiap genre akan memiliki banyak data buku"<<endl<<endl;
    cout<<"    Create by : Gery Nugroho(1301170116) and Muhammad Rayhan Alifinzi(1301174145)."<<endl<<endl;
    cout<<"    Tekan <ENTER> untuk masuk ke Menu Utama";
    cin.get();
}
