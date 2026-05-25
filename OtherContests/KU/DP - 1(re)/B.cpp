#include <bits/stdc++.h>

using namespace std;

int n;
const int sz = 305;
double dp[sz][sz][sz] = {};

double E(int c1, int c2, int c3)
{
    if ((c1 == 0 && c2 == 0 && c3 == 0) || (c1 < 0 || c2 < 0 || c3 < 0)) {
        return 0;
    }

    if (!dp[c1][c2][c3]) {
        dp[c1][c2][c3] = (1.0 + 1.0 / n * (c1 * E(c1 - 1, c2, c3) + c2 * E(c1 + 1, c2 - 1, c3) + c3 * E(c1, c2 + 1, c3 - 1))) / (1.0 - 1.0 / n * (n - c1 - c2 - c3));
    }

    return dp[c1][c2][c3];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    int c1 = 0, c2 = 0, c3 = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        c1 += it == 1;
        c2 += it == 2;
        c3 += it == 3;
    }

    cout << E(c1, c2, c3) << "\n";

    return 0;
}