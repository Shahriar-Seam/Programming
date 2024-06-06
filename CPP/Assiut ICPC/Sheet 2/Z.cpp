#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, s, m, x, y, z, c = 0;

    cin >> k >> s;

    m = min(k, s);

    for (x = 0; x <= m; x++) {
        for (y = 0; y <= m; y++) {
            if (s - x - y <= k && s - x - y >= 0) {
                c++;
            }
        }
    }

    cout << c;

    return 0;
}