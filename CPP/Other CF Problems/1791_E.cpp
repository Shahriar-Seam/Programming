#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, neg = 0, zero = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        if (it < 0) {
            neg++;

            it = -it;
        }

        if (it == 0) {
            zero++;
        }
    }

    if (neg % 2 == 0) {
        cout << accumulate(v.begin(), v.end(), 0LL) << "\n";
    }
    else {
        if (zero > 0) {
            cout << accumulate(v.begin(), v.end(), 0LL) << "\n";
        }
        else {
            cout << accumulate(v.begin(), v.end(), 0LL) - 2 * *min_element(v.begin(), v.end()) << "\n";
        }
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