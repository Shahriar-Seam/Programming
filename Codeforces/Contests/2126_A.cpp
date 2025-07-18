#include <bits/stdc++.h>

using namespace std;

bool common(string a, string b)
{
    for (auto &c : a) {
        if (b.find(c) != string::npos) {
            return true;
        }
    }

    return false;
}

void solve()
{
    int x, y;

    cin >> x;

    for (y = 0; ; y++) {
        if (common(to_string(x), to_string(y))) {
            cout << y << "\n";

            break;
        }
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