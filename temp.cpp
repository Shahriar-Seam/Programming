#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int m = 0; m < 1000; m++) {
        int f = 0;

        for (int x = 0; x < 1000; x++) {
            for (int y = 0; y < 1000; y++) {
                if (100 * x + 3 * y == m) {
                    f = 1;
                }
            }
        }

        if (!f) {
            cout << m << "\n";
        }
    }

    return 0;
}