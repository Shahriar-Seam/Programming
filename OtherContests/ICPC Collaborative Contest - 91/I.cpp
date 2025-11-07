#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, count = 0;

    cin >> n;

    vector <int> a(n), b(n);

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (i = n - 1, j = n - 1; i >= 0 && j >= 0; ) {
        while (i >= 0 && a[i] != b[j]) {
            i--;
        }

        if (i >= 0 && a[i] == b[j]) {
            j--;
        }
        else {
            count = j + 1;

            break;
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