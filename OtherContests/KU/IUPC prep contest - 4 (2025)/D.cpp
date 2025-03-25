#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, sum = 0, r_sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <int> ());

    r_sum = accumulate(v.begin(), v.end(), 0LL);

    for (i = 0; i < n; i++) {
        r_sum -= v[i];

        sum += v[i] * (n - i - 1) - r_sum;
    }

    cout << sum << "\n";

    return 0;
}