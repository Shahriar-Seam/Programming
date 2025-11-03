#include <bits/stdc++.h>

using namespace std;

vector <int> prefix_function(string s)
{
    int n = s.size(), i, j;
    vector <int> pi(n, 0);

    for (i = 1; i < n; i++) {
        j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

void solve()
{
    string a, b, t;
    int i;

    cin >> a >> b;

    vector <int> pi = prefix_function(b + "#" + a + a);

    for (i = 0; i < pi.size(); i++) {
        if (pi[i] == a.size()) {
            cout << i - 2 * a.size() << "\n";

            return;
        }
    }

    cout << "-1\n";
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