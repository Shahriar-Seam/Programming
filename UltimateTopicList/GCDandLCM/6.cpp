#include <bits/stdc++.h>

using namespace std;

int v_gcd(vector <int> &v)
{
    int i, g = 0;

    for (i = 0; i < v.size(); i++) {
        g = __gcd(g, v[i]);
    }

    return g;
}

void solve()
{
    int n, i, j, g = 0, cost = INT_MAX;

    cin >> n;

    vector <int> v(n), v_temp;
    set <int> s;

    for (auto &it : v) {
        cin >> it;
    }

    g = v_gcd(v);

    if (g == 1) {
        cout << 0 << "\n";

        return;
    }

    for (i = n - 1; i >= 0; i--) {
        v_temp = v;

        v_temp[i] = __gcd(v_temp[i], i + 1);

        g = v_gcd(v_temp);

        if (g == 1) {
            cost = min(cost, n - i);
        }

        for (j = n - 1; j >= 0; j--) {
            if (__gcd(__gcd(v_temp[j], j + 1), g) == 1) {
                break;
            }
        }

        cost = min(cost, n - j + n - i);
    }

    cout << cost << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}