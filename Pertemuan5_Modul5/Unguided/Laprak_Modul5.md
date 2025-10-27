# <h1 align="center">Laporan Praktikum Modul 5 -  SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Single Linked List merupakan struktur data linear dinamis yang terdiri dari rangkaian elemen bernama node, di mana setiap node menyimpan data dan satu pointer yang mengarah ke node berikutnya, sementara node terakhir menunjuk ke `null`. Berbeda dengan array yang memiliki alokasi memori kontigu, Singly Linked List mengalokasikan memori secara terpisah untuk setiap node, sehingga proses penyisipan dan penghapusan elemen dapat dilakukan tanpa perlu memindahkan seluruh data [1]. Kompleksitas waktu untuk operasi dasar seperti penyisipan atau penghapusan pada posisi awal bersifat O(1), sedangkan akses indeks acak memerlukan waktu O(n) karena harus melakukan traversal dari node pertama hingga node target [2]. Dengan sifat dinamisnya, struktur ini sering digunakan dalam pembelajaran dasar pemrograman untuk memperkenalkan konsep pointer dan manajemen memori dinamis [3].

Meski efisien untuk operasi penyisipan dan penghapusan, Singly Linked List memiliki kelemahan dalam efisiensi cache karena node-node-nya tersebar di lokasi memori yang berbeda. Hal ini menyebabkan cache miss lebih sering terjadi dibandingkan array yang disimpan secara berurutan [4]. Dalam implementasi praktis, array sering kali lebih cepat untuk operasi pembacaan berulang karena keunggulan spatial locality, sedangkan Singly Linked List lebih unggul pada situasi yang memerlukan banyak modifikasi elemen secara dinamis. Oleh karena itu, pemilihan struktur data ini bergantung pada kebutuhan aplikasi dan pola akses data yang digunakan. 

### A. Searching <br/>
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node
tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari
ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan
update akan lebih mudah.

#### 1. Binary search
Binary search adalah algoritma pencarian untuk menemukan sebuah elemen di dalam struktur data yang terurut (biasanya array atau list). Pada setiap langkah pencarian binary, ruang pencarian akan dibagi menjadi dua bagian, dan algoritma hanya akan melanjutkan pencarian pada salah satu bagian yang relevan, sehingga jumlah elemen yang harus diperiksa juga ikut berkurang.

#### 2. Linear search
Linear search adalah algoritma pencarian yang digunakan untuk menemukan elemen tertentu secara langsung pada sebuah koleksi data. Prinsip dasar dari linear search adalah memeriksa setiap elemen satu per satu dari awal hingga akhir hingga elemen yang dicari ditemukan atau seluruh elemen telah diperiksa tanpa perlu menyortir atau mengurutkan data terlebih dahulu.

## Guided

### 1. binary.cpp

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    
    else {
        Node* temp = head;
        while (temp->next) temp = temp-> next;
        temp->next = newNode;
    }
}

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) size++;
    Node* start = head;
    Node* end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        for (int i = 0; i < mid; i++) midNode = midNode->next;

        if (midNode->data == key) return midNode;
        if (midNode->data < key) {
            start = midNode->next;
        } else {
            end = midNode;
        }

        size -= mid;
    }

    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10); append (head, 20); append (head, 30); append (head, 40); append(head, 50);

    Node* result = binarySearch(head, 40);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Program yang menunjukkan algoritma binary search pada ADT di bahasa C++.

