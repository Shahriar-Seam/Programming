#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, mex1 = 1, mex2 = 0;;

    cin >> n;

    deque <int> dq(n);

    for (auto &it : dq) {
        cin >> it;
    }

    if (count(dq.begin(), dq.end(), 0) > 1 && count(dq.begin(), dq.end(), 1) == 0) {
        cout << "NO\n";
    }
    else if (count(dq.begin(), dq.end(), 0) == 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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