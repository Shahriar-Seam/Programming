#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> p;

void fill()
{
    int i, j;

    for (i = 0; i < 10; i++) {
        p.push_back(i);
    }

    p.push_back(11);
    p.push_back(22);
}

void solve()
{
    int n;

    cin >> n;

    for (auto &it : p) {
        if ((it <= n) && ((n - it) % 12 == 0)) {
            cout << it << " " << n - it << "\n";

            return;
        }
    }

    cout << "-1\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}