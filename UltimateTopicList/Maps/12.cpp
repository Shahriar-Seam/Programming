#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i, temp, l, r;
    map <int, int> mp;

    cin >> n >> x;

    vector <pair <int, int> > v;

    for (i = 1; i <= n; i++) {
        cin >> temp;

        v.push_back({temp, i});
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        l = i + 1;
        r = n - 1;
        temp = x - v[i].first;

        while (l < r) {
            if (v[l].first + v[r].first == temp) {
                cout << v[i].second << " " << v[l].second << " " << v[r].second << "\n";

                return 0;
            }
            else if (v[l].first + v[r].first < temp) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}