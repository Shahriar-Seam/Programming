#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(vector <int> &fib)
{
    int n, m, i;
    string s = "";

    cin >> n >> m;

    int v[m][3];

    for (i = 0; i < m; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    for (i = 0; i < m; i++) {
        sort(v[i], v[i] + 3);

        if ((fib[n] + fib[n - 1] <= v[i][2]) && (fib[n] <= v[i][0])) {
            s += '1';
        }
        else {
            s += '0';
        }
    }

    cout << s << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;
    vector <int> fib(12, 0);

    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;

    for (i = 3; i <= 11; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve(fib);
    }

    return 0;
}