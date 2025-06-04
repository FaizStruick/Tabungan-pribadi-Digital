#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Keuangan {
    string bulan;
    int tahun;
    float uangBulanan;
    float pengeluaranBulanan;
    float sisaBulanan;
    string ringkasanPengeluaran;

};
vector<string> jenisPengeluaran;
vector<float> jumlahPengeluaran;


void menyimpanData(const Keuangan& data) {
    ofstream file("data_uang.txt", ios::app);
    if (file.is_open()) {
        file << data.bulan << " " << data.tahun << " " << data.uangBulanan << " " << data.pengeluaranBulanan << " " << data.sisaBulanan << " " << data.ringkasanPengeluaran << endl;
        file.close();
    } else {
        cout << " Yah gagal menyimpan data ke file." << endl;
    }
}
void tampilkanRingkasan(const Keuangan& data) {
    cout << "\n ---- Ringkasan Keuangan bulanan Faiz Bulan " << data.bulan << " " << data.tahun << " ----" << endl;
    cout << "Uang Bulanan            : Rp "  << data.uangBulanan << endl;
    cout << "Pengeluaran Bulanan     : Rp "  << data.pengeluaranBulanan << endl;
    cout << "Ringkasan Pengeluaran   : "<< data.ringkasanPengeluaran <<endl;
    cout << "Sisa Uang Bulanan       : Rp "  << data.sisaBulanan << endl;


    if (data.sisaBulanan > 600000) {
        cout << "Faiz disarankan untuk menabung minimal Rp 400.000 pada bulan ini!" << endl;
    } else if (data.sisaBulanan > 400000) {
        cout << "Faiz kamu disarankan untuk menabung minimal Rp 300.000 pada bulan ini!" <<endl;
    } else if (data.sisaBulanan > 50000) {
        cout << "Hati-hati Faiz keuanganmu hampir menipis, pengeluarannya lebih dikurangi lagi" <<endl;
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
        float uangBulanan, pengeluaranBulanan, sisa;
        string ringkasanKeuangan;
        cout << "\n=== Riwayat Keuangan Bulanan Faiz ===" << endl;
    while (file >> bulan >> tahun >> uangBulanan >> pengeluaranBulanan >> sisa >> ringkasanKeuangan ) {
        cout << bulan << " " << tahun << " || " << "Uang Bulanan : Rp " << uangBulanan << " || " << "Pengeluaran Bulanan : Rp " << pengeluaranBulanan << " || " << "Sisa Bulanan : Rp " << sisa
        << " || " << " Ringkasan Pengeluaran : " << ringkasanKeuangan << endl;
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
        cout << "Semua data keuangan anda telah dihapus." << endl;
    } else {
        cout << "Gagal mengakses file untuk reset data." << endl;
    }
}

int main() {
// Sebelum masuk ke program diharapkan untuk memasukan pin terlebih dahulu
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
                cout << "Silahkan coba lagi, percobaan anda tersisa : " << maksPercobaan - percobaan << " lagi." <<endl;
            } else {
                cout << "Anda sudah melewati batas percobaan sebanyak " << maksPercobaan << " kali, Anda tidak bisa mengakses tabungan ini." <<endl;
                return 0;
            }
        }
    }
    cout << fixed << setprecision(2);  

    // Awal untuk Memilih pilihan Menu
    int pilihMenu;
    char lanjutkan;
    
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
    cin >> pilihMenu;                                      
    cout << "-------------------------------------------------" <<endl;

// Memasukan nama bulan apa dan tahun berapa, untuk dicatat lalu disimpan kedalam file
    if(pilihMenu == 1){
        Keuangan data;
        cout << "\nSelamat Datang, Faiz! jangan lupa catat keuanganmu bulan ini!." << endl;

        cout << "Masukkan nama bulan (Contoh : Juni) : ";
        cin >> data.bulan;

        cout << "Masukkan tahun (Contoh : 2025) : ";
        cin >> data.tahun;
        
        cout << "Masukkan uang bulanan pada bulan " << data.bulan << " (Rp) : ";
        cin >> data.uangBulanan;

        cout << endl;

        int jumlahJenis;
        cout << "Masukan total jumlah jenis pengeluaran : ";
        cin >> jumlahJenis;

        data.ringkasanPengeluaran = " ";
        float totalPengeluaran = 0;

        for(int i = 0; i < jumlahJenis; i++){
            string jenis;
            float jumlah;

        cout << "Nama pengeluaran ke-" << i+1 << " : ";
        cin >> jenis;

        cout << "Jumlah pengeluaran pada [" << jenis << "] :Rp.";
        cin >> jumlah;

        totalPengeluaran += jumlah;
        stringstream ss;
        ss << fixed << setprecision(2) << jumlah;
        data.ringkasanPengeluaran += jenis + " : " + ss.str() + " ";
        }
        
        data.pengeluaranBulanan = totalPengeluaran;
        data.sisaBulanan = data.uangBulanan - data.pengeluaranBulanan;

        tampilkanRingkasan(data);
        menyimpanData(data);

// Menampilkan riwayat yang udah dimasukan pada catatan
    } else if (pilihMenu == 2){
        tampilkanRiwayat();

// Menghapus catat supaya kalau catat ditahun yang bagus bisa lebih terlihat rapih
    } else if (pilihMenu == 3){
        char konfirmasi;
        cout << "Anda yakin ingin menghapus SEMUA data keuangan? (yakin/tidak) : ";
        cin >> konfirmasi;
            
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        meresetDataKeuangan();
    } else {
        cout << "Konfirmasi batal." <<endl;
    }
    
// Akhir program
    } else if (pilihMenu == 4){
        cout << "Terima kasih sudah menggunakan pengelola keuangan." <<endl;
        break;
    } else {
        cout << "pilihan anda tidak valid, pilih yang 1-5 saja." <<endl;
    }
    cout <<endl;

    cout << "Apakah anda ingin memilih pilihan lain yang ada pada menu? (iya/tidak) : ";
    cin >> lanjutkan;

    } while (lanjutkan == 'y' || lanjutkan == 'Y');

    return 0;
}