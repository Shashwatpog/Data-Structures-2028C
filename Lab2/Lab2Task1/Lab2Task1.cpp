#include <iostream>
#include <fstream>
using namespace std;
#include <string>

int main()
{
    string filename;
    string line;
    cout  << "Enter Name of the File You want to open" << endl;
    cin >> filename;
    fstream data;
    data.open(filename, ios::in);
    if (data.fail()) {
        cout << "File does not exist" << endl;
    }
    else {
        for (int i=0; i < 10; i++) {
            getline(data, line);
            cout << line << endl;
        }
    }
    return 0;
}

