#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int k, i;

    cin >> n;

    vector <int> v(n + 1, 0);

    for (k = 1; k <= n; k++) {
        for (i = k; i <= n; i += k) {
            v[i] = (n / k) * k;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
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