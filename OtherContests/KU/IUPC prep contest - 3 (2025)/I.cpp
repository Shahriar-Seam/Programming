#include <bits/stdc++.h>

using namespace std;

void to_bin(int n)
{
    stringstream ss;

    ss << bitset<32>(n);

    cout << ss.str() << "\n";
}

void solve()
{
    int n, i, x;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    for (x = 0; x < 20; x++) {
        temp = v;

        for (i = 0; i < n; i++) {
            temp[i] ^= x;
        }

        if (is_sorted(temp.begin(), temp.end())) {
            // to_bin(x);

            cout << x << ": ";

            for (i = 0; i < n; i++) {
                cout << temp[i] << " ";
            }

            cout << "\n";
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
        cout << "Case " << i << ":\n";

        solve();
    }

    return 0;
}