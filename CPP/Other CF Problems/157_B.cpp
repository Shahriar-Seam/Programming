#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int n, i;
    double area = 0, pi = acos(-1);

    cin >> n;

    vector <int> r(n);

    for (auto &it : r) {
        cin >> it;
    }

    sort(r.begin(), r.end(), greater <> ());

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            area += pi * r[i] * r[i];
        }
        else {
            area -= pi * r[i] * r[i];
        }
    }

    cout << area << "\n";

    return 0;
}