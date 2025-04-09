#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num_pairs = 0;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto it : mp) {
        num_pairs += it.second * (n - it.second);
    }

    cout << num_pairs / 2 << "\n";

    return 0;
}