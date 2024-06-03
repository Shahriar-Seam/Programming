#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, cnt = 0;
    string s;
    map <char, int> mp;
    vector <char> v = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    for (auto it : v) {
        mp[it] = 0;
    }

    cin >> n >> m >> s;

    for (auto c : s) {
        mp[c]++;
    }

    for (auto it : mp) {
        if (it.second < m) {
            cnt += m - it.second;
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