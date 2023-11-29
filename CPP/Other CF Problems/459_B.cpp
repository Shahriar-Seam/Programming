#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, t, ma = INT32_MIN, mi = INT32_MAX, diff;
    ll cnt;
    vector <int> arr;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> t;

        if (t > ma) {
            ma = t;
        }
        if (t < mi) {
            mi = t;
        }

        arr.push_back(t);
    }

    diff = ma - mi;

    if (diff != 0) {
        cnt = (ll) count (arr.begin(), arr.end(), ma) * count (arr.begin(), arr.end(), mi);
    }
    else {
        cnt = 1;
        for (i = 1; i <= 2; i++) {
            cnt = (cnt * (n - 2 + i)) / i;
        }
    }

    cout << diff << " " << cnt;

    return 0;
}