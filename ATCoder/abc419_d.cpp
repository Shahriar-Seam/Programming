#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, r, i;
    string s, t;

    cin >> n >> m >> s >> t;

    vector <int> swapped(n + 5, 0);

    while (m--) {
        cin >> l >> r;

        swapped[l - 1]++;
        swapped[r]--;
    }

    for (i = 1; i <= n; i++) {
        swapped[i] += swapped[i - 1];
    }

    for (i = 0; i < n; i++) {
        if (swapped[i] & 1) {
            swap(s[i], t[i]);
        }
    }

    cout << s << "\n";

    return 0;
}