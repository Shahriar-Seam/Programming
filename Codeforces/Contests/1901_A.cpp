#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, x, a_p, a_n, tank, i;

    cin >> t;
    
    while (t--) {
        cin >> n >> x >> a_p;

        tank = a_p;

        for (i = 1; i < n; i++) {
            cin >> a_n;

            tank = max(tank, a_n - a_p);

            a_p = a_n;
        }

        tank = max(tank, 2 * (x - a_p));

        cout << tank << "\n";
    }

    return 0;
}