#include <bits/stdc++.h>

using namespace std;

#define int long long

bool is_square(int n)
{
    int x = sqrt(n + 0.5);

    return x * x == n;
}

void solve()
{
    int n, i, sum = 0, temp, count = 0;

    cin >> n;

    vector <int> v, pref(n + 1, 0);

    if (n == 1) {
        cout << "-1\n";

        return;
    }

    v.push_back(2);

    for (i = n - !(n % 2); i > 0; i -= 2) {
        v.push_back(i);
    }

    for (i = 4; i <= n; i += 2) {
        v.push_back(i);
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 1; i < n; i++) {
        if (is_square(pref[i])) {
            swap(v[i - 1], v[i]);
        }
    }

    if (is_square(accumulate(v.begin(), v.end(), 0LL))) {
        cout << "-1\n";
    }
    else {
        for (i = 0; i < n; i++) {
            cout << v[i] << " ";
        }

        cout << "\n";
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