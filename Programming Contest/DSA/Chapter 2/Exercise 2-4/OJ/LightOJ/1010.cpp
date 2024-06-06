#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, m, n;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> m >> n;

        if (m == 1 || n == 1) {
            cout << "Case " << i << ": " << max(m, n) << "\n";
        }
        else if (m == 2 or n == 2) {
            cout << "Case " << i << ": " << ((m * n) / 8) * 4 + (((m * n) % 8 >= 4) ? 4 : ((m * n) % 8)) << endl;
        }
        else {
            cout << "Case " << i << ": " << ceil(m * n / 2.0) << "\n";
        }
    }

    return 0;
}