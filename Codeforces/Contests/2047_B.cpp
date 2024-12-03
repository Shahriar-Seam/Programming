#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s;
    map <char, int> mp;
    vector <pair <int, char> > v;

    cin >> n >> s;

    for (auto c : s) {
        mp[c]++;
    }

    for (auto it : mp) {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), greater <pair <int, char> > ());

    if (v.size() == 1) {
        cout << s << "\n";
    }
    else {
        for (i = 0; i < n; i++) {
            if (s[i] == v.back().second) {
                s[i] = v[0].second;

                break;
            }
        }

        cout << s << "\n";
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