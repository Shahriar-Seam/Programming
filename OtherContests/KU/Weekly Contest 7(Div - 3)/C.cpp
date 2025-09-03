#include <bits/stdc++.h>

using namespace std;

#define int long long

bool knapsack(int n, int w, vector <int> &wt)
{
    int i, j;
    bitset <(int) 1e3 + 5> dp;

    dp[0] = 1;

    for (i = 0; i < n; i++) {
        for (j = w; j >= wt[i]; j--) {
            dp[j] = dp[j] | dp[j - wt[i]];
        }

        if (dp[w]) {
            break;
        }
    }

    return dp[w];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int sum = 0, f = 0;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        sum += it;

        it %= m;

        if (it == 0) {
            f = 1;
        }
    }

    if (n > 2 * m) {
        cout << "YES\n";

        return 0;
    }
    else if ((sum % m == 0) || f) {
        cout << "YES\n";

        return 0;
    }
    else if (sum < m) {
        cout << "NO\n";

        return 0;
    }

    sort(v.begin(), v.end());

    if (knapsack(n, sum % m, v)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}