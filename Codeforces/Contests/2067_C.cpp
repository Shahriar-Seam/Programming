#include <bits/stdc++.h>

using namespace std;

#define int long long

bool present_7(int n)
{
    while (n > 0) {
        if (n % 10 == 7) {
            return true;
        }

        n /= 10;
    }

    return false;
}

void solve()
{
    int n, i, j, temp, min_ops = 1e9;
    vector <int> v = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999};

    cin >> n;

    if (present_7(n)) {
        cout << 0 << "\n";

        return;
    }

    for (i = 0; i < v.size(); i++) {
        temp = n;

        for (j = 1; j <= 100; j++) {
            temp += v[i];

            if (present_7(temp)) {
                min_ops = min(min_ops, j);
            }
        }
    }

    cout << min_ops << "\n";
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