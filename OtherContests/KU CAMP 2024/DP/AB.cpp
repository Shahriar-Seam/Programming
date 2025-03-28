#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <int> v(n);
    vector <int> lis;
    // lis[i] = minimum element of v where lis of length i + 1 ends

    for (auto &it : v) {
        cin >> it;
    }

    lis.push_back(v[0]);

    for (i = 1; i < n; i++) {
        if (v[i] > lis.back()) {
            lis.push_back(v[i]);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin()] = v[i];
        }
    }

    cout << lis.size() << "\n";

    return 0;
}