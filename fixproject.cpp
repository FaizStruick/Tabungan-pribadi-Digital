#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

struct Keuangan {
    string bulan;
    int tahun;
    float UangBulanan;
    float pengeluaran;
    float sisa;
};

void simpanData(const Keuangan& data) {
    ofstream file("data_keuangan.txt", ios::app);
    if (file.is_open()) {
        file << data.bulan << " " << data.tahun << " "
             << data.UangBulanan << " "
             << data.pengeluaran << " "
             << data.sisa << endl;
        file.close();
    } else {
        cout << "Gagal menyimpan data ke file." << endl;
    }
}

void tampilkanRingkasan(const Keuangan& data) {
    cout << "\n--- Ringkasan Keuangan Bulan " << data.bulan << " " << data.tahun << " ---" << endl;
    cout << "Uang Bulanan  : Rp "  << data.UangBulanan << endl;
    cout << "Pengeluaran : Rp "  << data.pengeluaran << endl;
    cout << "Sisa Uang   : Rp "  << data.sisa << endl;

    if (data.sisa > 500000) {
        cout << "Kamu disarankan untuk menabung minimal Rp 400.000 pada bulan ini!" << endl;
    } else if (data.sisa > 0) {
        cout << "Harus tetap hemat ya!, usahakan menabung minimal Rp " << data.sisa * 0.5 << endl;
    } else {
        cout << "Ayo Pengeluaran kamu bulan ini harus dikurangi lagi!" << endl;
    }
}

void tampilkanSemuaData() {
    ifstream file("data_keuangan.txt");
    if (file.is_open()) {
        string bulan;
        int tahun;
        float UangBulanan, pengeluaran, sisa;
        cout << "\n----- Riwayat Keuangan Anda -----" << endl;
        while (file >> bulan >> tahun >> UangBulanan >> pengeluaran >> sisa) {
            cout << bulan << " " << tahun << " | "
                 << "Pemasukan : Rp " << UangBulanan << ", "
                 << "Pengeluaran : Rp " << pengeluaran << ", "
                 << "Sisa : Rp " << sisa << endl;
        }
        file.close();
    } else {
        cout << "Belum ada data keuangan yang tersimpan." << endl;
    }
}
void resetDataKeuangan() {
    ofstream file("data_keuangan.txt", ios::trunc);
    if (file.is_open()) {
        file.close();
        cout << "Semua data keuangan berhasil di-reset." << endl;
    } else {
        cout << "Gagal mengakses file untuk reset data." << endl;
    }
}

int main() {
    string pin;
    const string pinBenar = "009987";
    int percobaan = 0;
    const int maksPercobaan = 3;
    char konfirmasi;

    while(percobaan < maksPercobaan){
        cout << " ----- Selamat Datang, silahkan untuk masukan pin terlebih dahulu ----- \n";
        cout << "PIN = ";
        cin >> pin;
        if(pin == pinBenar){
            cout << "YEAY PIN ANDA BENAR, SILAHKAN MASUK" <<endl;
            cin.ignore();
            break;
        } else {
            percobaan++;
            cout << "PIN YANG ANDA MASUKAN 'SALAH', HARAP MASUKAN DENGAN TELITI" <<endl;
            if(percobaan < maksPercobaan){
                cout << "Silahkan coba lagi, sisa percobaan anda tinggal : " << maksPercobaan - percobaan << " lagi." <<endl;
            } else {
                cout << "Anda telah melebihi percobaan. Anda tidak bisa memasuki tabungan ini.\n";
                return 0;
            }
        }
    }
    cout << fixed << setprecision(2);

    int pilihanMenu;
    char lanjut;
    
    do{
    cout << "-------------------------------------------------" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|       Aplikasi Tabungan Pribadi Digital       |" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|  1. Catatan Keuangan Bulanan                  |" <<endl;
    cout << "|  2. Lihat Riwayat Keuangan Bulanan            |" <<endl;
    cout << "|  3. Reset Semua Data Keuangan                 |" <<endl;
    cout << "|  4. Keluar Program                            |" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|  Pilih Menu (1-4) : ";     
    cin >> pilihanMenu;                                      
    cout << "-------------------------------------------------" <<endl;


    if(pilihanMenu == 1){
        Keuangan data;
        cout << "\nSelamat Datang, Faiz! Yuk catat keuangan kamu bulan ini." << endl;

        cout << "Masukkan nama bulan (misal : Juni) : ";
        cin >> data.bulan;

        cout << "Masukkan tahun (misal : 2025): ";
        cin >> data.tahun;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        

        cout << "Masukkan total uang bulanan pada " << data.bulan << " (Rp) : ";
        cin >> data.UangBulanan || data.UangBulanan < 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan total pengeluaran bulan " << data.bulan << " (Rp) : ";
        cin >> data.pengeluaran || data.pengeluaran < 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        data.sisa = data.UangBulanan - data.pengeluaran;

        tampilkanRingkasan(data);
        simpanData(data);

    } else if (pilihanMenu == 2){
        tampilkanSemuaData();

    } else if (pilihanMenu == 3){
        char konfirmasi;
        cout << "Anda yakin ingin menghapus SEMUA data keuangan? (yakin/tidak) : ";
        cin >> konfirmasi;
            
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        resetDataKeuangan();
    } else {
        cout << "Konfirmasi dibatalkan." <<endl;
    }
    } else if (pilihanMenu == 4){
        cout << "Terima kasih telah menggunakan aplikasi kami." <<endl;
        break;
    } else {
        cout << "Tidak valid, pilih yang 1-4 saja." <<endl;
    }
    cout <<endl;

    cout << "Apakah anda ingin memilih pilihan lain yang ada pada menu? (iya/tidak) : ";
    cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}