#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        address cek = findElm(L, x.nopol);
        if (cek != Nil) {
            cout << "nomor polisi sudah terdaftar\n\n";
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;

            address P = alokasi(x);
            insertLast(L, P);
            cout << endl;
        }
    }

    printInfo(L);

    string cariNopol;
        cout << "\nMasukkan Nomor Polisi yang dicari : ";
        cin >> cariNopol;

        address Q = findElm(L, cariNopol);
        if (Q != Nil) {
            cout << "\nNomor Polisi : " << Q->info.nopol << endl;
            cout << "Warna        : " << Q->info.warna << endl;
            cout << "Tahun        : " << Q->info.thnBuat << endl;
        } else {
            cout << "\nData tidak ditemukan.\n";
        }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    if (findElm(L, hapusNopol) != Nil) {
        deleteByNopol(L, hapusNopol);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}