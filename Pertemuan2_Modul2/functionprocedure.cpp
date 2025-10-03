#include <iostream>
using namespace std;

int cariMAX (int arr[], int ukuran) {
    int MAX = arr[0];

    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }

    return MAX;
}

void operasiAritmatika (int arr[], int ukuran) {
    int jumlah = 0;

    for (int i = 0; i < ukuran; i++) {
        jumlah += arr[i];
    }
    cout << "total penjumlahan: " << jumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian: " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];

    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai array ke-" << i << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Nilai terbesar dalam array: " << cariMAX(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    
    return 0;
}