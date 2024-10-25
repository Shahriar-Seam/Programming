#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, max_area = 0;
    stack <pair <int, int> > st;
    pair <int, int> p;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    v.push_back(0);

    for (i = 0; i <= n; i++) {
        p = {v[i], i};

        if (!st.empty() && st.top().first >= v[i]) {
            while (!st.empty() && st.top().first >= v[i]) {
                p = st.top();

                max_area = max(max_area, p.first * (i - p.second));

                st.pop();
            }
        }

        st.push({v[i], p.second});
    }

    max_area = max(max_area, st.top().first * (i - st.top().second));

    cout << max_area << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}