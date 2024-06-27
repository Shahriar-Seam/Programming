#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int t, l, r;

    cin >> n;

    vector <int> v(n), u;
    vector <long long> prefix_v(n + 1), prefix_u(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    u = v;

    sort(begin(u), end(u));

    for (i = 0; i < n; i++) {
        prefix_u[i + 1] = prefix_u[i] + u[i];
        prefix_v[i + 1] = prefix_v[i] + v[i];
    }

    cin >> m;

    while (m--) {
        cin >> t >> l >> r;

        if (t == 1) {
            cout << prefix_v[r] - prefix_v[l - 1] << "\n";
        }
        else {
            cout << prefix_u[r] - prefix_u[l - 1] << "\n";
        }
    }

    return 0;
}