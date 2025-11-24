#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1; 
}

bool isEmpty(Queue Q) {
    return (Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFull(Q) && Q.head > 0) {

        int j = 0;
        for (int i = Q.head; i <= Q.tail; i++) {
            Q.info[j] = Q.info[i];
            j++;
        }
        Q.tail = Q.tail - Q.head;
        Q.head = 0;
    }

    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = 0;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = 0; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}