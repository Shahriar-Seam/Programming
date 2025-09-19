#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, l;

    cin >> n >> m;

    vector <int> v(n), suff(n);
    bitset <100005> s;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            s[v[i]] = 1;

            suff[i] = 1;
        }
        else if (s[v[i]]) {
            suff[i] = suff[i + 1];
        }
        else {
            s[v[i]] = 1;

            suff[i] = suff[i + 1] + 1;
        }
    }

    while (m--) {
        cin >> l;

        cout << suff[l - 1] << "\n";
    }

    return 0;
}