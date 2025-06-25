#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed;
    cout << setprecision(2);

    int t, i;
    double pi, r, area;

    pi = 2 * acos(0.0);

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> r;

        area = r * r * (4 - pi);

        cout << "Case " << i << ": " << area << "\n";
    }

    return 0;
}