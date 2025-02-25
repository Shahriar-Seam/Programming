#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, max_val = 0;

    cin >> n;

    vector <int> v(n);
    unordered_map <int, int> counter, factor;

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        max_val = max(max_val, it);

        counter[it]++;
    }

    if (max_val > 2 * n) {
        for (auto it : counter) {
            max_val = max(max_val, it.first + it.second);
        }
        
        cout << max_val << "\n";
        
        return;
    }
    
    max_val = n + 1;
    
    for (i = 2; i <= 2 * n; i++) {
        for (j = i; j <= 2 * n; j += i) {
            if (counter.find(j) != counter.end()) {
                factor[i] += counter[j];
            }
        }
    }
    
    for (auto it : factor) {
        max_val = max(max_val, it.first + it.second);
    }
    
    cout << max_val << "\n";
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