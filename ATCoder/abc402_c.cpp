#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, i, j, temp, count = 0;
    map <int, set <int> > mp;
    vector <int> counter(int(3e5 + 10), 0);

    cin >> n >> m;

    for (i = 0; i < m; i++) {
        cin >> k;
        counter[i] = k;

        for (j = 0; j < k; j++) {
            cin >> temp;

            mp[temp].insert(i);
        }
    }

    for (i = 0; i < n; i++) {
        cin >> temp;

        for (auto it : mp[temp]) {
            counter[it]--;

            count += (counter[it] == 0);
        }

        cout << count << "\n";
    }

    return 0;
}