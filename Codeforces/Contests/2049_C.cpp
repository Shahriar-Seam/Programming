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
    int n, x, y, i, j;

    cin >> n >> x >> y;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        v[(x - 1 + i) % n] = i % 2;
    }

    if ((n & 1) || !((y - x) & 1)) {
        v[x - 1] = 2;
    }

    for (i = 0; i < n; i++) {
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