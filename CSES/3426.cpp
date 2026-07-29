#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    long long x, a, b, c;
    int w = 0, X = 0, i;

    cin >> n >> k;
    cin >> x >> a >> b >> c;

    vector <int> v(k);

    for (i = 0; i < k; i++) {
        x = v[i] = ((i == 0) ? x : (((a * x + b) % c + c) % c));

        w ^= v[i];
    }

    X = w;

    for (i = k; i < n; i++) {
        w ^= v[i % k];

        x = v[i % k] = ((a * x + b) % c + c) % c;

        w ^= v[i % k];

        X ^= w;
    }

    cout << X << "\n";

    return 0;
}