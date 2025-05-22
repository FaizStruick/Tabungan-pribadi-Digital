#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Keuangan {
    string bulan;
    int tahun;
    float UangBulanan;
    float pengeluaranBulanan;
    float sisaBulanan;
};

void menyimpanData(const Keuangan& data) {
    ofstream file("data_uang.txt", ios::app);
    if (file.is_open()) {
        file << data.bulan << " " << data.tahun << " " << data.UangBulanan << " " << data.pengeluaranBulanan << " " << data.sisaBulanan << endl;
        file.close();
    } else {
        cout << " Yah gagal menyimpan data ke file." << endl;
    }
}

void tampilkanRingkasan(const Keuangan& data) {
    cout << "\n ---- Ringkasan Keuangan bulanan Faiz Bulan " << data.bulan << " " << data.tahun << " ----" << endl;
    cout << "Uang Bulanan         : Rp "  << data.UangBulanan << endl;
    cout << "Pengeluaran Bulanan  : Rp "  << data.pengeluaranBulanan << endl;
    cout << "Sisa Uang Bulanan    : Rp "  << data.sisaBulanan << endl;

    if (data.sisaBulanan > 500000) {
        cout << "Faiz disarankan untuk menabung minimal Rp 400.000 pada bulan ini!" << endl;
    } else if (data.sisaBulanan > 0) {
        cout << "Harus tetap hemat ya Faiz!, usahakan menabung minimal Rp " << data.sisaBulanan * 0.5 << endl;
    } else {
        cout << "Ayo Faiz Pengeluaran kamu bulan ini harus dikurangi lagi!" << endl;
    }
}

void tampilkanRiwayat() {
    ifstream file("data_uang.txt");
    if (file.is_open()) {
        string bulan;
        int tahun;
        float UangBulanan, pengeluaranBulanan, sisa;
        cout << "\n=== Riwayat Keuangan Bulanan Faiz ===" << endl;
        while (file >> bulan >> tahun >> UangBulanan >> pengeluaranBulanan >> sisa) {
            cout << bulan << " " << tahun << " || " << "Uang Bulanan : Rp " << UangBulanan << " || " << "Pengeluaran Bulanan : Rp " << pengeluaranBulanan << " || " << "Sisa Bulanan : Rp " << sisa << endl;
        }
        file.close();
    } else {
        cout << "Belum ada data keuangan kamu yang tersimpan." << endl;
    }
}
void meresetDataKeuangan() {
    ofstream file("data_uang.txt", ios::trunc);
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
    const int maksPercobaan = 4;

    while(percobaan < maksPercobaan){
        cout << "----- Selamat Datang Faiz!, silahkan untuk masukan pin terlebih dahulu ----- \n";
        cout << "PIN = ";
        cin >> pin;
        if(pin == pinBenar){
            cout << "YEAY PIN ANDA BENAR, SILAHKAN MASUK" <<endl;
            break;
        } else {
            percobaan++;
            cout << "PIN YANG ANDA MASUKAN 'SALAH', HARAP MASUKAN DENGAN TELITI" <<endl;
            if(percobaan < maksPercobaan){
                cout << "Silahkan untuk coba lagi, sisa percobaan anda tinggal : " << maksPercobaan - percobaan << " lagi." <<endl;
            } else {
                cout << "Anda sudah melewati batas percobaan sebanyak " << maksPercobaan << " kali, Anda tidak bisa mengakses tabungan ini." <<endl;
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
    cout << "|      Pengelola Keuangan Bulanan Pribadi       |" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|-----------------------------------------------|" <<endl;
    cout << "|  1. Catatan Keuangan Bulanan                  |" <<endl;
    cout << "|  2. Lihat Riwayat Keuangan Bulanan            |" <<endl;
    cout << "|  3. Reset Semua Data Keuangan                 |" <<endl;
    cout << "|  4. Keluar dari Program                       |" <<endl;
    cout << "|                                               |" <<endl;
    cout << "|  Pilih Menu (1-4) : ";     
    cin >> pilihanMenu;                                      
    cout << "-------------------------------------------------" <<endl;


    if(pilihanMenu == 1){
        Keuangan data;
        cout << "\nSelamat Datang, Faiz! catat keuangan Faiz bulan ini!." << endl;

        cout << "Masukkan nama bulan (Contoh : Juni) : ";
        cin >> data.bulan;

        cout << "Masukkan tahun (Contoh : 2025): ";
        cin >> data.tahun;

        cout << "Masukkan total uang bulanan pada bulan " << data.bulan << " (Rp) : ";
        cin >> data.UangBulanan;

        cout << "Masukkan total pengeluaran bulan " << data.bulan << " (Rp) : ";
        cin >> data.pengeluaranBulanan;


        data.sisaBulanan = data.UangBulanan - data.pengeluaranBulanan;

        tampilkanRingkasan(data);
        menyimpanData(data);

    } else if (pilihanMenu == 2){
        tampilkanRiwayat();

    } else if (pilihanMenu == 3){
        char konfirmasi;
        cout << "Anda yakin ingin menghapus SEMUA data keuangan? (yakin/tidak) : ";
        cin >> konfirmasi;
            
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        meresetDataKeuangan();
    } else {
        cout << "Konfirmasi dibatalkan." <<endl;
    }
    
    } else if (pilihanMenu == 4){
        cout << "Terima kasih telah menggunakan pengelola keuangan." <<endl;
        break;
    } else {
        cout << "pilihan anda tidak valid, pilih yang 1-4 saja." <<endl;
    }
    cout <<endl;

    cout << "Apakah anda ingin memilih pilihan lain yang ada pada menu? (iya/tidak) : ";
    cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}