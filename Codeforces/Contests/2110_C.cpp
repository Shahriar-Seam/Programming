#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, h = 0, f = 1;
    stack <int> st;

    cin >> n;

    vector <int> v(n), l(n), r(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    for (i = 0; i < n; i++) {
        if (v[i] == -1) {
            st.push(i);
        }

        if (v[i] == 1) {
            h++;
        }

        if (l[i] <= h) {
            // do nothing
        }
        else {
            while (!st.empty() && l[i] > h) {
                auto index = st.top();
                st.pop();

                v[index] = 1;

                h++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (v[i] == -1) {
            v[i] = 0;
        }
    }

    h = 0;

    for (i = 0; i < n; i++) {
        if (v[i] == 1) {
            h++;
        }

        if (l[i] <= h && h <= r[i]) {

        }
        else {
            f = 0;

            break;
        }
    }

    if (f) {
        for (i = 0; i < n; i++) {
            cout << v[i] << " ";
        }

        cout << "\n";
    }
    else {
        cout << -1 << "\n";
    }
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