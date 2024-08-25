#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    string s, ss = "";
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

    while (v.size() > 0) {
        for (i = 0; i < v.size(); i++) {
            ss += v[i].second;
            v[i].first--;

            if (v[i].first == 0) {
                v.erase(v.begin() + i);

                i--;
            }
        }
    }

    cout << ss << "\n";
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