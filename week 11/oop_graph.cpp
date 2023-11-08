#include <iostream>
#include <list>
using namespace std;

struct nodeName {
    string name;
};

class Map {
private:
    int node;
    list<int> *adjList;
    int **adjMatrix;
    nodeName *nodeInfo;

public:
    Map(int node, nodeName nodeInfo[]) {
        this->node = node;
        this->adjListInit(node);
        this->adjMatrixInit(node);
        this->nodeInfo = new nodeName[node];
        for (int i = 0; i < node; i++) {
            this->nodeInfo[i] = nodeInfo[i];
        }
    }

    ~Map() {
        delete[] adjList;
        delete[] nodeInfo;
    }

    void adjListInit(int node) {
        adjList = new list<int>[node];
    }

    void adjMatrixInit(int node) {
        adjMatrix = new int *[node];
        for (int i = 0; i < node; i++) {
            adjMatrix[i] = new int[node];
            for (int j = 0; j < node; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addRoute(int titik_awal, int titik_tujuan) {
        adjList[titik_awal].push_back(titik_tujuan);
        adjMatrix[titik_awal][titik_tujuan] = 1;
        adjMatrix[titik_tujuan][titik_awal] = 1;
    }

    void ShowAdjList() {
        list<int>::iterator i;

        for (int v = 0; v < node; v++) {
            cout << nodeInfo[v].name << " -> ";
            for (i = adjList[v].begin(); i != adjList[v].end(); ++i) {
                cout << nodeInfo[*i].name;
                if (next(i, 1) != adjList[v].end()) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void showAdjMatrix() {
        for (int i = 0; i < node; i++) {
            for (int j = 0; j < node; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "Peta Rumah" << endl;
    int node = 10;
    nodeName nodeInfo[] = {
        {"rumah"},
        {"sma_2"},
        {"stadion"},
        {"toko"},
        {"stasiun"},
        {"gereja"},
        {"alun_alun"},
        {"terminal"},
        {"lap_gulun"},
        {"maospati"}
    };

    Map myMap(node, nodeInfo);

    myMap.addRoute(0, 1);
    myMap.addRoute(0, 2);
    myMap.addRoute(0, 3);
    myMap.addRoute(0, 4);
    myMap.addRoute(1, 4);
    myMap.addRoute(2, 8);
    myMap.addRoute(3, 7);
    myMap.addRoute(4, 7);
    myMap.addRoute(5, 6);
    myMap.addRoute(6, 9);

    cout << endl;
    cout << "Adjacency List" << endl;
    myMap.ShowAdjList();

    cout << endl;
    cout << "Adjacency Matrix" << endl;
    myMap.showAdjMatrix();

    return 0;
}
