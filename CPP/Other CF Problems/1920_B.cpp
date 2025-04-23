#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, x, i, sum = 0, neg_sum = 0, max_sum = -1e9;

    cin >> n >> k >> x;

    deque <int> dq(n);

    for (auto &it : dq) {
        cin >> it;

        sum += it;
    }

    sort(dq.begin(), dq.end(), greater <int> ());

    for (i = 0; i < x; i++) {
        neg_sum += dq[i];
    }

    max_sum = sum - neg_sum - neg_sum;

    for (i = 0; i < k; i++) {
        sum -= dq[i];
        neg_sum -= dq[i];

        if (i + x < n) {
            neg_sum += dq[i + x];
        }
        
        max_sum = max(max_sum, sum - 2 * neg_sum);
    }

    cout << max_sum << "\n";
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