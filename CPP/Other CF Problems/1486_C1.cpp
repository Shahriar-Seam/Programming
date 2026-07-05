#include <bits/stdc++.h>

using namespace std;

int query(int l, int r)
{
    int p;

    cout << "? " << l << " " << r << endl;
    cin >> p;

    return p;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int l, r, m, s, x;

    cin >> n;

    l = 1;
    r = n;

    s = query(l, r);

    if (s > 1 && query(1, s) == s) {
        l = 1;
        r = s - 1;

        while (l <= r) {
            m = (l + r) / 2;

            if (query(m, s) == s) {
                x = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    }
    else {
        l = s + 1;
        r = n;

        while (l <= r) {
            m = (l + r) / 2;

            if (query(s, m) == s) {
                x = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
    }

    cout << "! " << x << endl;

    return 0;
}