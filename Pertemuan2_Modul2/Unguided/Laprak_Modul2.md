# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Array adalah koleksi data dimana setiap elemen memakai nama yang sama dan bertipe sama dan setiap elemen diakses dengan membedakan indeks
arraynya[1]. Setiap rinci data disebut dengan elemen array. Matriks di dalam bahasa pemrograman seperti C++ dibentuk menggunakan array. Suatu matriks biasanya
diberi nama dengan huruf kapital dan ditulis tebal. Elemen-elemen matriks biasanya
diberi nama dengan huruf kecil yang sama dengan nama matriks tersebut disertai
2 indeks bawah yang menunjukkan letaknya di dalam matriks[2].

Sementara itu, pointer merupakan suatu variabel khusus yang menyimpan alamat memori sebuah variabel lain, bukan nilai data itu sendiri[3]. Dengan menggunakan pointer, data dapat diakses secara tidak langsung melalui alamat memori dari data tersebut, dan memungkinkan alokasi memori secara dinamis.

### A. Array <br/>

#### 1. Array Satu Dimensi
Array yang hanya terdiri dari satu larik data saja.

```C++
int nama_array[5];
```
#### 2. Array Dua Dimensi
Array yang terdiri atas dua indeks yang membentuk baris dan kolom, sehingga data terlihat seperti disimpan dalam sebuah tabel.

```C++
int nama_array[4][2];
array[2][0] = 10;
```

#### 3. Array Berdimensi Banyak
Array yang jumlah indeksnya lebih dari dua. Array berdimensi banyak sulit dibayangkan, sejalan dengan jumlah dimensi dalam array.

```C++
int nama_array[4][6][6];
```
### B. Pointer<br/>

#### 1. Pointer & Alamat
Pointer digunakan untuk menyimpan alamat memori dari variabel lain, sehingga pointer bisa mengakses nilai dari variabel yang alamatnya ditunjuk.
```C++
int *nama_ptr;
```
#### 2. Pointer & Array
Pointer memiliki keterhubungan yang kuat dengan array. Pointer bisa melakukan banyak operasi yang umumnya dilakukan oleh array.
```C++
int array[10];
int *ptr;
ptr = &array[0]; //Pointer menunjuk ke alamat dari elemen ke-0 dalam array
```
#### 3. Pointer & String
String sendiri sejatinya merupakan array yang terdiri dari sekumpulan karakter tunggal. Ketika karakter string tampil dalam sebuah program, maka digunakan pointer karakter untuk mengakses string ini
```C++
char *ptr_message;
ptr_message = "sudah waktunya"; //ptr_message menjadi pointer pada karakter array
```
### C. Fungsi <br/>

#### 1. Bentuk Umum
Fungsi merupakan blok kode yang dirancang untuk mengeksekusi tugas-tugas tertentu.
```C++
#include <iostream>
using namespace std;

//Badan fungsi
int tambah(int a, int b) {
    a = 1;
    b = 2;

    return a + b;
}

//Pendeklarasian variabel dan pemanggilan fungsi
int main() {}
```

### C. Prosedur<br/>

#### 1. Bentuk Umum
Prosedur adalah fungsi yang tidak mengembalikan nilai apapun. Dalam bahasa C++, prosedur dikenal sebagai fungsi void.
```C++
//Badan prosedur
void tulis (int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
}

//Prototipe fungsi
void tulis (int n) {
    int main() {}
}
```

### D. Parameter Fungsi<br/>

#### 1. Call by Value
Nilai dari parameter aktual akan disalin kedalam parameter formal.

```C++
int main() {
    int a, b; a = 4; b = 6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << endl;
}
```

#### 2. Call by Pointer
Variabel aktual diubah nilainya dengan cara melewatkan alamat variabel ke fungsi.

```C++
tukar (int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

tukar (&a, &b);
```

