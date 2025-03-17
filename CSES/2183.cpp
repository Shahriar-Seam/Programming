#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        if (it <= sum) {
            sum += it;
        }
        else {
            break;
        }
    }

    cout << sum << "\n";

    return 0;
}