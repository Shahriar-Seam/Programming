#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, o = 0, z = 0;
    int a = 0, b = 0;

    cin >> n;

    vector <int> v(2 * n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < 2 * n; i++) {
        if (v[i]) {
            o++;
        }
        else {
            z++;
        }
    }

    if (o == z) {
        if (o % 2) {
            a = 1;
            b = o;
        }
        else {
            a = 0;
            b = o;
        }
    }
    else {
        if (!o || !z) {
            a = 0;
            b = 0;
        }
        else {
            if (o % 2) {
                a = 1;
                b = min(o, z);
            }
            else {
                a = 0;
                b = min(o, z);
            }
        }
    }

    // cout << o << " " << z << "\n";
    cout << a << " " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}