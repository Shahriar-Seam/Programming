#include <bits/stdc++.h>

using namespace std;

int bleh(string &s, int i)
{
    if (i >= 0 && i < s.size() - 3) {
        return s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
    }
    else {
        return 0;
    }
}

void solve()
{
    string s;
    int q, i, f;
    char v;
    set <int> indices;

    cin >> s >> q;

    for (i = 0; i < s.size() - 3; i++) {
        if (bleh(s, i)) {
            indices.insert(i);
        }
    }

    while (q--) {
        cin >> i >> v;

        i--;
        f = 0;

        if (s[i] != v) {
            if (bleh(s, i)) {
                indices.erase(i);
            }
            else if (bleh(s, i - 1)) {
                indices.erase(i - 1);
            }
            else if (bleh(s, i - 2)) {
                indices.erase(i - 2);
            }
            else if (bleh(s, i - 3)) {
                indices.erase(i - 3);
            }

            s[i] = v;

            if (bleh(s, i)) {
                indices.insert(i);
            }
            else if (bleh(s, i - 1)) {
                indices.insert(i - 1);
            }
            else if (bleh(s, i - 2)) {
                indices.insert(i - 2);
            }
            else if (bleh(s, i - 3)) {
                indices.insert(i - 3);
            }
        }

        cout << (!indices.empty() ? "YES" : "NO") << "\n";
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