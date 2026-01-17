#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, one;
    string s;
    vector <int> v;

    cin >> n >> s;

    if (s.find("10") == string::npos) {
        cout << "Bob\n";

        return;
    }

    one = count(s.begin(), s.end(), '1');

    for (i = n - 1; i >= 0 && one > 0; i--) {
        if (s[i] == '0') {
            v.push_back(i + 1);
        }

        one--;
    }

    for (i; i >= 0; i--) {
        if (s[i] == '1') {
            v.push_back(i + 1);
        }
    }

    cout << "Alice\n" << v.size() << "\n";

    reverse(v.begin(), v.end());

    for (auto &it : v) {
        cout << it << " ";
    }
    cout << "\n";
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