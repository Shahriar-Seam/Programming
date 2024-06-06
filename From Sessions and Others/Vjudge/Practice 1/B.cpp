#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a, b, c, d;

    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> d;

        if ((d < b) || (c - a > d - b)) {
            cout << -1 << "\n";
        }
        else {
            cout << abs(b - d) + a + abs(b - d) - c << "\n";
        }
    }

    return 0;
}