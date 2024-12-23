#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, diff = 0;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n - 1; i++) {
        if (a[i] >= b[i + 1]) {
            diff += a[i] - b[i + 1];
        }
    }

    diff += a[n - 1];

    cout << diff << "\n";
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