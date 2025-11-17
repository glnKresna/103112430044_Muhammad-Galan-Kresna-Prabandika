# <h1 align="center">Laporan Praktikum Modul 7 -  STACK</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Stack adalah salah satu struktur data linier yang bekerja dengan prinsip LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Struktur ini hanya mengizinkan pengaksesan data pada satu ujung, yaitu bagian atas (top), sehingga operasi utamanya terdiri dari `push` (menambah elemen ke stack) dan `pop` (menghapus elemen dari stack). Selain itu, stack juga mendukung operasi `peek` untuk melihat elemen teratas tanpa menghapusnya, serta `isEmpty` atau `isFull` untuk mengecek kondisi stack.[1].

Stack dikenal sangat luas pemakaiannya dalam menyelesaikan berbagai macam permasalahan. Compiler, Sistem Operasi, dan berbagai Program Aplikasi banyak menggunakan konsep Stack tersebut. Salah satu contoh adalah masalah Penjodohan Tanda Kurung (Matching Parantheses). Misalnya, dalam algoritma pencarian dan pengurutan[2].

### A. Komponen Stack <br/>
Komponen – komponen dalam stack pada dasarnya sama dengan komponen pada Singly linked list. Hanya saja akses pada stack hanya bisa dilakukan pada awal stack saja.

```C++
#ifndef STACK_H
#define STACK_H
typedef int infotype;

struct elmStack {
    infotype info;
    elmStack* next;
}; 

struct stack {
    elmStack* Top;
};

#endif

```

### B. Operasi dalam Stack <br/>

#### 1. Push
Operasi yang menyisipkan elemen pada tumpukan data. Fungsi ini sama dengan fungsi insert first pada list biasa.

#### 2. Pop
Adalah operasi pengambilan data dalam list. Operasi ini mirip dengan operasi delete first dalam list linear, karena elemen yang paling pertama kali diakses adalah elemen paling atas atau elemen paling awal saja.


### C. Primitif dalam Stack
- createStack().
- isEmpty().
- alokasi().
- dealokasi().
- Fungsi – fungsi pencarian.
- Dan fungsi – fungsi primitif lainnya.
Seperti halnya pada model list yang lain, primitif-primitifnya tersimpan pada file `*.c`dan file `*.h`.

## Guided 1

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```

Program ini mengimplementasikan stack berbasis linked list dengan operasi `push`, `pop`, `update`, tampil data, dan pencarian.

## Guided 2

### 1. stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define MaxEl 20
#define Nil NULL
typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### 2. stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

### 3. main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program ini mengimplementasikan stack berbasis array dengan operasi dasar `push`, `pop`, `print`, dan fungsi untuk membalik isi stack.

## Unguided

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
```
Type infotype : integer
Type Stack <
    info : array [20] of integer
    top : integer
>
procedure CreateStack(input/output S : Stack)
procedure push(input/output S : Stack, input x : infotype)
function pop(input/output t S : Stack) → infotype
procedure printInfo(input S : Stack)
procedure balikStack(input/output S : Stack)
```

Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp":
```
int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

- stack.h
```C++
#ifndef STACK_H
#define MaxEl 20
#define Nil -1

#include <iostream>

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

- stack.cpp
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return (S.top == Nil);
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
```

- main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan7_Modul7/Unguided/Output/output_no1.jpg)

### 2.  Tambahkan prosedur `pushAscending(in/out S : Stack, in x : integer)`

- stack.h
```C++
void pushAscending(Stack &S, infotype x);
```

- stack.cpp
```C++
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```

- main.cpp
```C++
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan7_Modul7/Unguided/Output/output_no2.jpg)

### 3.  Tambahkan prosedur `getInputStream(in/out S : Stack)`. Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

- stack.h
```C++
void getInputStream(Stack &S);
```

- stack.cpp
```C++
void getInputStream(Stack &S) {  
    char c;
    cin.get(c);

    if (c == '\n') cin.get(c);

    while (c != '\n') {
        if (!isFull(S) && c >= '0' && c <= '9') {
            push(S, c - '0');
        }
        cin.get(c);
    }
}
```

- main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```

### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan7_Modul7/Unguided/Output/output_no3.jpg)

## Kesimpulan
Stack adalah struktur data linear yang mengikuti konsep LIFO (Last In, First Out), di mana elemen yang dimasukkan terakhir akan menjadi elemen pertama yang diambil. Dalam implementasi berbasis array, stack dikendalikan menggunakan variabel `top` sebagai penanda elemen teratas, dan menyediakan operasi dasar seperti `CreateStack`, `push`, `pop`, dan `printInfo` untuk membuat stack, menambah elemen, menghapus elemen, dan menampilkan isinya. Materi ini juga membahas operasi lanjutan seperti `balikStack` yang membalik urutan elemen dengan bantuan stack sementara, `pushAscending` yang menyisipkan elemen agar tersusun naik dari bawah ke atas, dan `getInputStream` yang membaca input karakter per karakter hingga tombol ENTER ditekan lalu menyimpannya ke dalam stack. Secara keseluruhan, pembahasan ini menunjukkan bahwa stack dapat dimodifikasi dan dikembangkan dengan memanfaatkan prinsip LIFO serta berbagai operasi tambahan untuk mendukung kebutuhan pengolahan data yang lebih kompleks.

## Referensi
[1] Amaylia, S., Setiabud, V. A., Alvianino, R., et al. (2025). Application of Stack Data Structure in Application Development. Journal of Advanced Systems Intelligence and Cybersecurity.
<br>[2] Setiyawan, R. D., Hermawan, D., et al. (2024). PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST. Journal Education and Technology (JURTECH).