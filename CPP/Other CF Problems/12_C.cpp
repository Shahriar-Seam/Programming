#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, min_sum = 0, max_sum = 0;
    map <string, int> mp;
    vector <int> counter;
    string s;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < m; i++) {
        cin >> s;

        mp[s]++;
    }

    for (auto it : mp) {
        counter.push_back(it.second);
    }

    sort(counter.begin(), counter.end(), greater <int> ());

    for (i = 0, j = v.size() - 1; i < counter.size(); i++, j--) {
        min_sum += counter[i] * v[i];
        max_sum += counter[i] * v[j];
    }

    cout << min_sum << " " << max_sum << "\n";

    return 0;
}