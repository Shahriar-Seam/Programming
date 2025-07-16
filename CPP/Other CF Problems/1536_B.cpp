#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string s;
    char a, b, c;

    cin >> n >> s;

    for (a = 'a'; a <= 'z'; a++) {
        if (s.find(a) == string::npos) {
            cout << a << "\n";

            return;
        }
    }

    for (a = 'a'; a <= 'z'; a++) {
        for (b = 'a'; b <= 'z'; b++) {
            if (s.find({a, b}) == string::npos) {
                cout << string({a, b}) << "\n";

                return;
            }
        }
    }

    for (a = 'a'; a <= 'z'; a++) {
        for (b = 'a'; b <= 'z'; b++) {
            for (c = 'a'; c <= 'z'; c++) {
                if (s.find({a, b, c}) == string::npos) {
                    cout << string({a, b, c}) << "\n";

                    return;
                }
            }
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