#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 1;

    cin >> n;

    vector <int> v(n), occupied(n + 2, 0);

    for (auto &it : v) {
        cin >> it;
    }

    occupied[v[0]]++;

    for (i = 1; i < n; i++) {
        if (occupied[v[i] + 1] == 1 || occupied[v[i] - 1] == 1) {
            occupied[v[i]]++;
        }
    }

    if (accumulate(occupied.begin(), occupied.end(), 0) == n) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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