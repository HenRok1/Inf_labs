#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int first_sub(string, string);

int main() {
    int flag = 0;
    string file_name;
    
    cout << "Enter a file name: " << endl;
    cin >> file_name;
    ifstream fin;
    fin.open(file_name);
    
    if (!fin.is_open()) {
        cout << "Error open file"; 
    } else {
        cout << "File is open" << endl;
        string str;
        string sub = "one";
        
        while (!fin.eof()) {
            str = "";
            getline(fin, str);
            if (first_sub(str, sub)) {
                cout << "str has ONE";
                break;
            } else {
                cout << "str not has ONE";
                break;
            }
            }
        }

    fin.close();
    return 0;;
}


int first_sub(string src, string sub) {
    int start = 0;
    int count = 0;
    int pos = 0;
    for (;;) {
        pos = src.find(sub.c_str(), start);
        if (pos != -1) {
            start = pos + sub.size();
            count = 1;
            break;
        } else {
            break;
        }
    }
    return count;
}
