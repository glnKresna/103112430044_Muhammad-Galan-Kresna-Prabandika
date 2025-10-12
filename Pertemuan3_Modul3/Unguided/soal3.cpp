#include <iostream>
using namespace std;

void arrDuaDimensi(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *ptr1, *ptr2;
    int x = 100, y = 200;

    ptr1 = &x;
    ptr2 = &y;

    cout << "Sebelum pertukaran: " << endl;
    arrDuaDimensi(A);
    arrDuaDimensi(B);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl << endl;

    tukarElemen(A, B, 1, 1);

    tukarPointer(ptr1, ptr2);

    cout << "Setelah pertukaran: " << endl;
    arrDuaDimensi(A);
    arrDuaDimensi(B);
    cout << "Pointer 1: " << *ptr1 << ", Pointer 2: " << *ptr2 << endl;

    return 0;
}
