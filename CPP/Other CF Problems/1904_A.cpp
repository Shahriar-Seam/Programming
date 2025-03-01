#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, xk, yk, xq, yq;
    set <pair <int, int> > k, q, common;

    cin >> a >> b >> xk >> yk >> xq >> yq;

    k.insert({xk + a, yk + b});
    k.insert({xk + a, yk - b});
    k.insert({xk - a, yk + b});
    k.insert({xk - a, yk - b});
    k.insert({xk + b, yk + a});
    k.insert({xk + b, yk - a});
    k.insert({xk - b, yk + a});
    k.insert({xk - b, yk - a});

    q.insert({xq + a, yq + b});
    q.insert({xq + a, yq - b});
    q.insert({xq - a, yq + b});
    q.insert({xq - a, yq - b});
    q.insert({xq + b, yq + a});
    q.insert({xq + b, yq - a});
    q.insert({xq - b, yq + a});
    q.insert({xq - b, yq - a});

    for (auto it : k) {
        if (q.find(it) != q.end()) {
            common.insert(it);
        }
    }

    cout << common.size() << "\n";
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