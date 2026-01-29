#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j = 0, k = 0, sz;
    vector <vector <int> > mask = {
        {1, 3, 5, 2, 4},
        {1, 3, 5, 2, 4, 6},
        {1, 3, 5, 2, 6, 4, 7},
        {1, 3, 5, 2, 6, 8, 4, 7},
        {1, 3, 5, 2, 4, 7, 9, 6, 8}
    };
    
    cin >> n;

    int v[n];

    if (n == 1) {
        cout << 1 << "\n";
    }
    else if (n <= 3) {
        cout << "NO SOLUTION\n";
    }
    else if (n == 4) {
        cout << "2 4 1 3\n";
    }
    else {
        sz = (n / 5 - 1) * 5;

        for (i = 0; i < sz; i++) {
            if ((i > 0) && ((i % 5) == 0)) {
                k += 5;
            }

            v[j++] = mask[0][i % 5] + k;
        }

        if (n >= 10) {
            k += 5;
        }

        for (i = 0; i < 5 + n % 5; i++) {
            v[j++] = mask[n % 5][i] + k;
        }

        for (auto &it : v) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}