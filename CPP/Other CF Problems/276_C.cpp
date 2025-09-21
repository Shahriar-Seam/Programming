#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, l, r, i, sum = 0;
    priority_queue <int> pq;

    cin >> n >> q;

    vector <int> v(n), counter(n + 2, 0);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <> ());

    while (q--) {
        cin >> l >> r;

        counter[l]++;
        counter[r + 1]--;
    }

    for (i = 1; i <= n; i++) {
        counter[i] += counter[i - 1];

        pq.push(counter[i]);
    }

    for (i = 0; i < n; i++) {
        sum += v[i] * pq.top();

        pq.pop();
    }

    cout << sum << "\n";

    return 0;
}