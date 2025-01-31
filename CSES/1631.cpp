#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int total = 0, without_last = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    total = accumulate(v.begin(), v.end(), 0LL);

    without_last = total - v[n - 1];

    if (without_last <= v[n - 1]) {
        cout << v[n - 1] * 2 << "\n";
    }
    else {
        cout << v[n - 1] + without_last << "\n";
    }

    return 0;
}