#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, u, q;
    int l, r, val;
    int index, i;

    cin >> n >> u;

    vector <long long> v(n + 1, 0LL);

    while (u--) {
        cin >> l >> r >> val;

        v[l] += val;
        v[r + 1] -= val;
    }

    for (i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }

    cin >> q;

    while (q--) {
        cin >> index;

        cout << v[index] << "\n";
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