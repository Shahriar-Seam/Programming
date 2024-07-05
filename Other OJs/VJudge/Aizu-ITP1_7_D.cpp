#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, p;
    int i, j, k;

    cin >> m >> n >> p;

    vector <vector <long long> > matrix1(m, vector <long long> (n));
    vector <vector <long long> > matrix2(n, vector <long long> (p));
    vector <vector <long long> > product(m, vector <long long> (p));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < n; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            cout << product[i][j];

            if (j < p - 1) {
                cout << " ";
            }
        }

        cout << "\n";        
    }

    return 0;
}