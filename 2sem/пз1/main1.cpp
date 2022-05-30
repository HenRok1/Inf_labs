#define _USE_MATH_DEFINES
#include <iostream>
#include<cmath>
using namespace std;

int max_ell(int *, int);
int min_ell(int *, int);

void input_array(int **, int, int);
void range_of_array_values(int *, int);
void range_of_absolute_values(int **, int, int);

void input_array(int **arr, int p, int q){
    int i, j;
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
        {
            cout << "[" << i + 1 <<"][" << j + 1 <<"]=";
            cin >> arr[i][j];
        }
}

int max_ell(int *arr, int n) {
    int second_point = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > second_point) {
            second_point = arr[i];
        }
    }
    return second_point;
}

int min_ell(int *arr, int n) {
    int first_point = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < first_point) {
            first_point = arr[i];
        }
    }
    return first_point;
}

void range_of_array_values(int *ms, int n){
    ms = new int [n];
    for (int i = 0; i < n; i++){
        cout << "Enter values";
        cout << "[" << i + 1 << "]" << ": ";
        cin >> ms[i];
    }
    cout << "range of array values: " << "(" << min_ell(ms, n) << ";" << max_ell(ms, n) << ")";
    cout << endl;
}

void range_of_absolute_values(int **arr, int p, int q, double (*func)(double)){
    int tmp;
    for (int j = 0; j < q; j++)
    {
        int minVal = (*func)(arr[0][j]);
        int maxVal = (*func)(arr[0][j]);
        for (int i = 0; i < p; i++) {
            if ((*func)(arr[i][j]) < (*func)(minVal))
                minVal = (*func)(arr[i][j]);
            if ((*func)(arr[i][j]) > (*func)(maxVal))
                maxVal = (*func)(arr[i][j]);
        }
        cout << "range of absolute values of a column[" << j + 1 << "] = " << "(" << minVal << ":" << maxVal << ")" << "\r\n";

    }
}

int main()
{
    setlocale(0,"RUS");
    // int n;
    // //ms
    // cout << "Enter n: ";
    // cin >> n;
    // int *ms;
    // ms = new int [n];
    // range_of_array_values(ms, n);
    // cout << endl;
    // delete []ms;

    int **arr, p, q;
    p = q = 0;
    do
    {
        if (p < 1)
        {
            cout << "enter the number of lines p: ";
            cin >> p;
        }
        if (q < 1)
        {
            cout << "enter the number of columns q: ";
            cin >> q;
        }
        if ((p < 1) || (q < 1))
        {
            cout << "\n:";
            if (p < 1) cout << " p ";
            if (q < 1) cout << " q ";
            cout << endl;
        }
    }
    while ((p < 1) || (q < 1));

    arr = new int*[p];
    for (int i = 0; i < p; i++)
        arr[i] = new int[q];

    input_array(arr, p, q);

    range_of_absolute_values(arr, p, q, &abs);
    cout << endl;

}