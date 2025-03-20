#include <bits/stdc++.h>

using namespace std;

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, l = 1;

    cin >> n;

    l = n;

    if (n <= 2) {
        l = n;
    }
    else if (n == 3) {
        l = 6;
    }
    else {
        for (i = n; i >= max(0, n - 100); i--) {
            for (j = i - 1; j >= max(0, n - 100); j--) {
                for (k = j - 1; k >= max(0, n - 100); k--) {
                    l = max(l, lcm(lcm(i, j), k));
                }
            }
        }
    }

    cout << l << "\n";

    return 0;
}