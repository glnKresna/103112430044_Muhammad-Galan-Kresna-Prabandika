# <h1 align="center">Laporan Praktikum Modul 3 -  ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan konsep fundamental dalam pemrograman yang menjelaskan bagaimana sebuah tipe data didefinisikan berdasarkan nilai-nilai yang dapat ditampung serta operasi-operasi yang dapat dilakukan terhadapnya, tanpa harus memperhatikan bagaimana data tersebut disimpan atau diimplementasikan secara fisik di memori. ADT dapat dianggap sebagai sistem yang mendefinisikan hubungan antara operasi dan objek melalui seperangkat aksioma atau aturan yang memastikan konsistensi dan keakuratan operasi data[1]. 

Dalam konteks yang lebih praktis, ADT juga dapat diterapkan pada sistem basis data berorientasi objek untuk memperluas kemampuan tipe data tradisional. Dengan menggunakan ADT, pengembang dapat menambahkan perilaku baru pada tipe data tanpa mengubah sistem inti, menunjukkan fleksibilitas tinggi dari pendekatan ini[2]. Selain itu, ADT juga memungkinkan perancangan program yang lebih terstruktur karena setiap tipe data memiliki spesifikasi operasi yang jelas dan dapat diuji kebenarannya secara matematis[3]. 

### A. Abstract Data Type <br/>

ADT adalah Type dan sekumpulan Primitif (operasi dasar) terhadap Type tersebut. Selain itu, dalam
sebuah ADT yang lengkap, disertakan pula definisi invarian dari Type dan aksioma yang berlaku. ADT
merupakan definisi statik.

ADT biasanya diimplementasikan menjadi dua buah modul utama dan 1 modul interface program
utama (driver). Dua modul tersebut adalah sebagai berikut:

#### 1. Definisi Type dan Primitif/Header fungsi (.h)
- Spesifikasi Type sesuai dengan kaidah bahasa yang dipakai
- Spesifikasi dari Primitif sesuai dengan kaidah dalam konteks prosedural, yaitu Fungsi (nama, domain, range, prekondisi) dan Prosedur (: Initial state, Final state, proses)

#### 2. Body/realisasi dari primitif (.c)
Berupa kode program dalam bahasa pemrograman (dalam praktikum ini berarti dengan bahasa
C++). Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan selector dan konstruktor.

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    char nim[10];:
    int nilail,nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m)

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata " == Y rata2(mhs);
    return 0;
}

void inputMhs (mahasiswa &m) {
    cout << "input nama = ";
    cin >> m.nim;
    cout << "input nilai = ";
    cin >> m.nilail;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2 (mahasiswa m) {
    return float(m.nilail+m.nilai2) / 2
}
```

## Guided 

### 1. mahasiswa.h

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char NIM[10];
    int nila1, nilai2;
};

void inputMhs(mahasiswa &m);
float rataMhs(mahasiswa m);

#endif
```
Header file C++ yang mendefinisikan ADT `mahasiswa`.

### 2. mahasiswa.cpp

```C++
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
```
Program yang menampilkan implementasi dari fungsi-fungsi ADT `mahasiswa` yang dideklarasikan di file header `mahasiswa.h`.

### 3. main.cpp

```C++
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
```
Program utama yang menggunakan ADT `mahasiswa`.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    float nilai_tugas;
    float nilai_uts;
    float nilai_uas;
    float nilai_akhir;
    string nama;
    string nim;
};

float nilaiAkhir(float nilai_tugas, float nilai_uts, float nilai_uas) {
    return (0.3 * nilai_tugas) + (0.3 * nilai_uts) + (0.4 * nilai_uas);
}

void dataMhs(Mahasiswa &mhs) {
    cout << "Masukkan nama         : ";
    cin >> mhs.nama;
    cout << "Masukkan NIM          : ";
    cin >> mhs.nim;
    cout << "Masukkan nilai tugas  : ";
    cin >> mhs.nilai_tugas;
    cout << "Masukkan nilai UTS    : ";
    cin >> mhs.nilai_uts;
    cout << "Masukkan nilai UAS    : ";
    cin >> mhs.nilai_uas;

    mhs.nilai_akhir = nilaiAkhir(mhs.nilai_tugas, mhs.nilai_uts, mhs.nilai_uas);
}

