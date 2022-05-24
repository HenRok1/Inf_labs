#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
 
using namespace std;
 
int findword_one(string str) {
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'o' and str[i + 1] == 'n' and str[i + 2] == 'e' and (i + 1 != str.size()) and (i + 2 != str.size())) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int findword_three(string str) {
    int flag = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 't' and str[i + 1] == 'h' and str[i + 2] == 'r' and str[i + 3] == 'e' and str[i + 4] == 'e' and (i + 1 != str.size()) and (i + 2 != str.size()) and (i + 3 != str.size()) and (i + 4 != str.size())) {
            flag = 1;
            break;
        }
    }
    return flag;
}
 
int main() {
 
    string fileName, str;
    cout << "Enter file name: ";
    cin >> fileName;
    fstream f(fileName);
 
    getline(f, str);
    if (findword_one(str) == 1)
        cout <<"One has in str "<< endl;
    else
        cout << "One not has in str " << endl;
    
    getline(f, str);
    if (findword_three(str) == 1)
        cout << "Three has in str" << endl;
    else
        cout << "Three not has in str" << endl;
 
    f.close();
 
    return 0;
}