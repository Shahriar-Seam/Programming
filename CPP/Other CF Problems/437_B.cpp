#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum, limit, i, s = 0;
    map <int, vector <int>, greater <int> > mp;
    vector <int> v;

    cin >> sum >> limit;

    for (i = 1; i <= limit; i++) {
        mp[1 << __builtin_ctzll(i)].push_back(i);
    }

    for (auto &it : mp) {
        while (it.second.size() > 0 && s + it.first <= sum) {
            s += it.first;

            v.push_back(it.second.back());
            it.second.pop_back();
        }
    }

    if (s < sum) {
        cout << -1 << "\n";
    }
    else {
        cout << v.size() << "\n";

        for (auto it : v) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}