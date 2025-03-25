#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, a, t, q, x;
    int sum_a = 0, min_a = -1e15, max_a = 1e15;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a >> t;

        if (t == 1) {
            sum_a += a;
            min_a += a;
            max_a += a;
        }
        else if (t == 2) {
            max_a = max(max_a, a);
            min_a = max(min_a, a);
        }
        else {
            min_a = min(min_a, a);
            max_a = min(max_a, a);
        }
    }

    cin >> q;

    while (q--) {
        cin >> x;

        cout << max(min_a, min(x + sum_a, max_a)) << "\n";
    }

    return 0;
}