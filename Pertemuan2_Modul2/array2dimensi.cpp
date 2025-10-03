#include <iostream>
using namespace std;

void tampilkanHasil (int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };

    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };

    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan: " << endl;
    tampilkanHasil(arrC);

    cout << "Hasil Pengurangan: " << endl;
    tampilkanHasil(arrD);

    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrD[i][j] += arrA[i][j] * arrB[i][j];
        }
    }

    cout << "Hasil Perkalian: " << endl;
    tampilkanHasil(arrD);

    return 0;
}