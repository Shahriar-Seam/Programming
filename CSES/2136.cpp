#pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, min_pop = 40;
    string s;

    cin >> n >> k;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> s;

        v[i] = stoi(s, 0, 2);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            min_pop = min(min_pop, __builtin_popcount(v[i] ^ v[j]));
        }
    }

    cout << min_pop << "\n";

    return 0;
}