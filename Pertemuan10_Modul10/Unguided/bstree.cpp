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