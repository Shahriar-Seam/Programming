#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    string s, ss;
    int i, max_b_point = 0, max_r_penalty = 0, max_penalty = 0;
    int j;
    multiset <pair <int, int>, greater <pair <int, int> > > ms;

    cin >> n >> k >> s;

    vector <int> v(n), visited(n, 0);
    ss = s;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == 'B') {
            visited[i] = 1;

            if (i > 0) {
                visited[i - 1] = 1;
            }

            break;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        if (s[i] == 'B') {
            visited[i] = 1;

            if (i < n - 1) {
                visited[i + 1] = 1;
            }

            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (s[i] == 'B') {
            ms.insert({v[i], i});
        }
    }

    if (k == 0) {
        for (i = 0; i < n; i++) {
            if (s[i] == 'B') {
                max_penalty = max(max_penalty, v[i]);
            }
        }

        cout << max_penalty << "\n";

        return;
    }

    int start = ms.begin()->second;

    for (auto it : ms) {
        if (k == 0) {
            break;
        }

        i = it.second;

        max_b_point = v[i];
        max_r_penalty = 0;

        for (j = i + 1; j < n; j++) {
            if (visited[j]) {
                break;
            }

            if (!visited[j] && s[j] == 'R') {
                max_r_penalty = max(max_r_penalty, v[j]);
            }

            if (max_r_penalty >= max_b_point) {
                break;
            }

            s[j] = 'B';
            visited[j] = 1;
        }

        for (j = i - 1; j >= 0; j--) {
            if (visited[j]) {
                break;
            }

            if (!visited[j] && s[j] == 'R') {
                max_r_penalty = max(max_r_penalty, v[j]);
            }

            if (max_r_penalty >= max_b_point) {
                break;
            }

            s[j] = 'B';
            visited[j] = 1;
        }

        k--;
    }

    for (i = 0; i < n; i++) {
        if (ss[i] != s[i]) {
            max_penalty = max(max_penalty, v[i]);
        }
    }

    cout << max_penalty << "\n";
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