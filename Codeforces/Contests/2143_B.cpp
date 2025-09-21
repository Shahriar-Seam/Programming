#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, j, sum = 0;

    cin >> n >> k;

    deque <int> a(n), b(k);

    for (auto &it : a) {
        cin >> it;
    }

    sort(a.begin(), a.end(), greater <> ());

    for (auto &it : b) {
        cin >> it;
    }

    sort(b.begin(), b.end());

    for (i = 0, j = 0; i < k; i++) {
        sum += (b[i] + j - 1 < n ? a[b[i] + j - 1] : 0LL);

        j += b[i];
    }

    cout << accumulate(a.begin(), a.end(), 0LL) - sum << "\n";
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