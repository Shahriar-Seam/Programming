#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, x, y, i, sum;

    cin >> t;

    while (t--) {
        cin >> x >> y;

        for (i = min(x, y) + 1, sum = 0; i < max(x, y); i++) {
            if (i % 2 == 1) {
                sum += i;
            }
        }

        cout << sum << "\n";
    }

    return 0;
}