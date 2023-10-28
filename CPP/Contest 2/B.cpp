#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k;

    cin >> n;

    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < i; j++) {
            cout << "*";
        }

        cout << "\\";

        for (j = 0; j < n - 2 * i - 2; j++) {
            cout << "*";
        }

        cout << "/";

        for (j = 0; j < i; j++) {
            cout << "*";
        }

        cout << "\n";
    }

    for (k = 0; k < n / 2; k++) {
        cout << "*";
    }

    cout << "X";

    for (k = 0; k < n / 2; k++) {
        cout << "*";
    }

    cout << "\n";

    for (i = n / 2, k = 0; i > 0; i--, k++) {
        for (j = 0; j < i - 1; j++) {
            cout << "*";
        }

        cout << "/";

        for (j = 0; j < 2 * k + 1; j++) {
            cout << "*";
        }

        cout << "\\";

        for (j = 0; j < i - 1; j++) {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}