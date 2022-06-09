#include "iostream"
#include "cmath"
 
using namespace std;
 
class Tr
{
public:
    Tr()
    {}


    Tr (double a, double b, double c, double d, double e, double f): x1(a), y1(b), x2(c), y2(d), x3(e), y3(f){
        AB = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        BC = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        AC = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        if (AB < BC + AC && BC < AB + AC && AC < AB + BC) {
            isTr = true;
        } else {
            isTr = false;
        }
    } 

    ~Tr()
    {}
    
    double Perimeter()
    {
        return AB + BC + AC;
    }

    double Ploshad() {
        return sqrt(AB + BC + AC * ((AB + BC + AC) - BC) * ((AB + BC + AC) - AC) * ((AB + BC + AC) - AB));
    }

    int Display() {
        if (isTr){
            cout << "Figura est" << endl;
            return 1;
        }
        else {
            cout << "Figuri ne sushestvuet" << endl;
            return 0;
        }
    }
    private: 
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double AB, BC, AC;
        bool isTr;

};

 
int main()
{
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double p1, s1;
        int flag;
        cout << "Введите координаты треугольника(x1 y1 x2 y2 x3 y3) - ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tr t(x1, y1, x2, y2, x3, y3);
   
        flag = t.Display();
        if (flag) {
            p1 = t.Perimeter();
            s1 = t.Ploshad();
            cout << "Периметр треугольника = " << p1 << endl;
            cout << "Площадь треугольника = " << s1 << endl;
        }
        return 0;
}