#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <int> v(n);
    vector <vector <int> > dp, cnt(n + 1, vector <int> (2, 0));

    for (auto &it : v) {
        cin >> it;

        dp.push_back({it / 2, it % 2});
    }

    for (i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            cnt[i] = dp[i];

            continue;
        }

        if (dp[i][0]) {
            cnt[i][0] = max({cnt[i + 1][1], cnt[i + 2][0], cnt[i + 2][1]}) + 1;
        }
        else {
            cnt[i][0] = max(cnt[i + 1][0], cnt[i + 1][1]);
        }

        if (dp[i][1]) {
            cnt[i][1] = max({cnt[i + 1][0], cnt[i + 2][0], cnt[i + 2][1]}) + 1;
        }
        else {
            cnt[i][1] = max(cnt[i + 1][0], cnt[i + 1][1]);
        }
    }

    cout << n - max(cnt[0][0], cnt[0][1]) << "\n";

    return 0;
}