#include <bits/stdc++.h>

using namespace std;

#define int long long

bool compare(int a, int b)
{
    return abs(a) > abs(b);
}

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    do {
        double r = v[1] * 1.0 / v[0];
        int f = 1;

        for (i = 1; i < n; i++) {
            if (abs(r - (v[i] * 1.0 / v[i - 1])) > 1e-6) {
                f = 0;

                break;
            }
        }

        if (f) {
            cout << "Yes\n";

            return;
        }

    } while(next_permutation(v.begin(), v.end()));

    cout << "No\n";
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