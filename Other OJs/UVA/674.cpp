#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    int i, j;
    vector <int> v = {50, 25, 10, 5, 1};
    vector <int> current_state(n + 1, 0); // dp[i]
    vector <int> next_state(n + 1, 0); // dp[i+1]
    // dp[i][j] = number of ways to make sum j with coins from i to n

    next_state[0] = current_state[0] = 1;

    for (i = 0; i < v.size(); i++) {
        current_state[0] = 1;

        for (j = 1; j <= n; j++) {
            current_state[j] = next_state[j] + (j >= v[i] ? current_state[j - v[i]] : 0);
        }

        next_state = current_state;
    }

    printf("%d\n", current_state[n]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t n;

    while (scanf("%d", &n) != EOF) {
        solve(n);
    }

    return 0;
}