#include <bits/stdc++.h>

using namespace std;

double calc(vector <double> &p, int i, int h, int t, vector <vector <double> > &dp)
{
    if (i == p.size()) {
        return h > t;
    }

    if (dp[h][t] != -1) {
        return dp[h][t];
    }

    return dp[h][t] = p[i] * calc(p, i + 1, h + 1, t, dp) + (1 - p[i]) * calc(p, i + 1, h, t + 1, dp);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    int n;

    cin >> n;

    vector <double> p(n);
    vector <vector <double> > dp(n, vector <double> (n, -1));

    for (auto &it : p) {
        cin >> it;
    }

    cout << calc(p, 0, 0,  0, dp) << "\n";

    return 0;
}