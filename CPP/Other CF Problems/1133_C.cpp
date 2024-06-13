#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, l, r, count = 0;

    cin >> n;

    vector <int> v(n);
    
    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (l = 0, r = 0; l < n; l++) {
        while (r < n && v[r] - v[l] <= 5) {
            r++;
        }

        count = max(count, r - l);
    }

    cout << count;

    return 0;
}