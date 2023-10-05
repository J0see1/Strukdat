#include <iostream>
#include <string>

using namespace std;

const int MAX_CHARACTERS = 100; // Maksimum karakter yang dapat disimpan

typedef struct {
    string name;
    int level;
    float str;
    float agi;
    float dex;
} status;

int main (){
    int input;
    status characters[MAX_CHARACTERS];
    int characterCount = 0; // deklarasi awal jumlah karakter
    int index;

    while (true)
    {
        cout << "====== Menu ======" << endl;
        cout << "1. Show Characters " << endl;
        cout << "2. Add Character " << endl;
        cout << "3. Remove Character " << endl;
        cout << "4. Modify Character Stats " << endl;
        cout << "5. Cancel" << endl;
        cout << "Select 1 to 5" << endl;
        cin >> input;


        if(input == 1) { //menampilkan karakter
            for(int i = 0; i < characterCount; i++) {
                cout << "\n==============" << endl;
                cout << "\nCharacter " << i+1 << endl;
                cout << "Name: " << characters[i].name << endl;
                cout << "Level: " << characters[i].level << endl;
                cout << "Str: " << characters[i].str << endl;
                cout << "Agi: " << characters[i].agi << endl;
                cout << "Dex: " << characters[i].dex << "\n" << endl;
                cout << "==============\n" << endl;
            }
        }
        
        else if(input == 2) { //menambhakan karakter
            if(characterCount < MAX_CHARACTERS) {
                status newCharacter;
                cout << "Enter Name: ";
                cin >> newCharacter.name;
                cout << "Enter Level: ";
                cin >> newCharacter.level;
                cout << "Enter Str: ";
                cin >> newCharacter.str;
                cout << "Enter Agi: ";
                cin >> newCharacter.agi;
                cout << "Enter Dex: ";
                cin >> newCharacter.dex;

                characters[characterCount] = newCharacter;
                characterCount++;

                cout << "Character added successfully!" << endl;
            }
            else {
                cout << "Cannot add more characters. Maximum limit reached." << endl;
            }
        }
        else if(input == 3) { //menghapus karakter
            cout << "Enter the index of character to remove: ";
            cin >> index;

            if(index >= 0 && index < characterCount) {
                for(int i = index; i < characterCount - 1; i++) {
                    characters[i+1] = characters[i];
                }
                characterCount--;
                cout << "Character removed successfully!" << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }
        }
        else if(input == 4) { //mengubah status karakter
            cout << "Enter the index of character to modify: ";
            cin >> index;

            if(index >= 0 && index < characterCount) {
                cout << "Enter new Level: ";
                cin >> characters[index].level;
                cout << "Enter new Str: ";
                cin >> characters[index].str;
                cout << "Enter new Agi: ";
                cin >> characters[index].agi;
                cout << "Enter new Dex: ";
                cin >> characters[index].dex;

                cout << "Character modified successfully!" << endl;
            }
            else {
                cout << "Invalid index!" << endl;
            }
        }
        else if(input == 5) {
            break;
        }
        else {
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
        }
    }
    return 0;
}
