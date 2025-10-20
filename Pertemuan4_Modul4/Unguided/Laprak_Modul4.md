# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST (BAGIAN PERTAМА)</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Single Linked List merupakan struktur data linear dinamis yang terdiri dari rangkaian elemen bernama node, di mana setiap node menyimpan data dan satu pointer yang mengarah ke node berikutnya, sementara node terakhir menunjuk ke `null`. Berbeda dengan array yang memiliki alokasi memori kontigu, Singly Linked List mengalokasikan memori secara terpisah untuk setiap node, sehingga proses penyisipan dan penghapusan elemen dapat dilakukan tanpa perlu memindahkan seluruh data [1]. Kompleksitas waktu untuk operasi dasar seperti penyisipan atau penghapusan pada posisi awal bersifat O(1), sedangkan akses indeks acak memerlukan waktu O(n) karena harus melakukan traversal dari node pertama hingga node target [2]. Dengan sifat dinamisnya, struktur ini sering digunakan dalam pembelajaran dasar pemrograman untuk memperkenalkan konsep pointer dan manajemen memori dinamis [3].

Meski efisien untuk operasi penyisipan dan penghapusan, Singly Linked List memiliki kelemahan dalam efisiensi cache karena node-node-nya tersebar di lokasi memori yang berbeda. Hal ini menyebabkan cache miss lebih sering terjadi dibandingkan array yang disimpan secara berurutan [4]. Dalam implementasi praktis, array sering kali lebih cepat untuk operasi pembacaan berulang karena keunggulan spatial locality, sedangkan Singly Linked List lebih unggul pada situasi yang memerlukan banyak modifikasi elemen secara dinamis. Oleh karena itu, pemilihan struktur data ini bergantung pada kebutuhan aplikasi dan pola akses data yang digunakan. 

### A. Single Linked List <br/>

Single linked list merupakan model ADT Linked list yang hanya memiliki satu arah pointer. Single linked list hanya membutuhkan satu buah pointer dengan node akhir yang menunjuk ke Nil (kecuali untuk list circular). Single linked list hanya dapat melakukan pembacaan maju dan pencarian sekuensial jika data tidak terurut.

#### 1. Pembentukan komponen-komponen list
- Pembentukan list: list baru dibentuk dengan fungsi yang biasanya bernama `createList()`. Fungsi ini akan mengatur nilai awal list, yaitu first(list) dan last(list) dengan nilai Nil.
- Alokasi memori: memori dialokasikan untuk setiap elemen yang ada dalam list. Fungsi yang biasanya digunakan adalah `alokasi()`.
- Dealokasi memori: memori yang telah dialokasikan juga bisa dihapus dengan sintaks `delete p;`.
- Pengecekan list: isi list bisa dicek dengan fungsi `isEmpty`. List akan mengembalikan nilai `true` jika kosong dan `false` jika tidak kosong.

#### 2. Insert
- Insert First: metode memasukkan elemen ke dalam list yang diletakkan pada awal list.

```C++
void insertFirst(List &L, address &P) {
P.next = L.first
L.first = P;
}
```

- Insert Last: metode memasukkan elemen data ke dalam list yang diletakkan pada akhir list.

```C++
void insertFirst(List &L, address &P) {
P.next = null
L.first = P;
}
```

- Insert After: metode memasukkan data ke dalam list yang diletakkan setelah node tertentu yang ditunjuk oleh user.

#### 3. View
Merupakan operasi dasar pada list yang menampilkan isi node/simpul dengan suatu penelusuran list. Mengunjungi setiap node kemudian menampilkan data yang tersimpan pada node tersebut.

## Guided 1

