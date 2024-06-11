#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector <string> v;
    string s;
    int n, m, i, r = 0, temp, a = 0, b = 0;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> s;

        temp = count(s.begin(), s.end(), '#');

        if (temp > r) {
            r = temp;
            a = i;
        }

        v.push_back(s);
    }

    for (i = 0, temp = 0; i < m; i++) {
        if (v[a][i] == '#') {
            temp++;
        }

        if (temp == ((r + 1) / 2)) {
            b = i;
            break;
        }
    }

    cout << a + 1 << " " << b + 1 << "\n";
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