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
