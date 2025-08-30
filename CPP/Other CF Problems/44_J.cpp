#include <bits/stdc++.h>

using namespace std;

void color(vector <string> &t, int i1, int j1, int i2, int j2, int i3, int j3)
{
    set <char> s;
    char c;

    s.insert(t[i1][j1 - 1]);
    s.insert(t[i1][j1 + 1]);
    s.insert(t[i1 - 1][j1]);
    s.insert(t[i1 + 1][j1]);
    
    s.insert(t[i2][j2 - 1]);
    s.insert(t[i2][j2 + 1]);
    s.insert(t[i2 - 1][j2]);
    s.insert(t[i2 + 1][j2]);

    s.insert(t[i3][j3 - 1]);
    s.insert(t[i3][j3 + 1]);
    s.insert(t[i3 - 1][j3]);
    s.insert(t[i3 + 1][j3]);

    for (c = 'a'; ; c++) {
        if (s.find(c) == s.end()) {
            t[i1][j1] = c;
            t[i2][j2] = c;
            t[i3][j3] = c;

            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, u = 1, l = 1, f = 1;

    cin >> n >> m;

    vector <string> v(n + 3), t(n + 3, string(m + 3, '.'));

    v[0] = string(m + 3, '.');
    v[n + 1] = string(m + 3, '.');
    v[n + 2] = string(m + 3, '.');

    for (i = 1; i <= n; i++) {
        cin >> v[i];

        v[i].insert(v[i].begin(), '.');
        v[i].push_back('.');
        v[i].push_back('.');
    }

    while (u <= n && l <= m) {
        for (i = l; i <= m; i++) {
            if (v[u][i] == 'b' && t[u][i] == '.') {
                if (v[u][i - 1] == 'w' && v[u][i + 1] == 'w' && t[u][i - 1] == '.' && t[u][i + 1] == '.') {
                    color(t, u, i - 1, u, i, u, i + 1);
                }
                else {
                    f = 0;
                }
            }
        }

        for (i = u; i <= n; i++) {
            if (v[i][l] == 'b' && t[i][l] == '.') {
                if (v[i - 1][l] == 'w' && v[i + 1][l] == 'w' && t[i - 1][l] == '.' && t[i + 1][l] == '.') {
                    color(t, i - 1, l, i, l, i + 1, l);
                }
                else {
                    f = 0;
                }
            }
        }

        for (i = l; i <= m; i++) {
            if (v[u][i] == 'w' && t[u][i] == '.') {
                if (v[u + 1][i] == 'b' && v[u + 2][i] == 'w' && t[u + 1][i] == '.' && t[u + 2][i] == '.') {
                    color(t, u, i, u + 1, i, u + 2, i);
                }
                else {
                    f = 0;
                }
            }
        }

        for (i = u; i <= n; i++) {
            if (v[i][l] == 'w' && t[i][l] == '.') {
                if (v[i][l + 1] == 'b' && v[i][l + 2] == 'w' && t[i][l + 1] == '.' && t[i][l + 2] == '.') {
                    color(t, i, l, i, l + 1, i, l + 2);
                }
                else {
                    f = 0;
                }
            }
        }

        u++;
        l++;
    }

    if (f == 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << t[i][j];
            }

            cout << "\n";
        }
    }

    return 0;
}