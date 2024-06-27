#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;

    cin >> n >> k;

    vector <int> prefix(k), v;

    for (auto &it : prefix) {
        cin >> it;
    }

    for (i = k - 1; i > 0; i--) {
        v.push_back(prefix[i] - prefix[i - 1]);
    }

    v.push_back(prefix[i]);

    reverse(begin(v), end(v));
    
    cout << (is_sorted(begin(v), end(v)) ? "YES\n" : "NO\n");
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