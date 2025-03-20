#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int recurse(string &s, int index, vector <int> &memo)
{
    if (index < 0) {
        return 1;
    }

    int i, j;

    if (memo[index] == -1) {
        memo[index] = 0;

        if (s[index] != s[index + 1]) {
            i = min(s[index], s[index + 1]);
            j = max(s[index], s[index + 1]);

            for (i, j; i <= j; i++) {
                memo[index] = (1LL * memo[index] + recurse(s, index - 1, memo)) % mod;
            }
        }
        else {
            for (i = 'a'; i <= 'z'; i++) {
                if (s[index] != i) {
                    memo[index] = (1LL * memo[index] + recurse(s, index - 1, memo)) % mod;
                }
            }
        }
    }

    return memo[index];
}

void solve()
{
    string s;

    cin >> s;

    vector <int> memo(s.size() + 1, -1);

    cout << recurse(s, s.size() - 2, memo) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}