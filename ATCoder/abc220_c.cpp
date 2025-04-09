#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, sum, rem, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> x;

    sum = accumulate(v.begin(), v.end(), 0LL);

    rem = x % sum;

    for (i = 0; i < n; i++) {
        if (rem >= 0) {
            rem -= v[i];
        }
        else {
            break;
        }
    }

    cout << (x / sum) * n + i << "\n";

    return 0;
}