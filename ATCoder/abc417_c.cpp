#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0;
    map <int, int> mp_p, mp_n;

    cin >> n;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        mp_n[i + 1 - v[i]]++;
        mp_p[i + 1 + v[i]]++;
    }
    
    for (auto &it : mp_n) {
        count += it.second * mp_p[it.first];
    }

    cout << count << "\n";

    return 0;
}