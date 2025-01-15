#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 1;
    
    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (__builtin_popcount(v[i]) != __builtin_popcount(i + 1)) {
            f = 0;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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