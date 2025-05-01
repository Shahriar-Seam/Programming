#include <bits/stdc++.h>

using namespace std;

#define int long long

int popcount(int n)
{
    int pop = 0;

    while (n) {
        if (n & 1LL) {
            pop++;
        }

        n >>= 1;
    }

    return pop;
}

void solve()
{
    int n, x, pop;

    cin >> n >> x;

    pop = popcount(x);

    if (pop >= n) {
        cout << x << "\n";

        return;
    }

    if (x == 1) {
        if (n % 2 == 0) {
            cout << 3 + n << "\n";
        }
        else {
            cout << n << "\n";
        }
    }
    else if (x == 0) {
        if (n == 1) {
            cout << -1 << "\n";
        }
        else if (n % 2 == 0) {
            cout << n << "\n";
        }
        else {
            cout << n + 3 << "\n";
        }
    }
    else if (((n - pop) % 2) == 0) {
        cout << x + n - pop << "\n";
    }
    else {
        cout << x + n - pop + 1 << "\n";
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