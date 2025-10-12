#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampilkan_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran      : " << pel.namaMapel << endl;
    cout << "Nilai               : " << pel.kodeMapel << endl;
}
