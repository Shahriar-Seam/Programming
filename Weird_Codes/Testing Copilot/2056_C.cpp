#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    cout << 1 << " " << 1 << " ";

    for (i = 2; i < n - 1; i++) {
        cout << i << " ";
    }

    cout << 1 << "\n";
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