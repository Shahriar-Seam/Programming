#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    char a[200][200];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = '.';
        }
    }
    while (q--)
    {
        int r1, c1, r2, c2;
        char k;
        cin >> r1 >> c1 >> r2 >> c2 >> k;

        if (r1 > r2) {
            swap(r1, r2);
        }

        if (c1 > c2) {
            swap(c1, c2);
        }

        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                a[i][j] = k;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}