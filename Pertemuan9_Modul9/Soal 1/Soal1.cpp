#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node *head = nullptr;

void insertAkhir(string &nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

bool deleteNama(string target) {
    if (head == nullptr) return false;

    if (head->nama == target) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return true;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->nama != target) {
        p = p->next;
    }

    if (p->next == nullptr) return false;

    Node* hapus = p->next;
    p->next = hapus->next;
    delete hapus;
    return true;
}

void tampilkanList() {
    if (head == nullptr) {
        cout << "kosong" << endl;
        return;
    }

    Node* p = head;
    while (p != nullptr) {
        cout << p->nama << " ";
        p = p->next;
    }
    cout << endl;
}

void hitungGenap() {
    int count = 0;
    Node* p = head;
    while (p != nullptr) {
        if (p->nama.length() % 2 == 0) {
            count++;
        }
        p = p->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int opsi;
    string nama;

    do {
        cout << "\nMenu: 1. Insert, 2. Delete, 3. View, 4. Hitung genap, 0. Exit\n";
        cin >> opsi;

        switch (opsi) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                (deleteNama(nama));
                break;

            case 3:
                tampilkanList();
                break;
            
            case 4:
                hitungGenap();
                break;
        }

    } while (opsi != 0);

    return 0;
}