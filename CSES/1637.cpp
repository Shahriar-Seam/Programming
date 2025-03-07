#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <int> dp(n + 1, 1e9);
    // dp[i] = number of steps to convert the number to 0

    dp[0] = 0;

    for (i = 1; i <= n; i++) {
        string s = to_string(i);

        for (auto c : s) {
            dp[i] = min(dp[i], dp[i - c + '0'] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}