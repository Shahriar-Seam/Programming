#include <bits/stdc++.h>

using namespace std;

#define int long long

bool _swap(multiset <int> &ms_l, multiset <int> &ms_r, int &sum_l, int &sum_r)
{
    if (*ms_l.rbegin() > *ms_r.begin()) {
        int temp = *ms_l.rbegin();
        sum_l -= temp;
        sum_r += temp;

        ms_l.erase(ms_l.find(temp));
        ms_r.insert(temp);

        ms_l.insert(*ms_r.begin());
        
        sum_l += *ms_r.begin();
        sum_r -= *ms_r.begin();

        ms_r.erase(ms_r.begin());

        return true;
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;
    multiset <int> ms_l, ms_r;
    int sum_l = 0, sum_r = 0;

    cin >> n >> k;

    vector <int> v(n), cost;

    for (auto &it : v) {
        cin >> it;
    }

    if (k == 1) {
        for (i = 0; i < n; i++) {
            cout << 0 << " ";
        }

        return 0;
    }

    for (i = 0; i < (k + 1) / 2; i++) {
        ms_l.insert(v[i]);
    }

    for (i; i < k; i++) {
        ms_r.insert(v[i]);
    }

    while (_swap(ms_l, ms_r, sum_l, sum_r));

    sum_l = sum_r = 0;

    for (auto it : ms_l) {
        sum_l += it;
    }

    for (auto it : ms_r) {
        sum_r += it;
    }

    cost.push_back(ms_l.size() * (*ms_l.rbegin()) - sum_l + sum_r - ms_r.size() * (*ms_l.rbegin()));

    for (i; i < n; i++) {
        if (v[i - k] <= *ms_l.rbegin()) {
            ms_l.erase(ms_l.find(v[i - k]));
            ms_l.insert(v[i]);

            sum_l -= v[i - k];
            sum_l += v[i];
        }
        else {
            ms_r.erase(ms_r.find(v[i - k]));
            ms_r.insert(v[i]);

            sum_r -= v[i - k];
            sum_r += v[i];
        }

        _swap(ms_l, ms_r, sum_l, sum_r);

        cost.push_back(ms_l.size() * (*ms_l.rbegin()) - sum_l + sum_r - ms_r.size() * (*ms_l.rbegin()));
    }

    for (auto it : cost) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}