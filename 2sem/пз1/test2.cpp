#define _USE_MATH_DEFINES
#include <iostream>
#include<cmath>

using namespace std;

double* row_to_mass(int n, int k, double** A) {
	double* out = new double[n];
	for (int i = 0; i < n; ++i)
		out[i] = A[k][i];
	return out;
}

// void input_array(int **arr, int p, int q){
//     int i, j;
//     for (i = 0; i < p; i++)
//         for (j = 0; j < q; j++)
//         {
//             cout << "[" << i + 1 <<"][" << j + 1 <<"]=";
//             cin >> arr[i][j];
//         }
// }

double max_ell(double *arr, int n) {
    double second_point = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > second_point) {
            second_point = arr[i];
        }
    }
    return second_point;
}

double min_ell(double *arr, int n) {
    double first_point = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < first_point) {
            first_point = arr[i];
        }
    }
    return first_point;
}

void range_of_array_values(double *ms, int n, double (*func)(double)){
    // ms = new double[n];
    // for (int i = 0; i < n; i++){
    //     cout << "Enter values";
    //     cout << "[" << i + 1 << "]" << ": ";
    //     cin >> ms[i];
    // }
    cout << "range of array values: " << "(" << (*func)(min_ell(ms, n)) << ";" << (*func)(max_ell(ms, n)) << ")";
    cout << endl;
}

// void range_of_absolute_values(int **arr, int p, int q, double (*func)(double)){
//     int tmp;
//     for (int j = 0; j < q; j++)
//     {
//         int minVal = (*func)(arr[0][j]);
//         int maxVal = (*func)(arr[0][j]);
//         for (int i = 0; i < p; i++) {
//             if ((*func)(arr[i][j]) < (*func)(minVal))
//                 minVal = (*func)(arr[i][j]);
//             if ((*func)(arr[i][j]) > (*func)(maxVal))
//                 maxVal = (*func)(arr[i][j]);
//         }
//         cout << "range of absolute values of a column[" << j + 1 << "] = " << "(" << minVal << ":" << maxVal << ")" << "\r\n";

//     }
// }

int main() {
    int p, q;
    cout << "Enter p - that's lines";
    cin >> p;
    cout << "Enter q - that's columns";
    cin >> q;
    double **arr = new double* [p];
    for (int i = 0; i < p; i++)
        arr[i] = new double[p];

    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++) {
            cout << "enter your matrix";
            cin >> arr[i][j];
        }
    
    double max;
    for (int j = 0; j < q; j++) {
        range_of_array_values(row_to_mass(j, p, arr), q, &abs);
    }
    for (int i = 0; i < p; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;

}

// int main()
// {
//     setlocale(0,"RUS");
//     int **arr;
//     int p, q;
//     p = q = 0;
//     do
//     {
//         if (p < 1)
//         {
//             cout << "enter the number of lines p: ";
//             cin >> p;
//         }
//         if (q < 1)
//         {
//             cout << "enter the number of columns q: ";
//             cin >> q;
//         }
//         if ((p < 1) || (q < 1))
//         {
//             cout << "\n:";
//             if (p < 1) cout << " p ";
//             if (q < 1) cout << " q ";
//             cout << endl;
//         }
//     }
//     while ((p < 1) || (q < 1));

//     arr = new int*[p];
//     for (int i = 0; i < p; i++)
//         arr[i] = new int[q];

//     input_array(arr, p, q);
//     range_of_array_values(row_to_mass(q, p, arr), q, &abs);
//     // range_of_absolute_values(arr, p, q, &abs);
//     for (int i = 0; i < p; ++i)
// 		delete[] arr[i];
// 	delete[] arr;
    //cout << endl;

//}