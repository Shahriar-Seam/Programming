#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    deque <int> v(n), dq(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        dq[i] = i + 1;
    }

    while (!dq.empty()) {
        if (v.front() == dq.front()) {
            v.pop_front();
            dq.pop_front();
        }
        else if (v.back() == dq.front()) {
            v.pop_back();
            dq.pop_front();
        }
        else {
            break;
        }
    }

    cout << (dq.empty() ? "YES" : "NO") << "\n";
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