#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // to add 2 matrices both must have the same dimension
    int m, n;
    int i, j; // helper variables

    cout << "Enter dimension of the matrices:\n";
    cin >> m >> n;

    vector <vector <int> > matrix1(m, vector <int> (n));
    vector <vector <int> > matrix2(m, vector <int> (n));
    vector <vector <int> > addition(m, vector <int> (n));

    // getting elements
    cout << "Enter elements of the first matrix:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of the second matrix:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }

    // addition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            addition[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // output
    cout << "The matrix after addition:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << addition[i][j] << " ";
        }

        cout << "\n";        
    }

    return 0;
}