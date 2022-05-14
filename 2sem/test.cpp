#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int have_sub(string, string);

int main() {
    string file_name;
    string src;
    string sub1 = "one";
    string sub2 = "three";

    int flag = 0;
    
    cout << "Enter a file name: " << endl;
    cin >> file_name;
    ifstream fin;
    fin.open(file_name);
    
    if (!fin.is_open()) {
        cout << "Error open file"; 
    } else {
//        cout << "File is open" << endl;
        
        while (getline(fin, src) and !fin.eof()) {
            flag++;
            src = "";
//            getline(fin, src);
            if (flag == 1) {
                if (have_sub(src, sub1)) {
                    cout << "src has ONE" << endl;
                    src = "";
                    flag++;
                } else {
                    cout << "src not has ONE" << endl;
                    src = "";
                    flag++;
                }
            }
            if (flag == 2) {
                if (have_sub(src, sub2)) {
                    cout << "src has THREE" << endl;
                    break;
                } else {
                    cout << "src not has THREE" << endl;
                    break;
                }    
            }
        }
    }

    fin.close();
    return 0;;
}

int have_sub(string src, string sub) {
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
