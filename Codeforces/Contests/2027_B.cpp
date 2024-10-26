#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, count = 0, min_count = int(1e9);

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        count  = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                count++;
            }
        }

        min_count = min(min_count, count);
    }

    cout << min_count << "\n";
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