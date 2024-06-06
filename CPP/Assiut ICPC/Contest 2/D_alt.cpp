#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long t, l, r, i, sum, mi, ma;

    cin >> t;

    while (t--) {
        cin >> l >> r;

        mi = min(l, r);
        ma = max(l, r);

        sum = mi + (ma * (ma + 1) / 2) - (mi * (mi + 1) / 2);

        cout << sum << "\n";
    }

    return 0;
}