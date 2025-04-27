#include <bits/stdc++.h>

using namespace std;

#define int long long

int minimal(int mid, vector <int> v, int n, int k)
{
    int i;

    for (i = 0; i < n; i++) {
        v[i] = abs(v[i] - mid);
    }

    sort(v.begin(), v.end());

    while (k--) {
        v.pop_back();
    }

    return accumulate(v.begin(), v.end(), 0LL);
}

void solve()
{
    int n, k, i;
    int l, r, mid;
    int low = 0, high = 0, min_fx = 1e18;
    int local_min, local_max;

    cin >> n >> k;

    vector <int> v(n), pref(n + 1, 0), fx(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 0; i < n; i++) {
        fx[i] = pref[n] - pref[i] - (n - i) * v[i] + i * v[i] - pref[i];

        min_fx = min(min_fx, fx[i]);
    }

    for (i = 0; i < n; i++) {
        if (fx[i] == min_fx) {
            local_min = v[i];
            break;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        if (fx[i] == min_fx) {
            local_max = v[i];
            break;
        }
    }

    // for (auto it : fx) {
    //     cout << it << " ";
    // }
    // cout << "\n";

    // left
    l = 1, r = local_max;

    while (l <= r) {
        mid = (l + r) / 2;

        if (minimal(mid, v, n, k) <= min_fx) {
            low = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    // right
    l = local_min, r = 1e9;

    while (l <= r) {
        mid = (l + r) / 2;

        if (minimal(mid, v, n, k) <= min_fx) {
            high = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    // cout << minimal(7, v, n, k) << "\n";

    cout << low << " " << high << "\n";
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