### 2. linear.cpp

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}
int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    Node* result = linearSearch(head, 20);

    cout << (result ? "Found: " : "Not Found") << endl;
    return 0;  
}
```
Program yang menampilkan implementasi algoritma linear search pada ADT dalam bahasa C++.

## Unguided

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int panjangList(Node* head) {
    int jum = 0;
    while (head) {
        jum++;
        head = head->next;
    }
    return jum;
}

Node* bacaList(Node* head, int index) {
    for (int i = 0; i < index && head; i++)
        head = head->next;
    return head;
}

Node* binarySearch(Node* head, int key) {
    int start = 0;
    int end = panjangList(head) - 1;
    int i = 1;

    cout << "\nProses Pencarian:\n";

    while (start <= end) {
        int mid = (start + end + 1) / 2;
        Node* midNode = bacaList(head, mid);

        cout << "Iterasi " << i << ": Mid = " << midNode->data << " (indeks tengah) ";

        if (midNode->data == key) {
            cout << "DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            cout << "Node berikutnya: " 
            << (midNode->next ? to_string(midNode->next->data) : string("NULL")) << endl;
            return midNode;
        }
        else if (midNode->data < key) {
            cout << "-> Cari di bagian kanan\n";
            start = mid + 1;
        }
        else {
            cout << "-> Cari di bagian kiri\n";
            end = mid - 1;
        }

        i++;
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    binarySearch(head, key1);

    int key2 = 25;
    cout << "\nMencari nilai: " << key2 << endl;
    binarySearch(head, key2);

    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan5_Modul5/Unguided/Output/output_no1.jpg)

Program ini menerapkan algoritma binary search pada struktur linked list untuk menemukan elemen tertentu, sambil menampilkan tahapan pencarian, posisi elemen tengah di setiap iterasi, serta hasil akhir yang mencakup alamat dan data node yang berhasil ditemukan.

### 2.  Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";

    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        cout << "Memeriksa node ke-" << index << " dengan nilai " << current->data;

        if (current->data == key) {
            cout << " (sama) - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            cout << "Node berikutnya: " << (current->next ? to_string(current->next->data) : string("NULL")) << endl;
            return current;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK ditemukan dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "LINEAR SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    int key1 = 30;
    cout << "Mencari nilai: " << key1 << endl;
    linearSearch(head, key1);

    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    linearSearch(head, key2);

    return 0;
}
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan5_Modul5/Unguided/Output/output_no2.jpg)

Program ini menerapkan algoritma linear search pada struktur linked list untuk mencari elemen tertentu, dengan menampilkan tahapan pemeriksaan tiap node serta hasil akhir yang mencakup alamat dan data node yang berhasil ditemukan.

## Kesimpulan
Berdasarkan hasil implementasi program, dapat disimpulkan bahwa linked list merupakan struktur data dinamis yang terdiri dari sekumpulan node yang saling terhubung melalui pointer. Setiap node menyimpan data serta alamat menuju node berikutnya, sehingga memungkinkan penambahan dan penghapusan elemen dilakukan dengan lebih fleksibel dibandingkan array. Pada percobaan ini, pembuatan linked list dilakukan menggunakan fungsi `append()`, yang menambahkan node baru di bagian akhir list. Untuk melakukan pencarian data, digunakan dua metode yaitu Linear Search dan Binary Search, masing-masing memiliki karakteristik dan keunggulannya tersendiri.

Linear Search bekerja dengan menelusuri setiap node secara berurutan dari awal hingga akhir hingga menemukan nilai yang dicari. Algoritma ini mudah diimplementasikan namun memiliki kompleksitas waktu O(n), sehingga kurang efisien untuk data berukuran besar. Sebaliknya, Binary Search diterapkan pada linked list yang terurut, dengan memanfaatkan fungsi `panjangList()` untuk mengetahui panjang list dan `bacaList()` untuk mengakses node di posisi tengah pada setiap iterasi pencarian. Hasil pengujian menunjukkan bahwa Binary Search dapat bekerja lebih efisien pada data yang terurut, meskipun implementasinya lebih kompleks dibandingkan Linear Search. Dengan demikian, pemilihan metode pencarian pada linked list perlu disesuaikan dengan kondisi data serta kebutuhan efisiensi program.

## Referensi
[1] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in Java. Wiley.
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[3] Parlante, N. (n.d.). Linked List Basics. Stanford University CS Education Library.
<br>[4] Sara, M. R. A. (2020). An Efficient Dynamic Array with Linked List Structure. Indonesian Journal of Computing. Telkom University.
