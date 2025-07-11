#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair <int, int> pt;
#define x first
#define y second

int dist(pt p, pt q)
{
    return abs(p.x - q.x) + abs(p.y - q.y);
}

void solve()
{
    int n, k, a, b, d = 0, temp, i;

    cin >> n >> k >> a >> b;

    vector <pt> p(n);

    for (auto &it : p) {
        cin >> it.x >> it.y;
    }

    for (i = 0, temp = 1e12; i < k; i++) {
        temp = min(temp, dist(p[a - 1], p[i]));
    }

    d = temp;

    for (i = 0, temp = 1e12; i < k; i++) {
        temp = min(temp, dist(p[b - 1], p[i]));
    }

    d += temp;

    d = min(d, dist(p[a - 1], p[b - 1]));

    cout << d << "\n";
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