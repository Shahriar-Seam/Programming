#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        v[i] = 0;
    }

    v[n / 2] = 1;

    for (auto it : v) {
        cout << it;
    }

    cout << "\n";
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