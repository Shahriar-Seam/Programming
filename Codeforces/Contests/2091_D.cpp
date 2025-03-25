#include <bits/stdc++.h>

using namespace std;

#define int long long

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

bool possible(int m, int p, int mid)
{
    int num_patches = (m + 1) / (mid + 1);
    int seated = num_patches * mid;

    p -= seated;

    int occupied = num_patches * (mid + 1) - 1;

    if (m - occupied > p || p == 0) {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    int n, m, k;

    cin >> n >> m >> k;

    int p = ceil_div(k, n), len = 0;

    int l = 1, r = 1e12, mid;

    while (l <= r) {
        mid = (l + r) / 2;

        if (possible(m, p, mid)) {
            len = mid;

            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << len << "\n";
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