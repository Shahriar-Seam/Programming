#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, count = 0;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <> > pq;

    cin >> n >> k;

    vector <pair <int, int> > v(n);

    for (i = 1; i <= k; i++) {
        pq.push({0, i});
    }

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end());

    for (auto &it : v) {
        cout << it.first << " " << it.second << "\n";
    }

    for (auto &it : v) {
        auto top = pq.top();

        if (top.first < it.first) {
            cout << it.first << " " << it.second << "\n";

            top.first = it.second;

            pq.pop();

            pq.push(top);

            count++;
        }
    }

    cout << count << "\n";

    return 0;
}