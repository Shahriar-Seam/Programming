#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, i, j, temp, l, r;
    map <int, int> mp;

    cin >> n >> x;

    vector <pair <int, int> > v;

    for (i = 1; i <= n; i++) {
        cin >> temp;

        v.push_back({temp, i});
    }

    sort(v.begin(), v.end());

    for (j = 0; j < n; j++) {
        for (i = j + 1; i < n; i++) {
            l = i + 1;
            r = n - 1;
            temp = x - v[i].first - v[j].first;

            while (l < r) {
                if (v[l].first + v[r].first == temp) {
                    cout << v[j].second << " " << v[i].second << " " << v[l].second << " " << v[r].second << "\n";

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
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}