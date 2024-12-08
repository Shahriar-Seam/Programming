#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x = 1, n, count = 1;

    cin >> n;

    while (x < n) {
        x = 2 * x + 2;
        count++;
    }

    cout << count << "\n";
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