#### 3. Call by Reference
Mirip seperti Call by Pointer, nilai variabel aktual diubah dengan melewatkan alamat variabel ke fungsi.

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << ": ";
        cin >> arr[i];
    }

    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke-" << j << ": " << arr[j] << endl;
        j++;
    }

    return 0;
}
```
Program yang menampilkan bentuk dari array yang hanya memiliki satu larik.

### 2. Array Dua Dimensi

```C++
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
```
Program yang menampilkan bentuk dari array berdimensi dua.

### 3. Pointer dengan Array

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i + 1 << "menggunakan pointer: " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i + 1 << "menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
```
Program yang menunjukkan implementasi pointer pada array.

### 4. Call by Pointer

```C++
#include <iostream>
using namespace std;

void ubahNilai(int* ptr) {
    *ptr = 20;
}

int main() {
    int x = 10;
    cout << "Nilai sebelum diubah:" << x << endl;

    ubahNilai(&x);
    cout << "Nilai setelah diubah:" << x << endl;

    return 0;
}
```
Program yang menunjukkan implementasi Call by Pointer.

### 5. Call by Reference

```C++
#include <iostream>
using namespace std;

void tukar (int &x int &y);
int main() {
    int a, b;
    a = 4; b = 6
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << endl;
    return 0;
}


void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "nilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << endl;
}
```
Program yang mennunjukkan implementasi Call by Reference.
## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini :
matriksA = [7122231641151936] MatriksB = [113473254151833]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan2_Modul2/Unguided/Output/No1_Lat2_Mod2.jpg)

Program ini program ini menjalankan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 dengan elemen yang ditentukan. Program ini menggunakan switch-case untuk memberikan user opsi dalam memilih operasi aritmatika apa yang akan dilakukan pada matriks; opsi pertama melakukan penjumlahan matriks, opsi kedua pengurangan matriks, opsi ketiga perkalian matriks, dan opsi keempat yang menyelesaikan program.

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah.

```C++
#include <iostream>
using namespace std;

void ubahPanjangLebar(int& Panjang, int& Lebar) {
    Panjang = 12;
    Lebar = 6;
}
int main (){
    int panjang = 10, lebar = 5, luas = 0;
    int keliling;
    cout << "--- Nilai awal---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    luas = panjang * lebar;
    keliling = 2 * (panjang + lebar);

    cout << "---Hasil Perhitungan---" << endl;
    cout << "Luas: " << luas << endl;
    cout << "Keliling: " << keliling << endl;

    ubahPanjangLebar(panjang, lebar);

    luas = panjang * lebar;
    keliling = 2 * (panjang + lebar);

    cout << "---Nilai Setelah Diubah---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "lebar: " << lebar << endl;
    cout << "Luas: " << luas << endl;
    cout << "Keliling: " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan2_Modul2/Unguided/Output/No1_Lat2_Mod2.jpg)

Program ini dibuat untuk menghitung luas dan keliling sebuah persegi panjang dengan nilai panjang dan lebar tertentu. Panjang awalnya bernilai 10 dengan lebar bernilai 5, kemudian program menampilkan nilai awal tersebut sekaligus hasil perhitungan luas dan kelilingnya. Setelah itu, program memanggil fungsi `ubahPanjangLebar` yang menggunakan konsep Passing by Reference untuk mengubah nilai panjang menjadi 12 dan lebar menjadi 6.

## Kesimpulan
Modul ini membahas lebih dalam mengenai dasar-dasar pemrograman C++, khususnya penggunaan variabel, tipe data, operator, fungsi, serta mempertegas ulang konsep dasar alur kontrol seperti percabangan dan perulangan. Modul ini menekankan pentingnya pemahaman struktur program C++ untuk menulis kode yang sistematis, efisien, dan mudah dipahami.

## Referensi
[1] Andri, K. (2003). "Algoritma pemrograman C++". Bandung: Graha Ilmu.
<br>[2] Putra, E.P., Bima, W.E. (2025). "DASAR LOGIKA PEMROGRAMAN DENGAN C++". Semarang: SIEGA Publisher.
<br>[3] Hamed, T. (2021). "Pointers in C++." University of Mosul.
