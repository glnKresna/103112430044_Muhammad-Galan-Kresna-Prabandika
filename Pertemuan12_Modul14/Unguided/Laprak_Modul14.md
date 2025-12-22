# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Muhammad Galan Kresna Prabandika - 103112430044</p>

## Dasar Teori
Graf adalah struktur data abstrak yang direpresentasikan sebagai pasangan (V, E) di mana V adalah himpunan simpul (vertices) dan E adalah himpunan sisi (edges) yang menghubungkan pasangan simpul (Kirthika et al., 2017)
ijtrd.com. Pada graf tak berarah, setiap sisi merupakan pasangan tak berurut antar-simpul, sedangkan pada graf berarah (digraph) setiap sisi berarah dan hanya melintas dari simpul asal ke simpul tujuan [1]. Selain itu, graf dapat bersifat berbobot jika setiap sisi diberi nilai angka tertentu (bobot) atau tak berbobot jika tidak ada nilai seperti itu [2]. Graf banyak digunakan dalam ilmu komputer untuk memodelkan sistem nyata; misalnya, Internet dapat dipandang sebagai graf yang terdiri dari router (simpul) dan koneksi antar-router (sisi),

Operasi dasar pada graf meliputi penelusuran (traversal) simpul dan sisi. Dua algoritma traversal utama adalah Breadth-First Search (BFS) dan Depth-First Search (DFS). BFS menelusuri graf secara level-order mulai dari sumber tertentu dengan memanfaatkan struktur antrian, sedangkan DFS menjelajah sedalam mungkin di satu cabang sebelum mundur, menggunakan struktur tumpukan. Dengan representasi adjacency list, penelusuran BFS/DFS dapat dilakukan dengan waktu linier sebanding dengan jumlah simpul dan sisi, yakni O(|V|+|E|). Keefisienan ini membuat graf sangat berguna dalam berbagai algoritma.

### A. Jenis-Jenis Graph

#### 1. Graph berarah (directed graph)
Merupakan graph dimana tiap node memiliki edge yang memiliki arah, kemana node tersebut dihubungkan.

#### 2. Graph tak berarah (undirected graph)
Merupakan graph dimana tiap node memiliki edge yang tidak terarah, node bebas berhubungan dengan node manapun selama masih bertetangga.


### B. Metode Penelusuran Graph <br/>

#### 1. Breadth First Search (BST)
Cara kerja algoritma ini adalah dengan mengunjungi root (depth 0) kemudian ke depth 1, 2, dan seterusnya. Kunjungan pada masing-masing level dimulai dari kiri ke kanan. Secara umum, Algoritma BFS pada graph adalah sebagai berikut:
```
procedure BFS ( input g : graph, start : node )
kamus
    Q : Queue
    x, w : node
algoritma
    enqueue ( Q, start )
    while ( not isEmpty( Q ) ) do
        x  dequeue ( Q )
        if ( isVisited( x ) = false ) then
            isVisited( x )  true
            output ( x )
            for each node w Є Vx
            if ( isVisited( w ) = false ) then
                enqueue( Q, w )
```

#### 2. Depth First Search (DFS)
Cara kerja algoritma ini adalah dengan mengunjungi root, kemudian rekursif ke subtree node tersebut. Secara umum, Algoritma DFS pada graph adalah sebagai berikut:
```
procedure BFS ( input g : graph, start : node )
kamus
    S : Stack
    x, w : node
algoritma
    push ( S, start )
    while ( not isEmpty( S ) ) do
        x  pop ( S )
        if ( isVisited( x ) = false ) then
            isVisited( x )  true
            output ( x )
        for each node w Є Vx
        if ( isVisited( w ) = false ) then
            push ( S, w )
```

## Guided 1

### 1. graph.h

```h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

### 2. graph_init.cpp

```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

### 3. graph_edge.cpp

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```

### 4. graph_print.cpp

```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
    cout << endl;
    P = P->next;
    }
}
```

### 5. main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << "=== Informasi Graph (Adjacency List) ===" << endl;
    PrintInfoGraph(G);

    cout << "=== Hasil Penelusuran DFS ===" << endl;
    PrintDFS(G, A);

    cout << "\n=== Hasil Penelusuran BFS ===" << endl;
    PrintBFS(G, A);

    return 0;
}
```


## Unguided

### 1. Buatlah ADT Graph tidak berarah file “graph.h”: Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

- graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

adrNode FindNode(Graph G, infoGraph X);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

- graph.cpp
```C++
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
    cout << endl;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void DFSRecursive(adrNode N) {
    if (N == NULL) return;
    
    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0) {
            DFSRecursive(E->Node);
        }
        E = E->Next;
    }
}
```

- main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode G_node = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G_node);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G_node, H);

    cout << "Informasi Graph (Adjacency List)" << endl;
    PrintInfoGraph(G);

    return 0;
}
```

### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan12_Modul14/Unguided/Output/output_no1.png)

### 2.  Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N);

- graph.cpp
```C++
void PrintDFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "DFS Traversal starting from " << N->info << ": ";
    DFSRecursive(N);
    cout << endl;
}
```

```C++
int main() {
   cout << "Hasil Penelusuran DFS" << endl;
    PrintDFS(G, A);
}
```

### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan12_Modul14/Unguided/Output/output_no2.png)

### 3. Print tree secara pre-order dan post-order.

- graph.cpp
```C++
void PrintBFS(Graph G, adrNode N) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        cout << current->info << " ";

        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}
```

- main.cpp
```C++
    cout << "\nHasil Penelusuran BFS" << endl;
    PrintBFS(G, A);
```

### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3](https://github.com/glnKresna/103112430044_Muhammad-Galan-Kresna-Prabandika/blob/main/Pertemuan12_Modul14/Unguided/Output/output_no3.png)

## Kesimpulan
Berdasarkan kajian teori dan praktikum, struktur data graf merupakan representasi matematis yang sangat fleksibel dan kuat untuk memodelkan berbagai permasalahan kompleks yang melibatkan hubungan antarobjek. Dengan komponen utama berupa simpul (vertex) dan sisi (edge), graf mampu merepresentasikan beragam sistem nyata seperti jaringan komputer, peta transportasi, hingga jejaring sosial. Keberadaan berbagai jenis graf—baik berarah maupun tidak berarah, berbobot maupun tidak berbobot—menjadikan graf dapat disesuaikan dengan kebutuhan permasalahan yang berbeda, sebagaimana dijelaskan dalam berbagai penelitian ilmiah.

Selain itu, algoritma dasar pada graf seperti Breadth-First Search (BFS) dan Depth-First Search (DFS) memiliki peran penting dalam proses penelusuran dan analisis struktur graf secara efisien dengan kompleksitas waktu O(|V| + |E|). Efisiensi dan fleksibilitas ini menjadikan graf sebagai salah satu struktur data fundamental dalam ilmu komputer, khususnya dalam pengembangan algoritma, optimisasi rute, analisis jaringan, dan berbagai aplikasi komputasi modern. Oleh karena itu, pemahaman konsep graf dan algoritmanya menjadi dasar penting dalam studi struktur data dan algoritma.

## Referensi
[1] Kirthika, B., Dhamayanthi, S.B., Tamizharasi, P.S. (2017). A Survey on Different Data Structure. International Journal of Trend in Research and Development, 4(1).
<br>[2] Kudase, J., Bane, P. (2016). A Brief Study of Graph Data Structure. International Journal of Advanced Research in Computer and Communication Engineering, 5(6).