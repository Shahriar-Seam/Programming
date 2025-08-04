#include <bits/stdc++.h>

using namespace std;

#define int long long

struct item {
    int a, b, c, d;
};

void solve()
{
    int n, i, count = 0, z = 0, o = 0;

    cin >> n;

    vector <item> v(n);

    for (auto &it : v) {
        cin >> it.a >> it.b >> it.c >> it.d;
    }

    for (auto &it : v) {
        if (it.b > it.d) {
            count += it.a + it.b - it.d;
        }
        else if (it.a > it.c) {
            count += it.a - it.c;
        }
    }

    cout << count << "\n";
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