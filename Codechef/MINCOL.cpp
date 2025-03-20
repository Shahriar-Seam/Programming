#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    stack <int> st;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        if (mp[it] > 0) {
            while (!st.empty() && st.top() != it) {
                mp[st.top()]--;
                st.pop();
            }
        }
        else {
            st.push(it);
            mp[it]++;
        }
    }

    cout << st.size() << "\n";
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