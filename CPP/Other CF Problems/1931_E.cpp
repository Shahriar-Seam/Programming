#include <bits/stdc++.h>

using namespace std;

int trailling_zeroes(int n)
{
    int count = 0;

    while (n % 10 == 0) {
        count++;
        n /= 10;
    }

    return count;
}

void solve()
{
    int n, m;

    cin >> n >> m;

    vector <int> v(n);
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