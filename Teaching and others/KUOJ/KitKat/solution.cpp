#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int i;
    string s, k = "kitkat";

    cin >> s;

    if (s.size() != 6) {
        cout << "KITKAT NA KHAWAILE, PROBLEM BANAYE DIMU NA!\n";
    }
    else {
        for (i = 0; i < 6; i++) {
            if ((s[i] | 32) ^ k[i]) {
                cout << "KITKAT NA KHAWAILE, PROBLEM BANAYE DIMU NA!\n";

                return;
            }
        }

        cout << "Problem peye gesi!\n";
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