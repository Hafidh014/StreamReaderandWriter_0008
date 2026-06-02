#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    TokoElektronik() {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }


    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!"
            );
        }
    }
};


const string FILE_GUDANG = "gudang.txt";


vector<string> bacaData() {
    vector<string> data;
    ifstream file(FILE_GUDANG);

    string barang;
    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();
    return data;
}


void tampilkanBarang() {
    vector<string> data = bacaData();

    cout << "\n===== DAFTAR BARANG GUDANG =====\n";

    if (data.empty()) {
        cout << "Gudang masih kosong.\n";
        return;
    }

    for (size_t i = 0; i < data.size(); i++) {
        cout << i + 1 << ". " << data[i] << endl;
    }
}


void tambahBarang() {
    ofstream file(FILE_GUDANG, ios::app);

    string barang;
    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;
    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}


void updateBarang() {
    vector<string> data = bacaData();

    if (data.empty()) {
        cout << "Tidak ada data untuk diubah.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore();

    string barangBaru;
    cout << "Masukkan nama barang baru : ";
    getline(cin, barangBaru);

    data[nomor - 1] = barangBaru;

    ofstream file(FILE_GUDANG);

    for (string barang : data) {
        file << barang << endl;
    }

    file.close();

    cout << "Data berhasil diperbarui.\n";
}


void hapusBarang() {
    vector<string> data = bacaData();

    if (data.empty()) {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang akan dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + (nomor - 1));

    ofstream file(FILE_GUDANG);

    for (string barang : data) {
        file << barang << endl;
    }

    file.close();

    cout << "Data berhasil dihapus.\n";
}

void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";


    try {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang ditemukan : "
        << toko.ambilProduk(1) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }


    try {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang ditemukan : "
        << toko.ambilProduk(5) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n=====================================\n";
        cout << " SISTEM MANAJEMEN TOKO GIBRAN JAYA\n";
        cout << "=====================================\n";

        tampilkanBarang();

        cout << "\nMenu:\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang (Update)\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilkanBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}