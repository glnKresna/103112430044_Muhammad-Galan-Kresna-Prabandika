#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char NIM[10];
    int nila1, nilai2;
};

void inputMhs(mahasiswa &m);
float rataMhs(mahasiswa m);

#endif