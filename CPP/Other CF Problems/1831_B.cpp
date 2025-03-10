#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count, max_len = 1;

    cin >> n;

    vector <int> a(n), b(n);
    unordered_map <int, int> mp_a, mp_b;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 1, count = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            mp_a[a[i - 1]] = max(mp_a[a[i - 1]], count);

            count = 1;
        }
        else {
            count++;
        }
    }

    mp_a[a[i - 1]] = max(mp_a[a[i - 1]], count);
    
    for (i = 1, count = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            mp_b[b[i - 1]] = max(mp_b[b[i - 1]], count);

            count = 1;
        }
        else {
            count++;
        }
    }

    mp_b[b[i - 1]] = max(mp_b[b[i - 1]], count);

    for (i = 0; i < n; i++) {
        max_len = max({max_len, mp_a[a[i]] + mp_b[a[i]], mp_a[b[i]] + mp_b[b[i]]});
    }

    cout << max_len << "\n";
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