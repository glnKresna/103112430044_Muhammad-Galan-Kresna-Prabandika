# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Queue merupakan salah satu struktur data linear yang beroperasi berdasarkan prinsip First In, First Out (FIFO), di mana elemen yang pertama masuk akan menjadi elemen pertama yang keluar. Struktur data ini memainkan peran penting dalam pengaturan aliran data secara berurutan, terutama pada sistem operasi, manajemen request server, penjadwalan proses, serta berbagai mekanisme buffer. Queue merupakan bagian fundamental dalam manajemen proses karena mendukung operasi sederhana namun kritis dalam penanganan data secara terstruktur, serta dapat diimplementasikan menggunakan array, linked list, maupun library standar seperti `std::queue` guna mempermudah pengelolaan memori dan operasi dasar antrian[1]. Struktur data linear seperti queue merupakan fondasi penting dalam membangun sistem perangkat lunak yang efisien dan modular, mengingat penggunaannya yang luas dalam kontrol aliran program, pemrosesan data beruntun, dan pemecahan masalah komputasi yang membutuhkan keteraturan tinggi[2].

Secara teknis, operasi utama pada queue meliputi `enqueue` (menambahkan elemen), `dequeue` (menghapus elemen), serta pemeriksaan kondisi `isEmpty` dan `isFull` yang memastikan konsistensi terhadap prinsip FIFO. Variasi implementasi seperti linear queue, dynamic queue, dan circular queue memberikan fleksibilitas dalam pengelolaan memori dan efisiensi akses. Circular queue, misalnya, memungkinkan pemanfaatan ruang array secara melingkar sehingga tidak memerlukan proses shifting seperti pada linear queue.

### A. Pengertian Queue
Secara umum, implementasi queue dengan array memiliki prinsip kerja yang sama seperti penggunaan pointer. Perbedaannya terletak pada cara pengelolaan memori serta batas kapasitas antrian yang bersifat tetap pada struktur berbasis array. Ada beberapa macam-macam bentuk queue, yaitu:

#### 1. Head diam, Tail bergerak
Algoritma paling dasar untuk menambahkan elemen ketika ruang masih tersedia adalah dengan menggeser posisi TAIL ke depan. Pada kondisi khusus ketika Queue masih kosong, nilai HEAD perlu diinisialisasi ke posisi 1.

Untuk proses penghapusan, pendekatan sederhana—meskipun cukup naif—adalah mengambil elemen pada posisi HEAD, lalu menggeser seluruh elemen dari indeks HEAD+1 hingga TAIL (jika ada), kemudian mengurangi nilai TAIL. Pada kasus Queue yang hanya memiliki satu elemen, HEAD dan TAIL harus dikembalikan ke nilai sesuai definisi awal. Metode ini menyerupai situasi antrean di dunia nyata di mana setiap orang bergerak maju, namun cara ini tidak efektif dari sisi komputasi.

#### 2. Head bergerak, Tail bergerak
HEAD dan TAIL, HEAD “bergerak” ketika sebuah elemen dihapus jika Queue tidak kosong. Jika Queue kosong, maka HEAD=0. Ilustrasi Queue tidak kosong, dengan 5 elemen, kemungkinan pertama HEAD“sedang berada di posisi awal. Proses penambahan elemen pada alternatif ini serupa dengan bentuk 1, yaitu dengan menggeser TAIL ke depan selama ruang masih tersedia. Pada kondisi khusus ketika Queue masih kosong, HEAD perlu diinisialisasi ke posisi 1. Dengan demikian, prosedur penambahannya pada dasarnya tidak berbeda dari bentuk 1.

Untuk penghapusan elemen, selama Queue tidak kosong, langkah yang dilakukan adalah mengambil nilai pada HEAD, lalu memajukan posisi HEAD. Jika Queue awalnya hanya berisi satu elemen, maka HEAD dan TAIL harus dikembalikan ke nilai awal sesuai definisi.

#### 3. Head dan Tail berputar (circular)
Pada proses penambahan elemen, TAIL digeser maju selama masih tersedia ruang. Namun, apabila TAIL telah berada di posisi IdxMax, maka indeks berikutnya kembali ke 1, sehingga nilai TAIL yang baru menjadi 1. Jika TAIL belum mencapai IdxMax, mekanisme penambahannya sama seperti pada bentuk 2. Untuk kondisi khusus ketika Queue masih kosong, HEAD perlu diinisialisasi ke posisi 1.

