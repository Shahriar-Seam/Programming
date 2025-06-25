#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, R, r;
    double pi = acos(-1), theta = 0;

    cin >> n >> R >> r;

    theta = pi / n;

    if (n > 1) {
        cout << ((R * sin(theta) / (1 + sin(theta))) + 1e-7 >= r ? "YES" : "NO") << "\n";
    }
    else {
        cout << (r <= R ? "YES" : "NO") << "\n";
    }

    return 0;
}