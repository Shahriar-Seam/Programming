#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e12;

void solve()
{
    int n, q, i, zero;
    int s_one, t_one, min_swaps = inf;
    string s, t;

    cin >> n >> q;

    cin >> s >> t;

    vector <int> s_s(n, inf), s_t(n, inf);
    queue <int> pos;

    s_one = count(s.begin(), s.end(), '1');
    t_one = count(t.begin(), t.end(), '1');

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos.push(i);
        }
    }

    for (i = 0; i < s_one; i++) {
        if (s[i] == '0') {
            s_s[i] = pos.front() - i;

            swap(s[i], s[pos.front()]);

            pos.pop();
        }
        else {
            s_s[i] = i > 0 ? s_s[i - 1] : 0;

            pos.pop();
        }
    }

    while (!pos.empty()) {
        pos.pop();
    }

    for (i = n - 1; i >= 0; i--) {
        if (t[i] == '1') {
            pos.push(i);
        }
    }

    for (i = 0; i < t_one; i++) {
        if (t[n - i - 1] == '0') {
            s_t[n - i - 1] = n - i - 1 - pos.front();

            swap(t[n - i - 1], t[pos.front()]);

            pos.pop();
        }
        else {
            s_t[n - i - 1] = i > 0 ? s_t[n - i] : 0;

            pos.pop();
        }
    }

    for (i = 1; i < n; i++) {
        s_s[i] += s_s[i - 1];
    }

    for (i = n - 2; i >= 0; i--) {
        s_t[i] += s_t[i + 1];
    }

    for (i = 0; i < n; i++) {
        min_swaps = min(min_swaps, s_s[i] + s_t[i]);
    }

    cout << (min_swaps >= inf ? -1 : min_swaps) << "\n";
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