### 1. list.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 
typedef struct node *address; 

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist { 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Header file C++ yang mendefinisikan ADT `list`.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
Program yang menampilkan implementasi dari fungsi-fungsi ADT `list.h`.

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program utama yang menggunakan ADT `list`.

## Guided 2

## 1. list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 
typedef struct node *address; 

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
Header file C++ yang mendefinisikan ADT `list`.

### 2. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil) {
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```
Program yang menampilkan implementasi dari fungsi-fungsi ADT `list.h`.

### 3. main.cpp

```C++
#include "list.h"
#include<iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program utama yang menggunakan ADT `list`.


## Unguided

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”.

- `singlylist.h`
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

- `singlylist.cpp`
```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

- `main.cpp`
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan4_Modul4/Unguided/Output/output_no1.jpg)

Program ini menampilkan penerapan modularisasi pada Singly Linked List dengan pemisahan file header (.h) dan implementasi (.cpp). Struktur `ElmList` menyimpan data bertipe `int` dan pointer ke elemen berikutnya, sedangkan `List` menampung alamat elemen pertama. Fungsi `createList` membuat list kosong, `alokasi` membuat node baru, `insertFirst` menambahkan node di awal list, dan `printInfo` menampilkan seluruh data. Di `main`, program membuat list baru, menambahkan data (9, 12, 8, 0, 2), lalu menampilkannya. Program ini memperlihatkan proses pembuatan, penambahan, dan penampilan data menggunakan konsep modularisasi di C++.

### 2.  Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

- main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P;
    createList(L);

    int data[] = {2, 0, 8, 12, 9};
    for (int i = 0; i < 5; i++)
        insertFirst(L, alokasi(data[i]));

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L.first, P);
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan4_Modul4/Unguided/Output/output_no2.jpg)

Pada program ini, struktur `ElmList` menyimpan data bertipe `int` dan pointer ke elemen berikutnya, sedangkan `List` menampung alamat elemen pertama. Di `main`, program membuat list baru, menambahkan data (9, 12, 8, 0, 2) menggunakan `insertFirst`, lalu melakukan penghapusan node, menampilkan jumlah node, dan menghapus seluruh elemen. Secara keseluruhan, program ini memperlihatkan proses pembuatan, penambahan, penghapusan, dan penampilan data dalam Singly Linked List menggunakan konsep modularisasi di C++.

## Kesimpulan
Pada program pertama, yaitu Singly Linked List versi dasar, konsep Abstract Data Type (ADT) diterapkan untuk merepresentasikan struktur data berbentuk daftar berantai yang menyimpan elemen-elemen bertipe integer. Program ini menyediakan operasi dasar seperti penambahan dan penampilan data, yang menjadi fondasi dari manipulasi data dalam struktur list. Melalui pendekatan ini, setiap elemen terhubung menggunakan pointer, sehingga memungkinkan penyimpanan data secara dinamis tanpa batasan ukuran tetap. Implementasi ini juga menggambarkan bagaimana ADT dapat menyembunyikan detail teknis struktur data dan memberikan antarmuka sederhana bagi pengguna untuk berinteraksi dengan list.

Sementara itu, pada program kedua, konsep dasar tersebut dikembangkan lebih lanjut dengan menambahkan berbagai operasi seperti penghapusan elemen menggunakan fungsi `deleteFirst`, `deleteLast`, dan `deleteAfter`, serta fitur untuk menghitung jumlah elemen dalam list. Penambahan fungsi-fungsi ini menunjukkan kemampuan ADT dalam mengelola data secara lebih kompleks dan fleksibel. Selain itu, penerapan modularisasi melalui pemisahan file header, implementasi, dan file utama menegaskan pentingnya pemisahan tanggung jawab dalam pemrograman. Dengan demikian, pengguna cukup memahami fungsi-fungsi yang tersedia tanpa perlu mengetahui detail implementasinya. Secara keseluruhan, kedua program ini menggambarkan bagaimana penerapan ADT dalam C++ mendukung pengembangan struktur data yang terorganisir, mudah dipelihara, dan efisien dalam pengelolaan data dinamis.

## Referensi
[1] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in Java. Wiley.
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
<br>[3] Parlante, N. (n.d.). Linked List Basics. Stanford University CS Education Library.
<br>[4] Sara, M. R. A. (2020). An Efficient Dynamic Array with Linked List Structure. Indonesian Journal of Computing. Telkom University.
