#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    if (n & 1) {
        for (i = n - 1; i > n / 2; i--) {
            cout << i << " " << n - i << " ";
        }
        cout << n << "\n";
    }
    else {
        for (i = n; i > n / 2; i--) {
            cout << i << " " << n + 1 - i << " ";
        }
        cout << "\n";
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