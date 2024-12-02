#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, points = 0;
    map <int, int> mp;
    vector <int> counts;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        counts.push_back(it.second);
    }

    sort(counts.begin(), counts.end());

    for (i = 0; i < counts.size(); i++) {
        if (counts[i] == 1 && (i % 2 == 0)) {
            points += 2;
        }
        else if (counts[i] != 1) {
            points++;
        }
    }

    cout << points << "\n";
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