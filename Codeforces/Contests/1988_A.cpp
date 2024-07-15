#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, op = 0;

    cin >> n >> k;

    while (n > 1) {
        n -= k - 1;

        op++;
    }

    cout << op << "\n";
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