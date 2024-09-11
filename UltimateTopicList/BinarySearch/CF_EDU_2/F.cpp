#include <bits/stdc++.h>

using namespace std;

string t, p;
vector <int> v;

bool possible(int m)
{
    if (m >= t.size() - p.size()) {
        return false;
    }

    set <int> s;
    int i, j;

    for (i = 0; i < m; i++) {
        s.insert(v[i]);
    }

    for (i = 0, j = 0; i < t.size(); i++) {
        if (s.find(i + 1) == s.end()) {
            if (t[i] == p[j]) {
                j++;
            }

            if (j == t.size()) {
                return true;
            }
        }
    }

    return j == p.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> p;

    v.resize(t.size());
    
    int l = 0, r = t.size(), m, i;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < 20; i++) {
        m = (l + r) / 2;

        if (possible(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << l << "\n";

    return 0;
}