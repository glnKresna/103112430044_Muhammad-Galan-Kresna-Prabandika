#include <iostream>
using namespace std;

struct NodeChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild *next;
    NodeChild *prev;
};

struct NodeParent {
    string idGenre;
    string namaGenre;
    NodeParent *next;
    NodeParent *prev;
    NodeChild *firstChild;
    NodeChild *lastChild;
};

struct ListParent {
    NodeParent *first;
    NodeParent *last;
};

void createListParent(ListParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(NodeParent *P) {
    P->firstChild = NULL;
    P->lastChild = NULL;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *newNode = new NodeParent;
    newNode->idGenre = id;
    newNode->namaGenre = nama;
    newNode->next = NULL;
    newNode->prev = NULL;
    createListChild(newNode);
    return newNode;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *newNode = new NodeChild;
    newNode->idFilm = id;
    newNode->judulFilm = judul;
    newNode->durasiFilm = durasi;
    newNode->tahunTayang = tahun;
    newNode->ratingFilm = rating;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void dealokasiNodeParent(NodeParent *node) {
    delete node;
}

void dealokasiNodeChild(NodeChild *node) {
    delete node;
}

void insertFirstParent(ListParent &L, NodeParent *newNode) {
    if (L.first == NULL) {
        L.first = newNode;
        L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLastChild(NodeParent *parent, NodeChild *newNode) {
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
        parent->lastChild = newNode;
    } else {
        parent->lastChild->next = newNode;
        newNode->prev = parent->lastChild;
        parent->lastChild = newNode;
    }
}

void insertLastParent(ListParent &L, NodeParent *newNode) {
    if (L.first == NULL) {
        L.first = newNode;
        L.last = newNode;
    } else {
        L.last->next = newNode;
        newNode->prev = L.last;
        L.last = newNode;
    }
}

void hapusListChild(NodeParent *parent) {
    NodeChild *curr = parent->firstChild;
    while (curr != NULL) {
        NodeChild *temp = curr;
        curr = curr->next;
        dealokasiNodeChild(temp);
    }
    parent->firstChild = NULL;
    parent->lastChild = NULL;
}

void deleteAfterParent(ListParent &L, string idGenrePrec) {
    NodeParent *prec = L.first;
    while (prec != NULL && prec->idGenre != idGenrePrec) {
        prec = prec->next;
    }

    if (prec == NULL || prec->next == NULL) {
        return;
    }

    NodeParent *delNode = prec->next;
    NodeParent *afterDel = delNode->next;

    hapusListChild(delNode);

    prec->next = afterDel;
    if (afterDel != NULL) {
        afterDel->prev = prec;
    } else {
        L.last = prec;
    }

    dealokasiNodeParent(delNode);
}

void searchFilmByRatingRange(ListParent L, float minRating, float maxRating) {
    NodeParent *P = L.first;
    bool found = false;
    
    while (P != NULL) {
        NodeChild *C = P->firstChild;
        while (C != NULL) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                cout << "Film: " << C->judulFilm << " (" << C->ratingFilm << ") - Genre: " << P->namaGenre << endl;
                found = true;
            }
            C = C->next;
        }
        P = P->next;
    }
    if (!found) cout << "Tidak ada film dalam range tersebut." << endl;
}

void printStrukturMLL(ListParent L) {
    NodeParent *P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre   : " << P->idGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        
        NodeChild *C = P->firstChild;
        int j = 1;
        while (C != NULL) {
            cout << "   - Child " << j << " :" << endl;
            cout << "     ID Film      : " << C->idFilm << endl;
            cout << "     Judul Film   : " << C->judulFilm << endl;
            cout << "     Durasi Film  : " << C->durasiFilm << " menit" << endl;
            cout << "     Tahun Tayang : " << C->tahunTayang << endl;
            cout << "     Rating Film  : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "----------------------" << endl;
        P = P->next;
        i++;
    }
}

int main() {
    ListParent LP;
    createListParent(LP);

    NodeParent *P1 = alokasiNodeParent("G001", "Action");
    NodeParent *P2 = alokasiNodeParent("G002", "Comedy");
    NodeParent *P3 = alokasiNodeParent("G003", "Horror");
    NodeParent *P4 = alokasiNodeParent("G004", "Romance");

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);

    insertLastChild(P1, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));

    insertLastChild(P2, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P2, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    insertLastChild(P3, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    insertLastChild(P4, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P4, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(LP);

    deleteAfterParent(LP, "G001");

    cout << endl;
    printStrukturMLL(LP);

    return 0;
}