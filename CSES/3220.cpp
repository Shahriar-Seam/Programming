#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x, a, b, c, i, sum, x_sum;

    cin >> n >> k >> x >> a >> b >> c;

    vector <int> v(n);

    v[0] = sum = x;

    for (i = 1; i < k; i++) {
        v[i] = (a * v[i - 1] + b) % c;

        sum += v[i];
    }

    x_sum = sum;

    for (i = k; i < n; i++) {
        v[i] = (a * v[i - 1] + b) % c;

        sum += v[i];
        sum -= v[i - k];

        x_sum ^= sum;
    }

    cout << x_sum << "\n";

    return 0;
}