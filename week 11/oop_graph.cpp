#include <iostream>
#include <list>
// #include <graphics.h>
using namespace std;

struct nodeName {
    string name;
};

class Titik {
private:
    int id;
    string nama;
    int x;
    int y;

public:
    Titik() {}

    Titik(int id, string nama, int x, int y) {
        this->id = id;
        this->nama = nama;
        this->x = x;
        this->y = y;
    }

    int getID() {
        return id;
    }

    string getNama() {
        return nama;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Map {
private:
    int node;
    list<int> *adjList;
    int **adjMatrix;
    nodeName *nodeInfo;
    Titik *titikInfo;

public:
    Map(int node, nodeName nodeInfo[], Titik titikInfo[]) {
        this->node = node;
        this->adjListInit(node);
        this->adjMatrixInit(node);
        this->nodeInfo = new nodeName[node];
        for (int i = 0; i < node; i++) {
            this->nodeInfo[i] = nodeInfo[i];
        }
        this->titikInfo = new Titik[node];
        for (int i = 0; i < node; i++) {
            this->titikInfo[i] = titikInfo[i];
        }
    }

    ~Map() {
        delete[] adjList;
        delete[] nodeInfo;
        delete[] titikInfo;
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
            cout << titikInfo[v].getNama() << " -> ";
            for (i = adjList[v].begin(); i != adjList[v].end(); ++i) {
                cout << titikInfo[*i].getNama();
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

    list<int>* getAdjList() {
        return adjList;
    }

    int getNode() {
        return node;
    }
};

// void drawGraph(Titik titikInfo[], Map myMap) {
//     int gd = DETECT, gm;
//     initgraph(&gd, &gm, NULL);

//     for (int i = 0; i < myMap.getNode(); i++) {
//         circle(titikInfo[i].getX(), titikInfo[i].getY(), 5);
//         outtextxy(titikInfo[i].getX() + 10, titikInfo[i].getY(), titikInfo[i].getNama().c_str());
//     }

//     for (int i = 0; i < myMap.getNode(); i++) {
//         for (int tujuan : myMap.getAdjList()[i]) {
//             line(titikInfo[i].getX(), titikInfo[i].getY(), titikInfo[tujuan].getX(), titikInfo[tujuan].getY());
//         }
//     }

//     delay(5000);
//     closegraph();
// }

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

    Titik titikInfo[] = {
        Titik(0, "Rumah", 100, 100),
        Titik(1, "SMA_2", 200, 100),
        Titik(2, "Stadion", 300, 100),
        Titik(3, "Toko", 100, 200),
        Titik(4, "Stasiun", 200, 200),
        Titik(5, "Gereja", 300, 200),
        Titik(6, "Alun Alun", 100, 300),
        Titik(7, "Terminal", 200, 300),
        Titik(8, "Lapangan Gulun", 300, 300),
        Titik(9, "Maospati", 400, 300)
    };

    Map myMap(node, nodeInfo, titikInfo);

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

    // drawGraph(titikInfo, myMap);

    return 0;
}
