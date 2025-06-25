#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int n, r, i, j;

    cin >> n >> r;

    vector <int> x(n);
    vector <double> y(n, r);

    for (auto &it : x) {
        cin >> it;
    }

    for (j = 1; j < n; j++) {
        for (i = j - 1; i >= 0; i--) {
            if (abs(x[i] - x[j]) <= 2 * r) {
                y[j] = max(y[j], sqrt(1.0 * (4 * r * r - (x[j] - x[i]) * (x[j] - x[i]))) + y[i]);
            }
        }
    }

    for (auto it : y) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}