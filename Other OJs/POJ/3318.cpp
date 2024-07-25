#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;

    cin >> n;

    vector <vector <int> > A(n, vector <int> (n));
    vector <vector <int> > B(n, vector <int> (n));
    vector <vector <int> > C(n, vector <int> (n));
    vector <vector <int> > AB(n, vector <int> (n));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    if (AB == C) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}