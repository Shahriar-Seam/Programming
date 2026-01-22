#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, cost1 = 0, cost2 = 0;
    string s, t;

    cin >> n >> k >> s >> t;

    for (i = 0; i < n; i++) {
        cost1 += abs(s[i] - t[i]);
    }
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (i = 0; i < n; i++) {
        cost2 += abs(s[i] - t[i]);
    }

    cout << min(cost1, k + cost2) << "\n";

    return 0;
}