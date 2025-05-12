#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, XOR = 0, t_xor = 0, i;
    int x, a, b, c;

    cin >> n >> k;
    cin >> x >> a >> b >> c;

    vector <int> v(n);

    v[0] = x;

    for (i = 1; i < n; i++) {
        v[i] = (a * v[i - 1] + b) % c;
    }

    for (i = 0; i < k; i++) {
        t_xor ^= v[i];
    }

    XOR ^= t_xor;

    for (i = k; i < n; i++) {
        t_xor ^= v[i];
        t_xor ^= v[i - k];

        XOR ^= t_xor;
    }

    cout << XOR << "\n";

    return 0;
}