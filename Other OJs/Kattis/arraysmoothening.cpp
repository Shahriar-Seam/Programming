#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector <int> v(n);
    map <int, int> mp;
    priority_queue <pair <int, int> > pq;

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        pq.push({it.second, it.first});
    }

    while (k--) {
        auto t = pq.top();
        pq.pop();

        t.first--;

        pq.push(t);
    }

    cout << pq.top().first << "\n";

    return 0;
}