#include <iostream>
#include <string>

using namespace std;

int main() {
    char str[250] = "";
    char res[250] = "";

    cout << "enter str\n";

    fgets(str, 255, stdin);

    int j = 0;
    int i;
    for (i = 0; i < int(sizeof(str)); i++) {
        if (str[i] == ' ') {
            if (j == 0)
                continue;
            if (str[i + 1] == ' ')
                continue;
        }
        res[j] = str[i];
        j++;
    }
    i = sizeof(res);
    if (res[i - 2] == ' ')
        res[i - 2] = '\0';

    cout << res;
}

