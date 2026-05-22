#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_exp(int b, int p, int m = 1e18)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector <int> v(k);

    for (auto &it : v) {
        cin >> it;
    }

    cout << bin_exp(k, n) << "\n";

    return 0;
}