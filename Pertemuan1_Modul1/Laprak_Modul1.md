# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
C++ merupakan bahasa Pemrograman Berorientasi Objek (Object-Oriented Programming) yang dikembangkan sebagai bagian dari keluarga bahasa C untuk memberikan developer tingkat kontrol yang lebih tinggi atas memori dan sumber daya sistem. Bahasa pemrograman ini menawarkan berbagai macam struktur data dan paradigma pemrograman yang bisa diimplementasikan untuk memenuhi kebutuhan spesifik suatu aplikasi atau memecahkan masalah dengan sistem tertentu[1]. Oleh karena itu, C++ menjadi bahasa yang populer digunakan untuk mengembangkan berbagai macam sistem seperti sistem operasi, sistem tertanam, video game, dan software lainnya[2].

Dalam praktikum ini, praktikan mempelajari penggunaan bahasa C++ untuk menjalankan operasi aritmatika sederhana[3], implementasi conditional statement atau percabangan[4], dan penerapan teknik perulangan atau looping. Hasil praktikum ditulis menggunakan bahasa C++ di dalam Visual Studio Code sebagai IDE.

### A. Dasar Pemrograman C++<br/>

#### 1. Struktur Program
Program C++ diinisasikan dengan memanggil library (`#include ...`) dan disusul dengan `int main() {}`.

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```
#### 2. Tipe Data
- `string`: kumpulan karakter/teks ("Hello", "World")
- `int`: bilangan bulat (-2,147,483,648 hingga 2,147,483,647)
- `float`: bilangan desimal (3.14, 2.0, -0.5, dsb.)
- `char`: karakter/huruf satuan (a, b, c, D, E, F, dsb.)
- `bool`: nilai boolean (TRUE/False)
#### 3. Operator Aritmatika
- `+` → penjumlahan
- `-` → pengurangan
- `*` → perkalian
- `/` → pembagian
- `%` → modulus (sisa hasil bagi)

#### 3. Operator Logika & Perbandingan
- `&&` → dan
- `||` → atau
- `==` → sama dengan
- `!=` → tidak sama dengan
- `>` → lebih besar
- `<` → lebih kecil
- `>=` → lebih besar atau sama dengan
- `<=` → lebih kecil atau sama dengan

### B. Input-Output<br/>

#### 1. `cin` (Input)
berfungsi untuk membaca masukan dari pengguna.
```C++
int n;
cin >> n;
```
#### 2. `cout` (Output)
berfungsi untuk memanggil dan menampilkan luaran program.
```C++
cout << n << endl;
```
### C. Percabangan (Conditional)<br/>

#### 1. If-Else Statement
Digunakan untuk menentukan perintah yang dijalankan berdasarkan kondisi tertentu.
```C++
if (n > 0) {
        cout << "Angka bernilai positif" << endl;
    } else {
        cout << "Angka bernilai negatif" << endl;
    }
```

#### 2. Switch-case
Digunakan untuk membuat menu atau opsi dengan pilihan ganda.
```C++
switch (pilihan) {
        case 1:
            cout << "Pilihan pertama" << endl;
            break;
        case 2:
            cout << "Pilihan kedua" << endl;
            break;
        case 3:
            cout << "Pilihan ketiga" << endl;
            break;
}
```

### C. Perulangan (Loop)<br/>

#### 1. For Loop
Digunakan jika iterasi diketahui.
```C++
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```

#### 2. While Loop
Digunakan saat perulangan bergantung dengan kondisi tertentu.
```C++
int j = 5;
while (j > 0) {
    cout << j << " ";
    j--;
}
```

#### 3. Do-While Loop
Menjalankan perintah minimal sekali sebelum melakukan pengecekan kondisi.
```C++
int k = 1;
do {
    cout << k << " ";
    k++;
} while (k <= 5);
```

## Guided 

### 1. Hello World

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello Wold"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
```
Program perkenalan sederhana yang memberikan keluaran berupa teks "Hello World".

### 2. Input-Output

```C++
#include<iostream>
using namespace std;

int main()
{
    int angka;
    cout << "masukkan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Program yang menunjukan penggunaan fungsi `cin` untuk membaca input dan `cout` untuk mengeluarkan output.

### 3. Operasi Aritmatika

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
    cout << "Hasil modulus: " << angka1 % angka2 << endl;
    
    return 0;
}
```
Program yang menunjukkan penggunaan operator aritmatika dan operasi aritmatika umum.

