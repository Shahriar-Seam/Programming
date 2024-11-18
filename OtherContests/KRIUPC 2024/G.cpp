#include <bits/stdc++.h>

using namespace std;

int mex(set <int> &s)
{
    int i = 1;

    for (auto it : s) {
        if (i != it) {
            return i;
        }

        i++;
    }

    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char op;
    string s;
    map <string, set <int> > mp;

    cin >> n;

    while (n--) {
        cin >> op >> s;

        if (op == 'a') {
            if (mp.find(s) == mp.end()) {
                mp[s] = {};

                cout << "OK\n";
            }
            else {
                int m = mex(mp[s]);

                mp[s].insert(m);

                cout << s << m << "\n";
            }
        }
        else {
            auto it = mp.find(s);

            if (it != mp.end()) {
                if (it->second.size() > 1) {
                    it->second.erase(it->second.begin());
                }
                else {
                    mp.erase(it);
                }

                cout << "DELETED\n";
            }
            else {
                cout << "INVALID\n";
            }
        }
    }

    return 0;
}