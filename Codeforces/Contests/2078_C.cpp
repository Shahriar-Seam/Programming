#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, a1, a_2n, a_2n1, sum = 0;

    cin >> n;

    deque <int> v(2 * n);
    vector <int> a;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    a1 = v.back();

    a.push_back(a1);

    v.pop_back();

    while (v.size() > 1) {
        int l, r;

        l = v.front();
        v.pop_front();

        sum += l;

        r = v.back();
        v.pop_back();

        sum -= r;

        a.push_back(l);
        a.push_back(r);
    }

    a_2n1 = v.front();

    a_2n = a1 + a_2n1 - sum;

    a.push_back(a_2n);
    a.push_back(a_2n1);

    for (auto it : a) {
        cout << it << " ";
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