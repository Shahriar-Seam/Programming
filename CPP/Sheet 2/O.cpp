#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int i, j;

    cin >> n;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}