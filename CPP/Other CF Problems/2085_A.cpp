#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    string str, temp;
    set <char> s;

    cin >> n >> k >> str;

    temp = str;

    reverse(temp.begin(), temp.end());

    for (auto c : str) {
        s.insert(c);
    }

    if (str < temp) {
        cout << "YES" << "\n";
    }
    else if (s.size() > 1 && k > 0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
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