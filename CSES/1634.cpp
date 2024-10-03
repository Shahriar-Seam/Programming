#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x;
    int i, j;

    cin >> n >> x;

    vector <long long> v(n);
    vector <long long> dp(x + 5);

    for (auto &it : v) {
        cin >> it;
    }

    fill(dp.begin(), dp.end(), LONG_LONG_MAX - 5);

    dp[0] = 0;

    for (i = 1; i <= x; i++) {
        for (j = 0; j < n; j++) {
            if (i - v[j] >= 0) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    cout << (dp[x] == LONG_LONG_MAX - 5 ? -1 : dp[x]) << "\n";

    return 0;
}