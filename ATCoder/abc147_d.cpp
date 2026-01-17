#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    __int128_t zero, one, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    reverse(v.begin(), v.end());

    for (i = 0; i < 62; i++) {
        zero = one = 0;

        for (auto &it : v) {
            if (it & (1LL << i)) {
                one++;

                sum = (sum + zero * (1LL << i)) % mod;
            }
            else {
                zero++;

                sum = (sum + one * (1LL << i)) % mod;
            }
        }
    }

    cout << (long long) (sum % mod) << "\n";

    return 0;
}