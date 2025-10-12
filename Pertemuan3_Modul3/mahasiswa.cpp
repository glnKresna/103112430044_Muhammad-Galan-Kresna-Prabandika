#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.NIM;
    cout << "Input nilai 1: ";
    cin >> m.nila1;
    cout << "Input nilai 2: ";
    cin >> m.nilai2;
}

float rataMhs(mahasiswa m) {
    return (float)(m.nila1 + m.nilai2) / 2;
}