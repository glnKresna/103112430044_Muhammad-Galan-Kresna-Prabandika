#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void penjumlahan(int A[3][3], int B[3][3]){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Hasil penjumlahan: " << endl;
    tampilkanHasil(c); 
}
void pengurangan(int A[3][3], int B[3][3]){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Hasil pengurangan: " << endl;
    tampilkanHasil(c); 
}
void perkalian(int A[3][3], int B[3][3]){
    int c[3][3] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Hasil perkalian: " << endl;
    tampilkanHasil(c); 
}
int main() {
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            penjumlahan(arrA, arrB);
            break;
            case 2:
            pengurangan(arrA, arrB);
            break;
            case 3:
            perkalian(arrA, arrB);
            break;
        } 
    } while (pilihan != 4);

return 0;
}