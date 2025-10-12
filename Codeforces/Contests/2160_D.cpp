#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int k, i, j, x, count = 0;

    cin >> n;

    n *= 2;

    vector <int> v(n + 1, 0), indices(n + 1, -1);
    bitset <700> s;

    for (i = n - 1; i > 0; i--) {
        cout << "? " << n - i + 1 - count << " ";

        for (j = i; j <= n; j++) {
            if (!s[j]) {
                cout << j << " ";
            }
        }

        cout << "\n";

        cout.flush();

        cin >> x;

        if (x != 0) {
            v[i] = x;
            s[i] = true;

            indices[x] = i;

            count++;
        }
    }

    s.reset();
    count = 0;

    for (i = 2; i <= n; i++) {
        cout << "? " << i - count << " ";

        for (j = 1; j <= i; j++) {
            if (!s[j]) {
                cout << j << " ";
            }
        }

        cout << "\n";

        cout.flush();

        cin >> x;

        if (x != 0) {
            v[i] = x;
            s[i] = true;
            s[indices[x]] = true;

            count += 2;
        }
    }

    cout << "! ";

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";

    cout.flush();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}