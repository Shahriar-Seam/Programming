#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, a = 0;

    cin >> n;

    vector <int> v(n), water;

    for (auto &it : v) {
        cin >> it;
    }
    
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a += v[i];
        }
        else {
            a -= v[i];
        }
    }

    water.push_back(a);

    for (i = 0; i < n - 1; i++) {
        water.push_back(2 * v[i] - water.back());
    }

    for (auto it : water) {
        cout << it << " ";
    }

    return 0;
}