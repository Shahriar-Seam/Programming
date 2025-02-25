#include <bits/stdc++.h>

using namespace std;

#define int long long

map <deque <int>, int> memo;

int recurse(deque <int> dq)
{
    if (dq.empty()) {
        return 0;
    }

    if (dq.size() == 1) {
        memo[dq] = dq.front();

        return dq.front();
    }

    if (memo.find(dq) == memo.end()) {
        deque <int> temp1, temp2;
        int a, b;

        temp1 = dq;

        a = temp1.front();
        temp1.pop_front();
        b = temp1.front();
        temp1.pop_front();

        temp2 = temp1;

        temp1.push_front(max(0LL, a - b));
        temp2.push_front(max(0LL, b - a));

        memo[dq] = min(recurse(temp1), recurse(temp2));
    }

    return memo[dq];
}

void solve()
{
    int n, max_val = 0, max_ind = 0, i, j;
    int max_power = 0;

    cin >> n;

    vector <int> v(n);
    deque <int> dq1, dq2;

    for (auto &it : v) {
        cin >> it;
    }
    
    if (n == 1) {
        cout << v[0] << "\n";

        return;
    }
    
    if (n == 2) {
        cout << abs(v[0] - v[1]) << "\n";

        return;
    }

    for (i = 0, max_val = v[0]; i < n; i++) {
        max_val = max(max_val, v[i]);
    }

    for (j = 0; j < n; j++) {
        // if (v[j] == max_val) {
            max_ind = j;

            dq1.clear();
            dq2.clear();

            for (i = 0; i < max_ind; i++) {
                dq1.push_back(v[i]);
            }

            for (i = max_ind + 1; i < n; i++) {
                dq2.push_back(v[i]);
            }

            int b = v[max_ind];

            memo.clear();

            int a = recurse(dq1);

            memo.clear();

            int c = recurse(dq2);

            max_power = max({max_power, b - a - c, a, c});
        // }
    }

    cout << max_power << "\n";
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