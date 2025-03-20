#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, l = 1;

    for (i = 1; i <= 9; i++) {
        l = lcm(l, i);
    }

    cin >> n;

    vector <int> v(n), current_state(l, 0), next_state(l, 0);
    // dp[i] = number of ways to select product of locations with remainder i

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        for (i = 0; i < l; i++) {
            next_state[(i * it) % l] = (next_state[(i * it) % l] + current_state[i]) % mod;
        }
        
        next_state[it % l]++;
        
        current_state = next_state;
    }

    cout << current_state[0] << "\n";

    return 0;
}