#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

struct Goods {
    string name;
    string country;
    int date_month;
    int date_day;
    int count;
};

int main () {
    int amount;
    string file_name;
    cout << "Enter a file name: ";
    cin >> file_name;
    ifstream F(file_name);
    Goods goods;
    if (!F) {
        F.close();
        ofstream F(file_name);
        cout << "Enter quantity of all goods:";
        cin >> amount;
        for (int i = 0; i < amount; i++) {
            cout << "Enter name: " << endl;
            cin >> goods.name;
            cout << "Enter country:" << endl;
            cin >> goods.country;
            cout << "Enter month:" << endl;
            cin >> goods.date_month;
            if (goods.date_month > 12 or goods.date_month < 1) {
                cout << "Error!" << endl << "You entered the wrong month";
                break;
            }
            cout << "Enter day:" << endl;
            cin >> goods.date_day;
            if (goods.date_day > 31 or goods.date_day < 0) {
                cout << "Error!" << endl << "you entered the wrong day";
                break;
            }
            if (goods.date_month == 2 and goods.date_day > 29) {
                cout << "Error!" << endl << "February has a maximum of 29 days!";
                break;
            }
            cout << "Enter the quantity of goods:" << endl;
            cin >> goods.count;
            cout << endl;
            F.write((char *) &goods, sizeof(goods));
        }
        F.close();
    }
    ifstream F2(file_name);
    do {
        F2.read((char *)&goods, sizeof(goods));
        if (goods.date_month < 7) {
            cout << goods.country << " ";
        }
    } while (!F2.eof());
    F2.close();
}