#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum, mod = 1e9 + 7, i, j;

    cin >> n;

    sum = (n * (n + 1)) / 2;

    if (sum & 1) {
        cout << 0 << "\n";
    }
    else {
        sum /= 2;

        vector <int> dp(sum + 1, 0);

        dp[0] = 1;

        for (i = 1; i < n; i++) {
            for (j = sum; j >= i; j--) {
                dp[j] = (dp[j] + dp[j - i]) % mod;
            }
        }

        cout << dp[sum] << "\n";
    }

    return 0;
}