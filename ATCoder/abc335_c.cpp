#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, t, p;
    char c;
    deque <pair <int, int> > dq;

    cin >> n >> q;

    for (i = 0; i < n; i++) {
        dq.push_back({i + 1, 0});
    }

    while (q--) {
        cin >> t;

        if (t == 1) {
            cin >> c;

            auto f = dq.front();
            
            if (c == 'U') {
                f.second++;
            }
            else if (c == 'D') {
                f.second--;
            }
            else if (c == 'L') {
                f.first--;
            }
            else {
                f.first++;
            }

            dq.push_front(f);
        }
        else {
            cin >> p;

            cout << dq[--p].first << " " << dq[p].second << "\n";
        }
    }

    return 0;
}