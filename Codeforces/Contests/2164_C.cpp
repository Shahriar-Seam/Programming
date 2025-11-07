#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, count = 0;

    cin >> n >> m;

    vector <int> a(n);
    vector <pair <int, int> > v(m);
    list <pair <int, int> > bc;
    priority_queue <int> pq;
    list <pair <int, int> > :: iterator l_it, temp;

    for (auto &it : a) {
        cin >> it;

        pq.push(it);
    }

    for (auto &it : v) {
        cin >> it.first;
    }

    for (auto &it : v) {
        cin >> it.second;
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    });

    i = 0;

    for (auto &it : v) {
        if (it.second > 0) {
            break;
        }
        else {
            i++;
        }
    }

    sort(v.begin() + i, v.end());

    for (auto &it : v) {
        bc.push_back(it);
    }

    bc.push_front({0, 0});

    temp = bc.begin();

    while (i--) {
        temp++;
    }

    while (!pq.empty()) {
        bool dead = false;

        for (l_it = temp, l_it++; l_it != bc.end(); ) {
            if (l_it->first <= pq.top()) {
                if (l_it->second > pq.top()) {
                    pq.pop();

                    pq.push(l_it->second);
                }

                l_it++;

                bc.erase(prev(l_it));

                dead = true;

                count++;
            }
            else {
                l_it++;
            }
        }

        if (!dead) {
            break;
        }
    }

    bc.pop_front();

    while (!pq.empty() && !bc.empty()) {
        if (bc.front().first <= pq.top()) {
            pq.pop();
            bc.pop_front();

            count++;
        }
        else {
            bc.pop_front();
        }
    }

    cout << count << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}