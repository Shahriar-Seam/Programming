#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int p, s, r;

    cin >> p >> s >> r;

    if (r == 1 || s < p) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}