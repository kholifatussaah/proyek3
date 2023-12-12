#include <iostream>
#include <fstream> 
#include <iomanip>
#include <conio.h>
 
using namespace std;
 
class item{
    //Data members
private:
    int code;
    char name[15];
    int qty;
    //member function
public:
    void put_item(void);
    void get_item(void);
    int get_code (void){
        return code;
    };
 
    int update_qty(int num){
        qty = qty-num;
        return qty;
    }
 
    void inputCode(){
    while (!(cin >> code))
        {
            cout << "ERROR: a number must be entered: ";
            cin.clear();
            cin.ignore(132, '\n');
        }
}
 
};
 
//Member fungtion class item di luar class
 
void item::get_item(void){
        cout << "Masukkan Kode Item: ";
        inputCode();
        //fflush(stdin);
        cout << "Masukkan Nama Item: "; cin >> name;
        cout << "Masukkan Qty: "; cin >> qty;
    }
 
void item::put_item(void){
    cout<<setw(6)<<code<<setw(15)<<name<<setw(6)<<qty<<endl; //setup dengan lebar field membutuhkan library iomanip
}
 
//Fuction Prototype
void addBarang(void);
void showAll(void);
void showBarang(void);
void deleteNamaBarang(void);
void modifBarang(void);
 
//Global Declaration
item it;        //membuat object item
fstream file;   //membuat object fstream
 
int main()
{
    int option;
    while(1){
        system("cls");
        cout<<"***MENU***"<<endl;
        cout<<"1. Tambah Barang"<<endl;
        cout<<"2. Tampil Semua Data"<<endl;
        cout<<"3. Cari Barang Tertentu"<<endl;
        cout<<"4. Hapus Nama Barang"<<endl;
        cout<<"5. Ubah Barang"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Masukkan nomor opsi: "; cin>>option;
        switch(option){
            case 1:{
                addBarang();
                cout<<"Tekan sembarang untuk kembali ke menu ...";
                getch(); //butuh library conio.h
                break;
            }
            case 2:{
                cout<<"-----------------------------------------\n";
                cout<<setw(6)<<"Kode"<<setw(15)<<"Nama Barang"<<setw(6)<<"Qty"<<endl;
                cout<<"-----------------------------------------\n";
                showAll();
                cout<<"-----------------------------------------\n";
                cout<<"Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 3:{
                showBarang();
                cout<<"Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 4:{
                deleteNamaBarang();
                cout<<"Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 5:{
                modifBarang();
                cout<<"Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 6:{
                exit(0);
            }
            default:{
                cout<<"Opsi pilihan tidak ada, Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
        }
    }
 
    return 0;
}
