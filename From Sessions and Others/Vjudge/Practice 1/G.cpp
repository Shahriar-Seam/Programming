#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x, y, i;

    cin >> t;

    while (t--) {
        cin >> x >> y;

        cout << 2 * (x - y) << "\n";

        for (i = x; i >= y; i--) {
            cout << i << " ";
        }

        for (i = y + 1; i < x; i++) {
            cout << i << " ";
        }

        cout << "\n";
    }

    return 0;
}