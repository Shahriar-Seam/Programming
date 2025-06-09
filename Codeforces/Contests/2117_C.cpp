#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0;
    map <int, int> mp;
    set <int> s;

    cin >> n;

    deque <int> dq(n);

    for (auto &it : dq) {
        cin >> it;

        mp[it]++;
    }

    while (!dq.empty()) {
        auto temp = dq.back();
        dq.pop_back();

        s.insert(temp);
        mp[temp]--;

        if (s.size() == mp.size()) {
            count++;

            for (auto &it : s) {
                if (mp[it] == 0) {
                    mp.erase(it);
                }
            }

            s.clear();
        }
    }

    cout << count << "\n";
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