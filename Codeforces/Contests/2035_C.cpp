#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k = 0, k2 = 0, i, j, l;

    cin >> n;

    vector <int> v(n), v2(n);

    l = (1 << int(log2(n))) - 1;

    for (i = 1, j = 0; i <= n; i++) {
        if (i != l) {
            v[j++] = i;
        }
        v2[i - 1] = i;
    }

    v[n - 1] = l;

    swap(v[0], v[1]);
    swap(v2[0], v2[1]);

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            k &= v[i];
        }
        else {
            k |= v[i];
        }
    }
    
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            k2 &= v2[i];
        }
        else {
            k2 |= v2[i];
        }
    }

    if (k > k2) {
        cout << k << "\n";

        for (auto it : v) {
            cout << it << " ";
        }
    }
    else {
        cout << k2 << "\n";

        for (auto it : v2) {
            cout << it << " ";
        }
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