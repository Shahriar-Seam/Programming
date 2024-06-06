#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, j, num, ma, mi;
    vector<ll> diff;

    cin >> t;

    while (t--)
    {
        cin >> n;

        ma = LLONG_MIN;
        mi = LLONG_MAX;

        for (i = 0; i < n; i++)
        {
            cin >> num;

            ma = max(ma, num);
            mi = min(mi, num);
        }

        diff.push_back(ma - mi);
        i = 0;

        while (ma != mi)
        {
            if (i < n) {
                ma = (ma + diff[i]) / 2;
                mi = (mi + diff[i]) / 2;
                diff.push_back(ma - mi);
                i++;
            }
            else {
                diff[0] = (ma - mi);
                ma = (ma + diff[0]) / 2;
                mi = (mi + diff[0]) / 2;
                i++;
            }
        }

        if (i == 0 || i > n) {
            cout << i << "\n";
        }
        else {
            cout << i << "\n";

            for (j = 0; j < i; j++) {
                cout << diff[j] << " ";
            }

            cout << "\n";
        }

        diff.clear();
    }

    return 0;
}
