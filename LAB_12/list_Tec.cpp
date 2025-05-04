/* B. Write a separate C++ menu-driven program to implement Graph ADT with an adjacency list. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class graph {
    private:
        vector<vector<int>> adj; // adjacency list
        int v; // number of vertices
        bool isdirect; // directed or not

    public:
        graph(int v, bool isdirect); // constructor
        void addedge(int i, int j); // adds edge between i and j
        void deledge(int i, int j); // deletes edge between i and j
        void search(int i, int j); // checks if edge exists
        void print(); // prints adjacency list
        bool check(int i, int j); // bounds check
};

int main() {
    int var = 5, choice = 0, i, j;
    cout << "Enter number of vertices: ";
    cin >> var;
    bool direct = 0; // undirected graph
    class graph g(var, direct);
    cout << "Entering adjacency list menu\n";

    while (choice != 5) {
        cout << "1) Add an edge\n2) Delete an edge\n3) Search for an edge\n4) Print adjacency list\n5) Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter i and j: ";
                cin >> i >> j;
                g.addedge(i, j);
                break;
            case 2:
                cout << "Enter i and j: ";
                cin >> i >> j;
                g.deledge(i, j);
                break;
            case 3:
                cout << "Enter i and j: ";
                cin >> i >> j;
                g.search(i, j);
                break;
            case 4:
                g.print();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Enter a valid number\n";
        }
    }
}

// constructor that sets size and initializes adjacency list
graph::graph(int v, bool isdirect) {
    this->v = v;
    this->isdirect = isdirect;
    adj.resize(v);
}

// bounds check
bool graph::check(int i, int j) {
    if (i < 0 || j < 0 || i >= v || j >= v) {
        return 0;
    }
    return 1;
}

// function to add edge
void graph::addedge(int i, int j) {
    if (check(i, j)) {
        adj[i].push_back(j);
        if (!isdirect) {
            adj[j].push_back(i);
        }
        cout << "Done\n";
    } else {
        cout << "Invalid range\n";
    }
}

// function to delete edge
void graph::deledge(int i, int j) {
    if (check(i, j)) {
        adj[i].erase(remove(adj[i].begin(), adj[i].end(), j), adj[i].end());
        if (!isdirect) {
            adj[j].erase(remove(adj[j].begin(), adj[j].end(), i), adj[j].end());
        }
        cout << "Done\n";
    } else {
        cout << "Invalid range\n";
    }
}

// function to search for edge
void graph::search(int i, int j) {
    if (check(i, j)) {
        bool found = false;
        for (int node : adj[i]) {
            if (node == j) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "There is a path between " << i << " and " << j << "\n";
        } else {
            cout << "There is no path between " << i << " and " << j << "\n";
        }
    } else {
        cout << "Invalid range\n";
    }
}

// function to print adjacency list
void graph::print() {
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (int node : adj[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }
}
