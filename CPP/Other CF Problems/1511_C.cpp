#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, t;

    cin >> n >> q;

    vector <int> v(n), indices(51, -1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 1; i >= 0; i--) {
        indices[v[i]] = i;
    }

    while (q--) {
        cin >> t;

        auto index = indices[t];

        for (auto &it : indices) {
            if (it != -1 && it < index) {
                it++;
            }
        }

        indices[t] = 0;

        cout << index + 1 << " ";
    }

    return 0;
}