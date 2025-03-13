#include <bits/stdc++.h>

using namespace std;

#define int long long

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int calc(vector <int> &v, int l)
{
    int i, temp = 1, count = 0;

    if (binary_search(v.begin(), v.end(), l)) {
        return 0;
    }

    for (i = 0; i < v.size(); i++) {
        if (v[i] < l && (l % v[i] == 0)) {
            count++;
            temp = LCM(temp, v[i]);
        }
    }

    return temp == l ? count : 0;
}

void solve()
{
    int n, l = 1, i;
    int max_count = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        l = LCM(l, v[i]);

        if (l > v.back()) {
            break;
        }
    }

    if (l > v.back()) {
        cout << n << "\n";

        return;
    }

    for (i = 1; i * i <= v.back(); i++) {
        if (v.back() % i == 0) {
            max_count = max(max_count, calc(v, i));
            max_count = max(max_count, calc(v, v.back() / i));
        }
    }

    cout << max_count << "\n";
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