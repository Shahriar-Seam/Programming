#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, b, i, j;

    cin >> n >> a >> b;

    vector <int> A(n), B(n);

    for (i = 0; i < n; i++) {
        A[i] = i + 1;
    }

    for (i = n - 1; i >= a + b; i--) {
        B[i] = i + 1;
    }

    for (i = 0, j = a + 1; i < n; i++, j++) {
        if (j > a + b) {
            j = 1;
        }

        if (!B[i]) {
            B[i] = j;
        }
    }

    for (i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            a--;
        }
        else if (A[i] < B[i]) {
            b--;
        }
    }

    if (a == 0 && b == 0) {
        cout << "YES\n";

        for (i = 0; i < n; i++) {
            cout << A[i] << " ";
        }

        cout << "\n";

        for (i = 0; i < n; i++) {
            cout << B[i] << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
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