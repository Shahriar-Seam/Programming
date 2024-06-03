#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, f, k, temp, i, fav;
    vector <int> v;

    cin >> n >> f >> k;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    fav = v[f - 1];

    sort(v.begin(), v.end(), greater <int>());

    if (k == n) {
        cout << "YES\n";
    }
    else if (v[k] > fav) {
        cout << "NO\n";
    }
    else if (v[k] == fav) {
        if (k > 0 && v[k - 1] == fav) {
            cout << "MAYBE\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "YES\n";
    }
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