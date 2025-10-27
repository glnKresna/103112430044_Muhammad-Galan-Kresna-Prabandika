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
