#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp, count = 0;
    map <int, int> mp;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        mp[temp]++;
    }

    for (auto it : mp) {
        count += it.second / 2;
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