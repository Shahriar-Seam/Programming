#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j;

    cin >> n;

    deque <int> v, h;

    h.push_back(1);
    v.push_back(1);

    for (i = 1; i < 2 * n - 1; i++) {
        if (i % 2 == 0) {
            h.push_front(2 * i + 1);
            v.push_back(2 * i);
        }
        else {
            h.push_back(2 * i + 1);
            v.push_front(2 * i);
        }
    }

    for (i = 0; i < 2 * n - 1; i++) {
        for (j = 0; j < 2 * n - 1; j++) {
            if (i == n - 1) {
                cout << h[j] << " ";
            }
            else if (j == n - 1) {
                cout << v[i] << " ";
            }
            else {
                cout << 0 << " ";
            }
        }

        cout << "\n";
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