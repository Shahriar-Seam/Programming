#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, i, odd = 0, even = 0;
    map <int, int> mp;
    vector <pair <int, int> > counter;
    set <int> s;

    cin >> n >> d;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        if (mp[it.first - d] > 0) {
            s.insert(it.first);
            s.insert(it.first - d);
        }
    }

    v.assign(s.begin(), s.end());

    for (i = 0; i < v.size(); i++) {
        if (i % 2 == 0) {
            even += mp[v[i]];
        }
        else {
            odd += mp[v[i]];
        }
    }

    for (auto &it : v) {
        counter.push_back({mp[it], it});
    }

    sort(counter.begin(), counter.end());

    

    cout << min(even, odd) << "\n";

    return 0;
}