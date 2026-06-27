#include <bits/stdc++.h>

using namespace std;

#define int long long

int cost(vector <int> &v, int n, int a, int r, int m, int h)
{
    int need = 0, extra = 0, i;
    int c1, c2;

    for (auto &it : v) {
        if (it < h) {
            need += h - it;
        }
        else if (it > h) {
            extra += it - h;
        }
    }

    c1 = need * a + extra * r;
    c2 = min(need, extra) * m + ((need > extra) ? ((need - extra) * a) : ((extra - need) * r));

    return min(c1, c2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, A, R, M;
    int l = 0, r = 0, m1, m2, c1, c2, i, c = 1e18;

    cin >> n >> A >> R >> M;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        r = max(r, it);
    }

    for (i = 0; i < 50; i++) {
        m1 = (l + r) / 2;
        m2 = m1 + 1;

        c1 = cost(v, n, A, R, M, m1);
        c2 = cost(v, n, A, R, M, m2);

        if (c1 > c2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }

    for (i = l; i <= r; i++) {
        c = min(c, cost(v, n, A, R, M, i));
    }

    cout << c << "\n";

    return 0;
}