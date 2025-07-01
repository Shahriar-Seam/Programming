#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, j, k, p, i;

    cin >> n >> j >> k;

    vector <int> v(n);
    deque <int> dq;

    for (auto &it : v) {
        cin >> it;
    }

    p = v[j - 1];

    sort(v.begin(), v.end(), greater <int> ());

    for (i = 0; i < n; i++) {
        if (v[i] == p) {
            for (i; i >= 0; i--) {
                dq.push_front(v[i]);
            }

            break;
        }
    }

    if (dq.size() <= k) {
        cout << "YES\n";

        return;
    }

    auto t = dq.front();
    dq.pop_front();

    while (dq.size() >= k) {
        dq.pop_front();
    }

    dq.push_front(t);

    cout << (dq.back() <= p ? "YES" : "NO") << "\n";
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