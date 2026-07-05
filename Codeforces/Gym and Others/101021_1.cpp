#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l = 1, r = 1e6, m, x;
    string s;

    while (l <= r) {
        m = (l + r) / 2;

        cout << m << endl;

        cin >> s;

        if (s == ">=") {
            x = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << "! " << x << endl;

    return 0;
}