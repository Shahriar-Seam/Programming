#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, count = 0, gold = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] >= k) {
            gold += v[i];
        }
        else if (v[i] == 0 && gold > 0) {
            count++;

            gold = max(0, gold - 1);
        }
    }

    cout << count << "\n";
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