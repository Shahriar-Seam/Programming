#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j;

    cin >> n;

    for (i = 0, j = 1; i < n; i++) {
        for (j; j % 4 != 0; j++) {
            cout << j << " ";
        }

        cout << "PUM" << "\n";
        j++;
    }

    return 0;
}