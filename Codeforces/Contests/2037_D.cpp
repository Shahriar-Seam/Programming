#include <bits/stdc++.h>

using namespace std;

#define int long long

bool compare(pair <int, int> p, pair <int, int> q)
{
    if (p.first > q.first) {
        return false;
    }
    else if (p.first < q.first) {
        return true;
    }
    else {
        if (p.second > q.second) {
            return true;
        }
        else {
            return false;
        }
    }
}

void solve()
{
    int n, m, l, i, j = 0, count = 0, sum = 0;
    priority_queue <int> pq;

    cin >> n >> m >> l;

    vector <pair <int, int> > h(n), p(m);

    for (i = 0; i < n; i++) {
        cin >> h[i].first >> h[i].second;
    }

    for (i = 0; i < m; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (i = 0; i < n; i++) {
        for (j; j < m; j++) {
            if (p[j].first < h[i].first) {
                pq.push(p[j].second);
            }
            else {
                break;
            }
        }

        int temp = h[i].second - h[i].first + 1;

        while (!pq.empty() && sum < temp) {
            sum += pq.top();

            pq.pop();

            count++;
        }

        if (sum < temp) {
            cout << -1 << "\n";

            return;
        }
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}