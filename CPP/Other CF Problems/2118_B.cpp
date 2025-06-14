#include <bits/stdc++.h>

using namespace std;

struct item {
    int a, b, c;
};

void test(int n, vector <item> &v)
{
    vector <vector <int> > d(n, vector <int> (n));
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            d[i][j] = j + 1;
        }
    }
    
    for (auto it : v) {
        reverse(d[it.a - 1].begin() + it.b - 1, d[it.a - 1].begin() + it.c);
    }

    for (auto &it : d) {
        for (auto &jt : it) {
            cout << jt << " ";
        }

        cout << "\n";
    }
}

void solve()
{
    int n, i;

    cin >> n;

    vector <item> v;

    v.push_back({1, 1, n});

    for (i = 2; i <= n; i++) {
        v.push_back({i, 1, n - i + 1});
        v.push_back({i, n - i + 2, n});
    }

    // cout << v.size() << "\n";

    // for (auto it : v) {
    //     cout << it.a << " " << it.b << " " << it.c << "\n";
    // }

    test(n, v);

    cout << "\n";
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