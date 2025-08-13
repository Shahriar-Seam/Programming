#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, sum = 0;

    cin >> n;

    vector <int> a(n), b(n), cnt(25, 0);
    vector <int> f(n);

    f[0] = 1;

    for (i = 1; i < n; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (auto &it : a) {
        for (i = 0; i < 25; i++) {
            if (it & (1 << i)) {
                cnt[i]++;
            }
        }
    }

    for (auto &it : b) {
        for (i = 0; i < 25; i++) {
            if (it & (1 << i)) {
                sum += (1 << i) * (n - cnt[i]);
            }
            else {
                sum += (1 << i) * cnt[i];
            }

            sum %= mod;
        }
    }

    cout << (sum * f[n - 1]) % mod << "\n";

    return 0;
}