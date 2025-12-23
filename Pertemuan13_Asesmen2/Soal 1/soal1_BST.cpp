#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

Node *root;

bool isEmpty() {
    return root == NULL;
}

void createTree() {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node();
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertRec(Node* node, string nama, float berat, string tier) {
    if (node == NULL) {
        return newNode(nama, berat, tier);
    }

    if (berat < node->beratBadan) {
        node->left = insertRec(node->left, nama, berat, tier);
    } else if (berat > node->beratBadan) {
        node->right = insertRec(node->right, nama, berat, tier);
    }

    return node;
}

void insertNode(string nama, float berat, string tier) {
    root = insertRec(root, nama, berat, tier);
}

void mostLeft() {
    if (isEmpty()) {
        cout << "Tree kosong." << endl;
        return;
    }
    Node* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    cout << "Node MostLeft  : " << curr->beratBadan << endl;
}

void mostRight() {
    if (isEmpty()) {
        cout << "Tree kosong." << endl;
        return;
    }
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    cout << "Node MostRight : " << curr->beratBadan << endl;
}

void inOrderRec(Node* node) {
    if (node != NULL) {
        inOrderRec(node->left);
        cout << node->beratBadan << " - ";
        inOrderRec(node->right);
    }
}

void inOrder() {
    cout << "=== Traversal InOrder ===" << endl;
    inOrderRec(root);
    cout << endl;
}

void searchRec(Node* curr, Node* parent, float target) {
    if (curr == NULL) {
        cout << "Data berat badan " << target << " tidak ditemukan" << endl;
        return;
    }

    if (curr->beratBadan == target) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << curr->namaMember << endl;
        cout << "Berat Badan : " << curr->beratBadan << endl;
        cout << "Tier Member : " << curr->tierMember << endl;
        cout << "-----------------------------" << endl;

        cout << "--- Data Parent ---" << endl;
        if (parent != NULL) {
            cout << "Nama Member : " << parent->namaMember << endl;
            cout << "Berat Badan : " << parent->beratBadan << endl;
            cout << "Tier Member : " << parent->tierMember << endl;
        } else {
            cout << "Node ini adalah Root (Tidak memiliki Parent)" << endl;
        }
        cout << "-----------------------------" << endl;

        if (parent != NULL) {
            Node* sibling = NULL;
            if (parent->left == curr) {
                sibling = parent->right;
            } else {
                sibling = parent->left;
            }

            if (sibling != NULL) {
                cout << "Sibling : " << sibling->namaMember << " (" << sibling->beratBadan << ")" << endl;
            } else {
                cout << "Tidak Memiliki Sibling" << endl;
            }
        } else {
            cout << "Tidak Memiliki Sibling (Karena Root)" << endl;
        }
        cout << "-----------------------------" << endl;

        cout << "--- Data Child Kiri ---" << endl;
        if (curr->left != NULL) {
            cout << "Nama Member : " << curr->left->namaMember << endl;
            cout << "Berat Badan : " << curr->left->beratBadan << endl;
            cout << "Tier Member : " << curr->left->tierMember << endl;
        } else {
            cout << "Tidak memiliki Child Kiri" << endl;
        }
        cout << "-----------------------------" << endl;

        cout << "--- Data Child Kanan ---" << endl;
        if (curr->right != NULL) {
            cout << "Nama Member : " << curr->right->namaMember << endl;
            cout << "Berat Badan : " << curr->right->beratBadan << endl;
            cout << "Tier Member : " << curr->right->tierMember << endl;
        } else {
            cout << "Tidak memiliki Child Kanan" << endl;
        }
        cout << "-----------------------------" << endl;

        return; 
    }

    if (target < curr->beratBadan) {
        searchRec(curr->left, curr, target);
    } else {
        searchRec(curr->right, curr, target);
    }
}

void searchByBeratBadan(float berat) {
    searchRec(root, NULL, berat);
}

int main() {
    createTree();

    insertNode("Rizkina Azizah", 60, "Basic");
    insertNode("Hakan Ismail", 50, "Bronze");
    insertNode("Olivia Saevali", 65, "Silver");
    insertNode("Felix Pedrosa", 47, "Gold");
    insertNode("Gamel Al Ghifari", 56, "Platinum");
    insertNode("Hanif Al Faiz", 70, "Basic");
    insertNode("Mutiara Fauziah", 52, "Bronze");
    insertNode("Davi Ilyas", 68, "Silver");
    insertNode("Abdad Mubarok", 81, "Gold");

    inOrder();
    cout << endl;

    mostLeft();
    mostRight();
    cout << endl;

    searchByBeratBadan(70);

    return 0;
}