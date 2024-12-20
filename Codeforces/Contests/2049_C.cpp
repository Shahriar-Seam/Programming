#include <bits/stdc++.h>

using namespace std;

int mex(int a, int b, int c)
{
    set <int> s;

    s.insert(a);
    s.insert(b);
    s.insert(c);

    for (int i = 0; i < 5; i++) {
        if (s.find(i) == s.end()) {
            return i;
        }
    }

    return 0;
}

int mex(int a, int b)
{
    set <int> s;

    s.insert(a);
    s.insert(b);

    for (int i = 0; i < 5; i++) {
        if (s.find(i) == s.end()) {
            return i;
        }
    }

    return 0;
}

void solve()
{
    int n, x, y, i;

    cin >> n >> x >> y;

    vector <int> v(n + 2, -1);

    for (i = 1; i <= n; i++) {
        v[i] = (i % 2);
    }

    if (n % 2 == 1) {
        v[n] = 0;
        v[n - 1] = -1;
    }

    v[0] = v[n];
    v[n + 1] = v[1];

    v[x] = mex(v[x - 1], v[x + 1], max(0, v[y]));
    v[y] = mex(v[y - 1], v[y + 1], v[x]);

    for (i = 1; i <= n; i++) {
        if (v[i] == -1) {
            v[i] = mex(v[i - 1], v[i + 1]);
        }
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}