#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, count = 0, i, j, sum = 0;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = n - 1; i >= 0; i--) {
        if (v[i] >= x) {
            count++;
        }
        else {
            break;
        }
    }

    for (j = i; j >= 0; j--) {
        if (v[j] * (i - j + 1) >= x) {
            count++;

            i = j - 1;
        }
    }

    cout << count << "\n";
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