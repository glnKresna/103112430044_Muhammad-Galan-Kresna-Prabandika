#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    string nama;
    string nim;
};

float nilaiAkhir(float nilai_tugas, float nilai_uts, float nilai_uas) {
    return (0.3 * nilai_tugas) + (0.3 * nilai_uts) + (0.4 * nilai_uas);
}

void dataMhs(Mahasiswa &mhs) {
    cout << "Masukkan nama         : ";
    cin >> mhs.nama;
    cout << "Masukkan NIM          : ";
    cin >> mhs.nim;
    cout << "Masukkan nilai tugas  : ";
    cin >> mhs.nilai_tugas;
    cout << "Masukkan nilai UTS    : ";
    cin >> mhs.nilai_uts;
    cout << "Masukkan nilai UAS    : ";
    cin >> mhs.nilai_uas;

    mhs.nilai_akhir = nilaiAkhir(mhs.nilai_tugas, mhs.nilai_uts, mhs.nilai_uas);
}

void tampilkanData(const Mahasiswa mhs[], int jumlah) {
    cout << "\nNo\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t"
            << mhs[i].nama << "\t\t"
            << mhs[i].nilai_akhir << endl;
    }
}

int main() {
    Mahasiswa list[10];
    int jumlah = 0;
    char lagi;

    do {
        if (jumlah >= 10) {
            cout << "\nTidak dapat menambah data lagi (maks. 10)\n";
            break;
        }

        cout << "Input data mahasiswa\n";
        dataMhs(list[jumlah]);
        jumlah++;

        cout << "Tambah data lagi? (y/t): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    tampilkanData(list, jumlah);
    return 0;
}
