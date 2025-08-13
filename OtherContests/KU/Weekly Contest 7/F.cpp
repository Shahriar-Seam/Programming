#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, mask, count = 0;
    __int128_t d;

    cin >> n >> k;

    vector <int> v(k);

    for (auto &it : v) {
        cin >> it;
    }

    for (mask = 1; mask < (1LL << k); mask++) {
        d = 1;

        for (i = 0; i < k; i++) {
            if (mask & (1LL << i)) {
                d *=  __int128_t(v[i]);
            }

            if (d > n) {
                break;
            }
        }

        if (__builtin_popcountll(mask) & 1) {
            count += n / d;
        }
        else {
            count -= n / d;
        }
    }

    cout << count << "\n";

    return 0;
}