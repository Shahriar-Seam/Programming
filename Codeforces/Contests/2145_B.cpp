#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;
    string s;

    cin >> n >> k >> s;

    deque <int> dq(n);
    string v(n, '+');

    sort(s.begin(), s.end());

    iota(dq.begin(), dq.end(), 1);

    for (i = 0; i < k && !dq.empty(); i++) {
        if (s[i] == '0') {
            v[dq.front() - 1] = '-';

            dq.pop_front();
        }
        else if (s[i] == '1') {
            v[dq.back() - 1] = '-';

            dq.pop_back();
        }
        else {
            v[dq.front() - 1] = '?';
            v[dq.back() - 1] = '?';

            dq.pop_front();

            if (!dq.empty()) {
                dq.pop_back();
            }
        }
    }

    if (k == n) {
        v = string(n, '-');
    }

    cout << v << "\n";
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