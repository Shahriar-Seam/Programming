#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        long long sum_remaining = 0;
        vector<pair<long long, int>> dp(n + 1, make_pair(0, 1));
        dp[n] = make_pair(0, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            long long total = dp[i + 1].first;
            int count = dp[i + 1].second;
            dp[i] = make_pair(total + array[i], count);
            dp[i] = max(dp[i], make_pair(total + sum_remaining + array[i], count + 1));
            sum_remaining += array[i];
        }

        cout << dp[0].first << endl;
    }

    return 0;
}