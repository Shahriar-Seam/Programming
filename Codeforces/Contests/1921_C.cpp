#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, f, a, b, temp, i, re, mn;
    vector <int> v;
    
    cin >> t;

    while (t--) {
        cin >> n >> f >> a >> b;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        re = 0;

        for (i = 0; i < n; i++) {
            mn = min(b, abs(v[i] - re) * a);
            f -= mn;
            re = v[i];
        }

        if (f > 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

        v.clear();
    }

    return 0;
}