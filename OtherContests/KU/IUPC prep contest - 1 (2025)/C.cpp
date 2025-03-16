#include <bits/stdc++.h>

using namespace std;

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, j, g = 0, max_element = 0, x, y = 1e15, z;
    int l, r, cost;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0), indices;

    for (auto &it : v) {
        cin >> it;

        g = gcd(g, it);
        max_element = max(max_element, it);
    }

    if (g > 1) {
        cout << 0 << " " << g << "\n";

        return;
    }

    sort(v.begin(), v.end());

    indices.resize(2 * max_element + 1, -1);

    for (i = 0; i < n; i++) {
        indices[v[i]] = i + 1;
    }

    for (i = 1; i <= 2 * max_element; i++) {
        if (indices[i] == -1) {
            indices[i] = max(0, indices[i - 1]);
        }
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i] * v[i];
    }

    for (g = 2; g <= max_element; g++) {
        cost = 0;

        l = 0;

        for (j = 1; j * g <= max_element + g; j++) {
            r = indices[j * g];
            
            cost += (r - l) * j * g * j * g - (pref[r] - pref[l]);
            
            l = r;
        }

        if (cost <= y) {
            y = cost;
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