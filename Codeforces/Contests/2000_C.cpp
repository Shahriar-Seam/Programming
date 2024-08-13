#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, f;
    map <int, set <char> > mp_i;
    map <char, set <int> > mp_c;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> m;

    vector <string> vs(m);

    for (auto &it : vs) {
        cin >> it;
    }

    for (auto s : vs) {
        if (s.size() != n) {
            cout << "NO\n";
        }
        else {
            mp_i.clear();
            mp_c.clear();
            f = 1;

            for (i = 0; i < n; i++) {
                mp_i[v[i]].insert(s[i]);
                mp_c[s[i]].insert(v[i]);
            }

            for (auto it : mp_i) {
                if (it.second.size() > 1) {
                    f = 0;

                    break;
                }
            }

            for (auto it : mp_c) {
                if (it.second.size() > 1) {
                    f = 0;

                    break;
                }
            }

            cout << (f == 1 ? "YES\n" : "NO\n");
        }
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