#include <stdio.h>

int _min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
    int i, j, n = 80;
    long long int mat[n][n];

    freopen("matrix.txt", "r", stdin);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lld", &mat[i][j]);
        }
    }

    for (i = 1; i < n; i++) {
        mat[0][i] += mat[0][i - 1];
    }

    for (i = 1; i < n; i++) {
        mat[i][0] += mat[i - 1][0];
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            mat[i][j] += _min(mat[i - 1][j], mat[i][j - 1]);
        }
    }

    printf("%lld\n", mat[79][79]);

    return 0;
}