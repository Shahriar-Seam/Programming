#include <bits/stdc++.h>

using namespace std;

bool valid(int n, int a, int b, vector <int> &v1, vector <int> &v2)
{
    int w1 = 0, w2 = 0, i;

    for (i = 0; i < n; i++) {
        if (v1[i] > v2[i]) {
            w1++;
        }
        else if (v1[i] < v2[i]) {
            w2++;
        }
    }

    return w1 == a && w2 == b;
}

void solve()
{
    int n, a, b, i, j;

    cin >> n >> a >> b;

    if (a + b > n) {
        cout << "NO\n";

        return;
    }

    vector <int> v(n), v2(n, 0);
    set <int> s;

    for (i = 1; i <= n; i++) {
        v[i - 1] = i;

        s.insert(i);
    }

    // draw
    for (i = b, j = b + 1; i < n - a; i++, j++) {
        v2[i] = j;

        s.erase(j);
    }

    while (s.size() > b) {
        s.erase(s.begin());
    }

    // 2win
    for (i = 0; i < b; i++) {
        v2[i] = *s.begin();

        s.erase(s.begin());
    }

    for (i = 1; i <= n; i++) {
        if (find(v2.begin(), v2.end(), i) == v2.end()) {
            s.insert(i);
        }
    }

    // 1win
    for (i = n - a; i < n; i++) {
        v2[i] = *s.begin();

        s.erase(s.begin());
    }

    if (valid(n, a, b, v, v2)) {
        cout << "YES\n";

        for (auto it : v) {
            cout << it << " ";
        }

        cout << "\n";

        for (auto it : v2) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
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