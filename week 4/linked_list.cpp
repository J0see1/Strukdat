#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode* next;
};

TNode* head = nullptr;
TNode* tail = nullptr;

void insertFront(int newData) {
    TNode* input = new TNode;
    input->data = newData;
    input->next = head;
    head = input;
    if (tail == nullptr) tail = input;
    cout << "Data masuk\n";
}

void showList() {
    TNode* n = head;
    if (n == nullptr) {
        cout << "Masih kosong\n";
        } else {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
        }
    }
}

void delFront() {
    if (head != nullptr) {
        TNode* hapus = head;
        int d = hapus->data;
        head = head->next;
        delete hapus;
        if (head == nullptr) tail = nullptr;
        cout << d << " deleted\n";
    }
    else {
        cout << "failed executing delete function\n";
    }
}

void clearList() {
    TNode* n = head;
    while (n != nullptr) {
        TNode* hapus = n;
        n = n->next;
        delete hapus;
    }
    head = tail = nullptr;
    cout << "clear\n";
}

int main() {
    int input, newData;
    while (true) {
        cout << endl;
        cout << " ============================" << endl;
        cout << " =   LINKED LIST PROGRAM    =" << endl;
        cout << " ============================" << endl;
        cout << " = 1. Insert Front          =" << endl;
        cout << " = 2. Delete Front          =" << endl;
        cout << " = 3. Show Data             =" << endl;
        cout << " = 4. Clear                 =" << endl;
        cout << " = 5. Exit                  =" << endl;
        cout << " ============================" << endl;
        cout << " Select menu : ";
        cin >> input;
        if (input == 1) {
            cout << "Input Data = "; 
            cin >> newData;
            insertFront(newData);
        }
        else if (input == 2) {
            delFront();
        }
        else if (input == 3) {
            showList();
        }
        else if (input == 4) {
            clearList();
        }
        else if (input == 5) {
            break;
        }
        else {
            cout << "\n Select another input";
        }
    }
}
