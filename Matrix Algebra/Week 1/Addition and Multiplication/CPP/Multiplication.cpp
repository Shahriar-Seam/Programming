#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // to multiply column number of the first matrix should be equal to the row number of the second matrix
    // this program doesn't account for input/dimension error. it assumes the user will provide correct input
    int m, n, p;
    int i, j, k; // helper variables

    cout << "Enter dimension of the first matrix:\n";
    cin >> m >> n;

    cout << "Enter dimension of the second matrix:\n";
    cin >> n >> p;

    vector <vector <int> > matrix1(m, vector <int> (n));
    vector <vector <int> > matrix2(n, vector <int> (p));
    vector <vector <int> > product(m, vector <int> (p));

    // getting elements
    cout << "Enter elements of the first matrix:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements of the second matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            cin >> matrix2[i][j];
        }
    }

    // multiplication
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < n; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // output
    cout << "The matrix after multiplication:\n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            cout << product[i][j] << " ";
        }

        cout << "\n";        
    }

    return 0;
}