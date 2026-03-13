#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, sum = 0, k = 1;
    string s;
    stack <int> st, rst;

    cin >> n >> s;

    vector <int> color(n, 0);

    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            sum++;
        }
        else {
            sum--;
        }
    }

    if (sum != 0) {
        cout << -1 << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (!rst.empty()) {
                color[i] = 2;
                color[rst.top()] = 2;

                rst.pop();
            }
            else {
                st.push(i);
            }
        }
        else {
            if (!st.empty()) {
                color[i] = 1;
                color[st.top()] = 1;

                st.pop();
            }
            else {
                rst.push(i);
            }
        }
    }

    for (i = 1; i < n; i++) {
        if (color[i] != color[i - 1]) {
            k = 2;
        }
    }

    if (k == 1) {
        for (i = 0; i < n; i++) {
            color[i] = 1;
        }
    }

    cout << k << "\n";

    for (i = 0; i < n; i++) {
        cout << color[i] << " ";
    }

    cout << "\n";
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