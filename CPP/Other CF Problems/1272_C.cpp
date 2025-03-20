#include <bits/stdc++.h>

using namespace std;

#define int long long

int count(vector <bool> &v)
{
    int i;
    vector <int> dp(v.size(), 0);

    dp[0] = v[0];

    for (i = 1; i < v.size(); i++) {
        if (v[i] == 0) {
            dp[i] = 0;
        }
        else {
            dp[i] = dp[i - 1] + 1;
        }

        
    }

    return accumulate(dp.begin(), dp.end(), 0LL);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    string s;
    vector <bool> v;
    set <char> s_c;
    char c;

    cin >> n >> k >> s;

    v.resize(n, false);

    while (k--) {
        cin >> c;

        s_c.insert(c);
    }

    for (i = 0; i < n; i++) {
        if (s_c.find(s[i]) != s_c.end()) {
            v[i] = true;
        }
    }

    cout << count(v) << "\n";

    return 0;
}