Pada proses penghapusan elemen, selama Queue tidak kosong, nilai pada HEAD diambil lalu HEAD digeser maju. Penentuan indeks berikutnya dilakukan dengan aturan yang sama seperti pada operasi penambahan: jika HEAD mencapai IdxMax, maka posisi selanjutnya kembali ke 1. Jika Queue semula hanya berisi satu elemen, maka HEAD dan TAIL harus dikembalikan sesuai definisi awal. Pendekatan ini jauh lebih efisien karena tidak memerlukan pergeseran elemen, dan teknik seperti ini umumnya dikenal sebagai “circular buffer”, di mana array dianggap berputar sebagai sebuah buffer.

Salah satu variasi dari representasi pada bentuk queue 3 adalah mengganti TAIL dengan COUNT, yaitu jumlah elemen dalam Queue. Dengan cara ini, banyaknya elemen dapat diketahui secara langsung, meskipun perhitungan TAIL tetap perlu dilakukan saat menambah elemen. Pendekatan ini bisa dijadikan latihan untuk diuji coba lebih lanjut.

### B. Operasi dalam Queue <br/>

#### 1. Enqueue (insert)
Operasi penyisipan selalu dilakukan pada akhir (tail).

#### 2. Dequeue (delete)
Operasi delete dilakukan pada awal (head).


### C. Primitif dalam Queue
- `createQueue()`
- `isEmpty()`
- `isFull()`
- `alokasi()`
- `dealokasi()`
- Fungsi – fungsi pencarian
Seperti halnya pada model list yang lain, primitif-primitifnya tersimpan pada file `*.c`dan file `*.h`

## Guided 1

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```

### 2. queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        int deletedValue = nodeHapus->dataAngka;
        dealokasi(nodeHapus);
        cout << "node " <<  deletedValue << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);


    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah dequeue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}
```

Program ini mengimplementasikan queue untuk pencarian data.

## Guided 2

### 1. queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### 2. queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

### 3. main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\nEnqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\nDequeue 1 elemen" << endl;
    cout << "Dequeued: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini mengimplementasikan queue utuk membuat antrian.

## Unguided

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
```
Type infotype: integer
Type Queue: <
    info : array [5] of infotype {index array dalam C++
    dimulai dari 0}
    head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queue) → infotype
procedure printInfo (input Q: Queue)
```

Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 1 (head diam, tail bergerak).
```
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

- queue.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1; 
}

bool isEmpty(Queue Q) {
    return (Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[0] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[0];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i+1];
    }
    Q.tail--;

    if (Q.tail == -1) {
        Q.head = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = 0; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

- main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info"   << endl;
    cout << "----------------------" << endl;

    printInfo(Q);

    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q);   printInfo(Q);
    dequeue(Q);   printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan8_Modul8/Unguided/Output/output_no1.jpg)

### 2.  Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

- queue.cpp
```C++
void enqueue(Queue &Q, infotype x) {
    if (isFull(Q) && Q.head > 0) {

        int j = 0;
        for (int i = Q.head; i <= Q.tail; i++) {
            Q.info[j] = Q.info[i];
            j++;
        }
        Q.tail = Q.tail - Q.head;
        Q.head = 0;
    }

    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = 0;
        Q.tail = -1;
    }

    return x;
}
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan8_Modul8/Unguided/Output/output_no2.jpg)

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

- queue.cpp
```C++
bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
        return;
    }

    Q.tail = (Q.tail + 1) % MAX;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
        return x;
    }

    Q.head = (Q.head + 1) % MAX;
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
```


### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan8_Modul8/Unguided/Output/output_no3.jpg)

## Kesimpulan
Queue merupakan struktur data linear yang bekerja dengan prinsip First In, First Out (FIFO) sehingga elemen yang pertama masuk menjadi elemen pertama yang keluar. Alternatif 1 (head tetap, tail bergerak) mudah diimplementasikan namun kurang efisien karena membutuhkan pergeseran elemen saat `dequeue`. Alternatif 2 meningkatkan efisiensi dengan menggerakkan head dan tail bersama-sama, meskipun masih memungkinkan terjadinya kondisi penuh semu. Alternatif 3, yaitu circular queue, menjadi pendekatan paling optimal karena head dan tail bergerak secara melingkar sehingga memaksimalkan penggunaan ruang array tanpa perlu shifting.

## Referensi
[1] Mpolo, T. (2025). Understanding and Implementing Queues in C++.
<br>[2] Nugroho, A. Y., Sutanto, N. H. (2024). Exploring the Code Foundation: A Literature Review of Data Structures in C++. International Journal of Mechanical, Industrial and Control Systems Engineering 1(3)