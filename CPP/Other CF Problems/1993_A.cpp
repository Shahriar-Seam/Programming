#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, cnt = 0;
    string s;
    map <char, int> mp;

    cin >> n >> s;

    for (auto c : s) {
        mp[c]++;
    }

    for (auto it : mp) {
        if (it.first != '?') {
            cnt += min(it.second, n);
        }
    }

    cout << cnt << "\n";
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