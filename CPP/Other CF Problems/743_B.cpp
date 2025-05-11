#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;

    cin >> n >> k;

    vector <int> v(n + 1);

    v[0] = v[1] = 0;

    for (i = 2; i <= n; i++) {
        v[i] = (1LL << (i - 1));
    }

    while (!binary_search(v.begin(), v.end(), k)) {
        k -= (1LL << (63 - __builtin_clzll(k)));
    }

    for (i = 1; i <= n; i++) {
        if (v[i] == k) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}