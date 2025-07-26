#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, sum = 0;
    map <int, int> mp_a, mp_b;
    map <int, vector <int> > mp_aa, mp_bb;

    cin >> n >> m;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;

        mp_a[it]++;
    }

    for (auto &it : b) {
        cin >> it;

        mp_b[it]++;
    }

    for (auto &it : mp_a) {
        auto temp = min(it.second, mp_b[m - it.first]);

        it.second -= temp;
        mp_b[m - it.first] -= temp;
    }

    a.clear();
    b.clear();

    for (auto &it : mp_a) {
        while (it.second--) {
            a.push_back(it.first);
        }
    }

    for (auto &it : mp_b) {
        while (it.second--) {
            b.push_back(it.first);
        }
    }

    for (i = 0; i < a.size(); i++) {
        mp_aa[a[i]].push_back(i);
        mp_bb[b[i]].push_back(i);
    }

    vector <bool> visited_a(a.size(), false), visited_b(b.size(), false);

    for (i = 0; i < a.size(); i++) {
        if (visited_a[i]) {
            continue;
        }

        auto temp = mp_bb.lower_bound(m - a[i]);

        if (temp == mp_bb.end()) {
            continue;
        }
        else {
            int idx = temp->second.back();
            temp->second.pop_back();

            if (temp->second.size() == 0) {
                mp_bb.erase(temp);
            }

            visited_a[i] = true;
            visited_b[idx] = true;

            sum += (a[i] + b[idx]) % m;
        }
    }

    vector <int> bb;

    for (i = 0; i < b.size(); i++) {
        if (!visited_b[i]) {
            bb.push_back(b[i]);
        }
    }

    for (i = 0; i < a.size(); i++) {
        if (!visited_a[i]) {
            sum += (a[i] + bb.back()) % m;
            bb.pop_back();
        }
    }

    cout << sum << "\n";
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