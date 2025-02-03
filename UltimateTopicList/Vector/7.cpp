#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, j, k, type, x, t, total = 0, unread = 0;

    cin >> n >> q;

    vector <int> v(n + 1, 0);
    list <pair <int, int> > time;
    vector <list <list <pair <int, int> > :: iterator > > nodes(n + 1);
    list <pair <int, int> > :: iterator l_it;

    for (i = 0, k = 0; i < q; i++) {
        cin >> type;

        if (type == 1) {
            cin >> x;

            time.push_back({k++, x});

            l_it = time.end();

            l_it--;

            nodes[x].push_back(l_it);

            v[x]++;

            unread++;
            total++;
        }
        else if (type == 2) {
            cin >> x;

            unread -= v[x];

            v[x] = 0;

            for (auto it : nodes[x]) {
                time.erase(it);
            }

            nodes[x].clear();
        }
        else {
            cin >> t;

            while ((!time.empty()) && ((*time.begin()).first < t)) {
                v[(*time.begin()).second]--;

                nodes[(*time.begin()).second].pop_front();

                time.erase(time.begin());

                unread--;
            }
        }

        cout << unread << "\n";
    }

    return 0;
}