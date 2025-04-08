#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > bleh = {
    {1, 4, 13, 16},
    {3, 2, 15, 14},
    {9, 12, 5, 8},
    {11, 10, 7, 6}
};

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

pair <int, int> index(int k)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (bleh[i][j] == k) {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

void solve()
{
    int n, q;

    cin >> n >> q;

    while (q--) {
        string op;

        cin >> op;

        if (op == "->") {
            int r, c;

            cin >> r >> c;

            int block = ceil_div(r, 4) * ceil_div(c, 4);

            r %= 4;
            c %= 4;

            if (r == 0) {
                r = 4;
            }
            if (c == 0) {
                c = 4;
            }

            r--;
            c--;

            cout << (block - 1) * 16 + bleh[r][c] << "\n";
        }
        else {
            int d;

            cin >> d;

            int block = ceil_div(d, 16);

            int k = d % 16;

            if (k == 0) {
                k = 16;
            }

            auto p = index(k);

            int r, c;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}