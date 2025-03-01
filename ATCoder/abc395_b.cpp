#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, p, q;

    cin >> n;

    vector <vector <char> > v(n, vector <char> (n));

    for (i = 0; i < n; i++) {
        for (j = n - i - 1; j >= 0; j--) {
            if (i <= j) {
                for (p = i; p <= j; p++) {
                    for (q = i; q <= j; q++) {
                        if (i % 2 == 0) {
                            v[p][q] = '#';
                        }
                        else {
                            v[p][q] = '.';
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << v[i][j];
        }

        cout << "\n";
    }

    return 0;
}