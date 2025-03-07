#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int num_ways(int n, int x, vector <int> &v)
{
    int i, j;
    vector <int> next_state(x + 1, 0); // dp[i + 1]
    vector <int> current_state(x + 1, 0); // dp[i]
    // dp[i][j] = number of ways to make sum j
    // with coins from i to n

    next_state[0] = 1; // dp[n][0] = 1

    for (i = n - 1; i >= 0; i--) {
        current_state[0] = 1;

        for (j = 1; j <= x; j++) {
            current_state[j] = (next_state[j] + (v[i] <= j ? current_state[j - v[i]] : 0)) % mod;
        }

        next_state = current_state;
    }

    return current_state[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }
 
    cout << num_ways(n, x, v) << "\n";
 
    return 0;
}