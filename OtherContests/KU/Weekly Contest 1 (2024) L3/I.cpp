#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 0;

    cin >> n;

    vector <int> v(n - 1), a;

    for (auto &it : v) {
        cin >> it;
    }

    a.push_back(v[0]);
    a.push_back(v[0]);

    for (i = 1; i < n - 1; i++) {
        if (max(a.back(), v[i]) != v[i]) {
            a[a.size() - 1] = v[i];
        }

        a.push_back(v[i]);
    }

    for (auto it : a) {
        cout << it << " ";
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