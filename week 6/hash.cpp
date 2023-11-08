#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, map<string, string>> accData;

// hash function menjumlahkan nilai ASCII dari setiap karakter
int hashFunction(const string& password) {
    int hash = 0;
    for (char c : password) {
        hash += c;
    }
    return hash;
}

void registerAcc()
{
  string username, password, fullname;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;
  cout << "Masukkan Nama Lengkap: " << endl;
  cin >> fullname;

  string hash_key = to_string(hashFunction(password));
  map<string, string> dataDetail;
  dataDetail["username"] = username;
  dataDetail["fullname"] = fullname;

  // masukkan ke map
  accData[hash_key] = dataDetail;
}

void printAcc()
{
  cout << endl;
  for (auto i = accData.begin(); i != accData.end(); i++)
  {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] << " Fullname: " << i->second["fullname"] << endl;
  }
}

void loginAcc()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));
  
  cout << endl;
  if (accData.find(hash_key) != accData.end())
  {
    cout << "Login berhasil!" << endl
         << endl;
    cout << "==== Account Details ====" << endl;
    cout << "Username: " << accData[hash_key]["username"] << endl;
    cout << "Fullname: " << accData[hash_key]["fullname"] << endl;
  } else {
    cout << "Login gagal!" << endl
         << endl;
  }
}

int main(){
    int input;

    while(true){

        cout << "Menu" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" <<endl;

        cout << "Select Menu" <<endl;
        cin >> input;

        if (input == 1 ){
            registerAcc();
        } else if(input == 2){
            loginAcc();
        }
        else if(input == 3) {
            printAcc();
            break;
        }
        else {
            cout << "Invalid input! Please enter a number between 1 and 3." << endl;
        }
    }
    return 0;
}
