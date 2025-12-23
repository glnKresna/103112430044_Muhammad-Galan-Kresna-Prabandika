#include <iostream>
#include <string>

using namespace std;

struct Node;

struct Edge {
    Node* destination;
    Edge* nextEdge;
};

struct Node {
    string info;
    bool isLockdown;
    bool visited;
    Edge* firstEdge;
    Node* next;
};

struct Graph {
    Node* first;
};

void createGraph(Graph &G) {
    G.first = NULL;
}

Node* createNode(string name) {
    Node* newNode = new Node;
    newNode->info = name;
    newNode->isLockdown = false;
    newNode->visited = false;
    newNode->firstEdge = NULL;
    newNode->next = NULL;
    return newNode;
}

Edge* createEdge(Node* dest) {
    Edge* newEdge = new Edge;
    newEdge->destination = dest;
    newEdge->nextEdge = NULL;
    return newEdge;
}

void addNode(Graph &G, string name) {
    Node* newNode = createNode(name);
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        Node* curr = G.first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

Node* findNode(Graph G, string name) {
    Node* curr = G.first;
    while (curr != NULL) {
        if (curr->info == name) return curr;
        curr = curr->next;
    }
    return NULL;
}

void addEdge(Graph &G, string srcName, string destName) {
    Node* srcNode = findNode(G, srcName);
    Node* destNode = findNode(G, destName);

    if (srcNode != NULL && destNode != NULL) {
        Edge* newEdge1 = createEdge(destNode);
        newEdge1->nextEdge = srcNode->firstEdge;
        srcNode->firstEdge = newEdge1;

        Edge* newEdge2 = createEdge(srcNode);
        newEdge2->nextEdge = destNode->firstEdge;
        destNode->firstEdge = newEdge2;
    }
}

void resetVisited(Graph G) {
    Node* curr = G.first;
    while (curr != NULL) {
        curr->visited = false;
        curr = curr->next;
    }
}

int countTotalNodes(Graph G) {
    int count = 0;
    Node* curr = G.first;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void DFS(Node* curr, int &count) {
    curr->visited = true;
    count++;

    Edge* e = curr->firstEdge;
    while (e != NULL) {
        if (!e->destination->visited && !e->destination->isLockdown) {
            DFS(e->destination, count);
        }
        e = e->nextEdge;
    }
}

void analyzeCriticalPoints(Graph G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    
    int totalNodes = countTotalNodes(G);
    Node* target = G.first;

    while (target != NULL) {
        target->isLockdown = true;

        resetVisited(G);

        Node* startNode = G.first;
        if (startNode == target) {
            startNode = startNode->next;
        }

        int reachableNodes = 0;
        if (startNode != NULL) {
            DFS(startNode, reachableNodes);
        }

        if (reachableNodes < (totalNodes - 1)) {
            cout << "[PERINGATAN] Kota " << target->info << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << target->info << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << target->info << " aman (redundansi oke)." << endl;
        }

        target->isLockdown = false;

        target = target->next;
    }
}

void printGraph(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    Node* curr = G.first;
    while (curr != NULL) {
        cout << "Node " << curr->info << " terhubung ke: ";
        Edge* e = curr->firstEdge;
        while (e != NULL) {
            cout << e->destination->info << " ";
            e = e->nextEdge;
        }
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    Graph G;
    createGraph(G);

    addNode(G, "A");
    addNode(G, "B");
    addNode(G, "C");
    addNode(G, "D");
    addNode(G, "E");

    addEdge(G, "A", "B");
    addEdge(G, "B", "E");
    addEdge(G, "B", "C");
    addEdge(G, "C", "D");

    printGraph(G);

    analyzeCriticalPoints(G);

    return 0;
}