#include <iostream>
using namespace std;

int pangkat_2(int x) {
    if (x = 0) {
        return 1;
    } else if (x > 0) {
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "Menghitung x^y" << endl;
    int x;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah: " << pangkat_2(x) << endl;

    return 0;
}