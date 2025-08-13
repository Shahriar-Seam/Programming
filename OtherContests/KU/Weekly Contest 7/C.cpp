#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i;

    cin >> n >> x;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        int s = v[i].first;

        int l = 0, r = n - 1;

        while (l < r) {
            if (l == i) {
                l++;
            }
            else if (r == i) {
                r--;
            }
            else {
                if (v[i].first + v[l].first + v[r].first > x) {
                    r--;
                }
                else if (v[i].first + v[l].first + v[r].first < x) {
                    l++;
                }
                else {
                    cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n";

                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}