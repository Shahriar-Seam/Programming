#include <bits/stdc++.h>

using namespace std;

int bleh(map <char, int> mp_m, map <char, int> mp_temp)
{
    for (auto it : mp_m) {
        if (mp_temp[it.first] < it.second) {
            return 0;
        }
    }

    return 1;
}

void solve()
{
    int n, q, count = 0;
    vector <map <char, int> > dict;
    map <char, int> mp_temp;
    string s;

    cin >> n;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp_temp.clear();

        for (auto c : it) {
            mp_temp[c]++;
        }

        dict.push_back(mp_temp);
    }

    cin >> q;

    while (q--) {
        cin >> s;

        mp_temp.clear();
        count = 0;

        for (auto c : s) {
            mp_temp[c]++;
        }

        for (auto it : dict) {
            count += bleh(it, mp_temp);
        }

        cout << count << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}