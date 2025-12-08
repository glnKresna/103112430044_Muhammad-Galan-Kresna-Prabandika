# <h1 align="center">Laporan Praktikum Modul 10 - TREE</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Tree merupakan struktur hierarkis yang terdiri dari simpul-simpul dengan maksimal dua anak. Tree digunakan karena mampu menyimpan dan mengelola data lebih efisien dibanding struktur linear. Literatur menjelaskan bahwa sifat hierarkis Tree memungkinkan operasi seperti pencarian dan penyisipan dilakukan lebih cepat, terutama pada varian terstruktur seperti Binary Search Tree (BST) [1]

Binary Search Tree (BST) menerapkan aturan bahwa nilai di anak kiri lebih kecil dan nilai di anak kanan lebih besar dari node induknya. Aturan ini membuat BST efektif digunakan dalam traversal seperti in-order, pre-order, dan post-order, yang masing-masing memiliki kegunaan khusus, termasuk menghasilkan data terurut saat in-order dilakukan. Konsep traversal dan penghitungan atribut pohon seperti jumlah node dan kedalaman juga dijelaskan dalam literatur struktur data modern[2].

### A. Pengertian Rekursif
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar.

Sub Program Rekursif adalah sub program yang memanggil dirinya sendiri selama kondisi pemanggilan dipenuhi. Prinsip rekursif sangat berkaitan erat dengan bentuk induksi matematika. Berikut adalah contoh fungsi rekursif pada rumus pangkat 2: Kita ketahui bahwa secara umum perhitungan pangkat 2 dapat dituliskan sebagai berikut:
```
function pangkat_2 ( x : integer )→integer
kamus

algoritma
    if( x = 0 ) then
    → 1
    else
    → 2 * pangkat_2( x – 1 )
```

#### 1. Kriteria Rekursif
Sub program rekursif umumnya dipakai untuk permasalahan yang memiliki langkah penyelesaian yang terpola atau langkah-langkah yang teratur. Bila kita memiliki suatu permasalahan dan kita mengetahui algoritma penyelesaiannya, kadang-kadang sub program rekursif menjadi pilihan kita bila memang memungkinkan untuk dipergunakan. Secara algoritmis (dari segi algoritma, yaitu bila kita mempertimbangkan penggunaan memori, waktu eksekusi sub program) sub program rekursif sering bersifat tidak efisien.

Dengan demikian sub program rekursif umumnya memiliki efisiensi dalam penulisan perintah, tetapi
kadang tidak efisien secara algoritmis. Meskipun demikian banyak pula permasalahan-permasalahan
yang lebih sesuai diselesaikan dengan cara rekursif (misalnya dalam pencarian / searching, yang akan
dibahas pada pertemuan-pertemuan yang akan datang).

#### 2. Kekurangan Rekursif
Konsep penggunaan yang terlihat mudah karena fungsi rekursif dapat menyederhanakan solusi dari suatu permasalahan, sehingga sering kali menghasilkan bentuk algoritma dan program yang lebih singkat dan lebih mudah dimengerti.


### B. Pengertian Tree <br/>
Tree digambarkan sebagai suatu graph tak berarah terhubung dan tidak terhubung dan tidak mengandung sirkuit.

#### 1. Ordered Tree
Pohon yang urutan anak-anaknya penting.

#### 2. Binary Tree
Setiap node di Binary Tree hanya dapat mempunyai maksimum 2 children tanpa pengecualian. Level dari suatu tree dapat menunjukan berapa kemungkinan jumlah maximum nodes yang terdapat pada tree tersebut. Misalnya, level tree adalah r, maka node maksimum yang mungkin adalah 2r.

## Guided 1

### 1. rekursif_pangkat2.cpp

```C++
#include <iostream>
using namespace std;

int pangkat_2(int x) {
    if (x = 0) {
        return 1;
    } else if (x > 0) {
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "Menghitung x^y" << endl;
    int x;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat " << x << " adalah: " << pangkat_2(x) << endl;

    return 0;
}
```

## Guided 2

### 1. BST1.h

```C++
#ifndef BST1_H
#define BST1_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);

#endif
```

### 2. BST1.cpp

```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

## Guided 3

### 1. BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int countNodes(address root);
int treeDepth(address root);

void searchByData(address root, infotype x);

address mostLeft(address root);
address mostRight(address root);

bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif
```

