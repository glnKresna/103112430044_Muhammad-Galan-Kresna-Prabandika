#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertAkhir(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;
    baru->prev = tail;

    if (head == nullptr) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void deleteAkhir() {
    if (head == nullptr) {
        cout << "List kosong\n" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail;
        tail = nullptr;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;

    delete hapus;
}

void view() {
    if (head == nullptr) {
        cout << "List kosong\n";
        return;
    }

    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        head = temp->prev;
}

int main() {
    int opsi, angka;

    do {
        cout << "\nMenu: 1. Insert (end), 2. Delete (last), 3. View (depan), 4. Reverse & view (depan), 0. Exit\n";
        cin >> opsi;

        switch (opsi) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> angka;
                insertAkhir(angka);
                break;

            case 2:
                deleteAkhir();
                break;

            case 3:
                view();
                break;

            case 4:
                reverseList();
                cout << "List setelah direverse: ";
                view();
                break;
        }

    } while (opsi != 0);

    return 0;
}