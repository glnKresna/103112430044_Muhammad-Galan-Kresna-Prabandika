#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "Rata-rata nilai: " << rataMhs(mhs) << endl;

    system ("pause");
    return 0;
}