### 2. BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

### 3. main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```

## Unguided

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”
```
Type infotype: integer
Type address : pointer to Node
Type Node: <
    info : infotype
    left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )
```

Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp”
```
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    return 0;
}
```

- bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

void InOrder(address root);
void PreOrder(address root);
void PostOrder(address root);

#endif
```

- bstree.cpp
```C++
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new(std::nothrow) Node;
    if(p != Nil) {
        p->info = x;
        p->left = Nil;
        p->right = Nil;
    }
    return p;
}

void insertNode(address &root, infotype x) {
    if(root == Nil) {
        root = alokasi(x);
        return;
    }
    if(x < root->info) insertNode(root->left, x);
    else if(x > root->info) insertNode(root->right, x);
    else return;
}

address findNode(infotype x, address root) {
    if(root == Nil) return Nil;
    if(root->info == x) return root;
    if(x < root->info) return findNode(x, root->left);
    return findNode(x, root->right);
}

void InOrder(address root) {
    if(root == Nil) return;
    InOrder(root->left);
    cout << root->info << "-";
    InOrder(root->right);
}

void PreOrder(address root) {
    if(root == Nil) return;
    cout << root->info << "-";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(address root) {
    if(root == Nil) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->info << "-";
}
```

- main.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);

    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan10_Modul10/Unguided/Output/output_no1.jpg)

### 2.  Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

- bstree.h
```C++
int hitungJumlahNode(address root);
int hitungNode(address root);
int hitungTotalInfo(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);
```
Menambahkan definisi fungsi `hitungJumlahNode`, `hitungNode`, `hitungTotalInfo`, `hitungTotal`, `hitungKedalaman`

- bstree.cpp
```C++
int hitungJumlahNode(address root) {
    if(root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungNode(address root) {
    return hitungJumlahNode(root);
}

int hitungTotalInfo(address root) {
    if(root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungTotal(address root) {
    return hitungTotalInfo(root);
}

int hitungKedalaman(address root, int start) {
    if(root == Nil) return start;
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
```

```C++
int main() {
    cout << "Hello World" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);

    cout<<"\n";
    cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
    cout<<"jumlah node : "<<hitungNode(root)<<endl;
    cout<<"total : "<<hitungTotal(root)<<endl;

    return 0;
}
```
Struktur data fungsi

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan10_Modul10/Unguided/Output/output_no2.jpg)

### 3. Print tree secara pre-order dan post-order.

- main.cpp
```C++
cout << "Pre-order: ";
    PreOrder(root);
    cout << "\n";

    cout << "Post-order: ";
    PostOrder(root);
    cout << "\n";
```
Memanggil prosedur `PreOrder` dan `PostOrder`

### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan10_Modul10/Unguided/Output/output_no3.jpg)

## Kesimpulan
Dari hasil praktikum, dapat disimpulkan bahwa Binary Search Tree (BST) merupakan struktur data yang efektif untuk operasi penyisipan, pencarian, dan pengurutan data. Implementasi fungsi insertNode, findNode, serta traversal in-order, pre-order, dan post-order menunjukkan bahwa BST mampu menyusun data secara otomatis berdasarkan aturan perbandingan nilai, sehingga proses membaca data dalam urutan tertentu dapat dilakukan dengan mudah. In-order traversal terbukti menghasilkan data yang terurut, sedangkan pre-order dan post-order memberikan susunan kunjungan node yang berbeda sesuai kebutuhan analisis struktur pohon.

Selain itu, perhitungan jumlah node, total nilai, serta kedalaman pohon memberikan pemahaman tambahan mengenai karakteristik internal BST. Latihan ini membuktikan bahwa BST tidak hanya berguna untuk menyimpan data, tetapi juga memudahkan analisis struktur melalui operasi rekursif yang sederhana namun konsisten. Dengan demikian, praktikum ini membantu memahami bagaimana BST bekerja serta bagaimana struktur data hierarkis dapat digunakan untuk meningkatkan efisiensi pengolahan data.

## Referensi
[1] Wijoyo, A., Syukur, A., Rabbani, A. R., et al (2024). Pemanfaatan Pohon Biner Untuk Pemrosesan Data Efisien.
<br>[2] Dhankhar, R., Kamra, S., Jangra, V. (2014) Tree concept in data structure.