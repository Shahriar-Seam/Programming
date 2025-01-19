#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (v[0] > v[1]) {
        cout << "NO\n";

        return;
    }

    for (i = 0; i < n - 1; i++) {
        temp = min(v[i], v[i + 1]);

        v[i] -= temp;
        v[i + 1] -= temp;
    }

    cout << (is_sorted(v.begin(), v.end()) ? "YES" : "NO") << "\n";
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