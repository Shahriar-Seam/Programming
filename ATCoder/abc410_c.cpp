#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, type, rot = 0, i;

    cin >> n >> q;

    vector <int> v(n);

    for (i = 1; i <= n; i++) {
        v[i - 1] = i;
    }

    while (q--) {
        cin >> type;

        if (type == 1) {
            int p, x;

            cin >> p >> x;

            v[((((p - 1) - rot) % n) + n) % n] = x;
        }
        else if (type == 2) {
            int p;

            cin >> p;

            cout << v[((((p - 1) - rot) % n) + n) % n] << "\n";
        }
        else {
            int k;

            cin >> k;

            k %= n;
            rot -= k;
            rot %= n;
        }
    }

    return 0;
}