void tampilkanData(const Mahasiswa mhs[], int jumlah) {
    cout << "\nNo\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" << mhs[i].nim << "\t"
            << mhs[i].nama << "\t\t"
            << mhs[i].nilai_akhir << endl;
    }
}

int main() {
    Mahasiswa list[10];
    int jumlah = 0;
    char lagi;

    do {
        if (jumlah >= 10) {
            cout << "\nTidak dapat menambah data lagi (maks. 10)\n";
            break;
        }

        cout << "Input data mahasiswa\n";
        dataMhs(list[jumlah]);
        jumlah++;

        cout << "Tambah data lagi? (y/t): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    tampilkanData(list, jumlah);
    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan3_Modul3/Unguided/Output/soal1_output.jpg)

Kode di atas merupakan program C++ untuk menyimpan dan menampilkan data mahasiswa menggunakan konsep ADT. Struktur `Mahasiswa` berfungsi sebagai ADT yang menyimpan data berupa nama, NIM, serta nilai tugas, UTS, UAS, dan nilai akhir. Fungsi `nilaiAkhir()` digunakan untuk menghitung nilai akhir mahasiswa berdasarkan rumus `0.3 * tugas + 0.3 * uts + 0.4 * uas`. Prosedur `dataMhs()` bertugas menginput data mahasiswa, kemudian langsung menghitung nilai akhirnya. Prosedur `tampilkanData()` menampilkan daftar seluruh mahasiswa beserta nilai akhirnya dalam bentuk tabel sederhana.

### 2.  Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
Type pelajaran <
namaMapel : string kodeMapel : string
function create_pelajaran( namapel : string, kodepel: string ) → pelajaran
procedure tampil_pelajaran(input pel: pelajaran)

- pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampilkan_pelajaran(pelajaran pel);

#endif
```

- pelajaran.cpp
```C++
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
```

- main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampilkan_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan3_Modul3/Unguided/Output/soal2_output.jpg)

Ketiga program diatas merupakan penerapan ADT dengan contoh output nama dan kode mata pelajaran. ADT disimpan dan dideklarasikan dalam file `pelajaran.h`, diimplementasikan dalam file `pelajaran.cpp` sebelum akhirnya bisa dieksekusi di dalam file `main.cpp`.

### 3.  Buatlah program dengan ketentuan:
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer

```C++
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
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan3_Modul3/Unguided/Output/soal3_output.jpg)

Kode di atas adalah program C++ yang menggunakan array 2 dimensi dan pointer, serta menerapkan fungsi untuk menampilkan dan menukar nilai. Fungsi `arrDuaDimensi()` digunakan untuk menampilkan isi sebuah array 2D berukuran 3×3. Fungsi `tukarElemen()` berfungsi untuk menukar nilai antara dua array 2D pada posisi tertentu (baris, kolom). Fungsi `tukarPointer()` digunakan untuk menukar nilai yang ditunjuk oleh dua pointer integer.

## Kesimpulan
Dari modul ini, dapat disimpulkan bahwa ADT merupakan konsep penting dalam pemrograman yang memisahkan antara spesifikasi dan implementasi suatu struktur data. Melalui ADT, programmer dapat mendefinisikan tipe data beserta operasi-operasinya tanpa harus memperhatikan bagaimana data tersebut direpresentasikan di memori. Pendekatan ini meningkatkan abstraksi, modularitas, dan kemudahan pemeliharaan program.

## Referensi
[1] Jouannaud, J. P., Okada, M. (1997). Abstract Data Type Systems. Theoretical Computer Science, 173(2), 349-391.
<br>[2] Astesiano, E., Reggio, G., & Tarlecki, A. (1955). Recent Trends in Data Type Specification (ADT COMPASS 1994).
<br>[3] Seshadri, P., et al. (1998). Enhanced abstract data types in object-relational databases. The VLDB Journal, 7(2), 130-140.