### 4. Percabangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << " kurang dari " << endl;
    } else if (angka1 < angka2) {
        cout << " lebih dari " << endl;
    }

    if (angka1 == angka2) {
        cout << " sama dengan " << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " ;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
        cout << "penjumlahan: " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "pilihan salah" << endl;
    }

    return 0;
}
```
Program yang menunjukkan penggunaan bentuk percabangan `if-else` dan `switch-case`.

### 4. Perulangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;
    
    for (int i = 1; i <= angka1; i++) {
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--;
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    }
```
Program yang mengimplementasikan teknik perulangan.

## Unguided 

### 1. Buatlah program yang menerima input-an dua bilangan bertipe float, kemudiaj memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan:" << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided1_modul1(1).jpg)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided1_modul1(2).jpg)

Program ini adalah kalkulator sederhana berbasis C++ yang meminta pengguna memasukkan dua angka. Program kemudian melakukan operasi aritmatika dasar yang terdiri dari penjumlahan, pengurangan, perkalian, dan pembagian, serta menampilkan hasilnya di layar. Program menggunakan tipe data `float` agar dapat menangani angka desimal.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input oleh user adalah bilangan bulat positif mulai dari 0 s.d. 100.

```C++
#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    string keHuruf (int n) {
        switch (n) {
            case 0: 
                return "nol";
            case 10: 
                return "sepuluh";
            case 11: 
                return "sebelas";
            case 100: 
                return "seratus";
        }

        if (n < 10) return satuan[n];
        if (n < 20) return satuan[n % 10] + " belas";
        if (n < 100) {
            string result = satuan[n / 10] + " puluh";
            if (n % 10 != 0) {
                result += " " + satuan[n % 10];
            }
            
            return result;
        }

        return "input melebihi batas";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    cout << keHuruf(n) << endl;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided2_modul1(1).jpg)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided2_modul1(2).jpg)

Program ini mengubah angka dari 0 hingga 100 menjadi bentuk teks. Pengguna memasukkan angka melalui `cin`, kemudian fungsi `keHuruf()` mengubah angka tersebut menjadi kata-kata dengan tipe data `string`. Program menggunakan `switch` untuk kasus khusus (0, 10, 11, 100) dan logika `if` untuk angka lain, termasuk belasan dan puluhan. Jika angka melebihi 100, program akan menampilkan pesan "input melebihi batas".

### 3. Buatlah program yang dapat memberikan input dan output sebagai berikut.

```C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided3_modul1(1).jpg)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan1_Modul1/Output/output_unguided3_modul1(2).jpg)

Program ini membuat pola piramida angka simetris dengan tanda `*` di tengah. Pengguna memasukkan sebuah angka `n`, yang menentukan tinggi piramida. Program menggunakan dua nested loop: Loop pertama menampilkan angka menurun di sebelah kiri `*`, Loop kedua menampilkan angka menaik di sebelah kanan `*`.

## Kesimpulan
Ketiga program tersebut memperlihatkan penggunaan dasar bahasa C++ untuk interaksi dengan pengguna, pengolahan data, dan kontrol alur program:
- Program operasi aritmatika sederhana Menunjukkan penggunaan `cin` dan `cout` untuk input-output, tipe data `float` untuk angka desimal, serta operasi aritmatika dasar (`+`, `-`, `*`, `/`).
- Program Konversi Angka ke Kata menunjukkan penerapan fungsi `switch-case` dan logika kondisional (`if`) untuk memetakan angka menjadi teks, serta penggunaan array `string` untuk menyimpan kata-kata numerik.
- Program Pola Piramida Angka menunjukkan penggunaan nested loop dan manipulasi spasi untuk mencetak pola angka di konsol, serta kombinasi perulangan menaik dan menurun untuk membentuk struktur simetris.

Secara keseluruhan, ketiga program ini menekankan konsep fundamental C++: input-output, tipe data, kontrol alur (conditional statements), fungsi, dan perulangan, yang menjadi dasar bagi pengembangan program yang lebih kompleks.

## Referensi
[1] Nugroho, A. Y., Sutanto, N. H. (2024). "Exploring the Code Foundation: A Literature Review of Data Structures in C++". Yogyakarta: International Journal of Mechanical, Industrial and Control Systems Engineering.
<br>[2] Aljas, J. M, Amores, H. A, Lincopinis, D. R. (2023). "An Overview on C++ Programming Language". Pagadian City: https://www.researchgate.net/publication/371166631.
<br>[3] Fathonia, G., Yahfizam, Y. (2024). "Analisis Studi Literatur Penyelesaian Operator Aritmatika Serta Bilangan
Bulat Dengan Code Sederhana Pada Bahasa Pemrograman C++". Medan: Jurnal Teknik Informatika, Sains dan Ilmu Komunikasi.
<br>[4] Nafiah, R., et al. (2020). "Bit Manipulation: Conditional Statement using
Bit-wise operators with C++". Yogyakarta: International Journal on Informatics for Development.
