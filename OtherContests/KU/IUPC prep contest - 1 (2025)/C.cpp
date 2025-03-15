#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, g = 0, max_element = 0, count = 0, x, y = 1e15, z, temp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        g = gcd(g, it);
        max_element = max(max_element, it);
    }

    if (g > 1) {
        cout << 0 << " " << g << "\n";

        return;
    }

    for (i = 2; i <= max_element; i++) {
        g = i;
        temp = 0;

        for (auto it : v) {
            if (it % g != 0) {
                x = it + g - (it % g);

                temp += abs(it + x) * abs(it - x);
            }
        }

        if (temp <= y) {
            y = temp;
            z = g;
        }
    }

    cout << y << " " << z << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}