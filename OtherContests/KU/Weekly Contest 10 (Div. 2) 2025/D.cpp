#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, max_area = 0, i;
    pair <int, int> p;

    cin >> n;

    vector <int> v(n);
    stack <pair <int, int> > st;

    for (auto &it : v) {
        cin >> it;
    }

    v.push_back(0);

    for (i = 0; i <= n; i++) {
        p = {v[i], i};

        while (!st.empty() && st.top().first >= v[i]) {
            p = st.top();

            max_area = max(max_area, p.first * (i - p.second));

            st.pop();
        }

        st.push({v[i], p.second});
    }

    cout << max_area << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}