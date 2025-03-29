#include <bits/stdc++.h>

using namespace std;

int lg(int n, int b)
{
    int count = 0;

    while (n > 0) {
        n /= b;

        count++;
    }

    return count;
}

void solve()
{
    int a, b, count = 0, f = 0, i;

    cin >> a >> b;

    if (b == 1) {
        f = 1;

        b++;

        count++;
    }

    count += lg(a, b);

    for (i = b + 1; i < b + 6; i++) {
        count = min(count, i - b + f + lg(a, i));
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