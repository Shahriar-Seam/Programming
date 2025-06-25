#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, min_index = 1e9;
    string s;

    cin >> n >> s;

    s = "a" + s + "z";

    vector <set <int> > index(26);

    for (i = 1; i < s.size(); i++) {
        index[s[i] - 'a'].insert(i);
    }

    for (i = 1; i < s.size() - 1; i++) {
        if (s[i] > s[i + 1]) {
            for (j = s[i] - 'a' + 1; j < 26; j++) {
                auto it = index[j].lower_bound(i);

                if (it != index[j].end() && *it > 0) {
                    min_index = min(*it, min_index);
                }
            }

            if (min_index != 1e9) {
                s.insert(s.begin() + min_index, s[i]);
                s.erase(i, 1);
            }
            else {
                s.insert(s.begin() + n + 1, s[i]);
                s.erase(i, 1);
            }

            break;
        }
    }

    s.erase(s.begin());
    s.erase(prev(s.end()));

    cout << s << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}