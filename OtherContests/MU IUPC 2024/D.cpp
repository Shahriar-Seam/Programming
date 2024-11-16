#include <bits/stdc++.h>

using namespace std;

int is_nice(int n)
{
    while (n > 0) {
        if ((n % 10 != 6) && (n % 10 != 9)) {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

void solve()
{
    int n, i;

    cin >> n;

    for (i = n; ; i++) {
        if (is_nice(i)) {
            cout << i << "\n";

            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}