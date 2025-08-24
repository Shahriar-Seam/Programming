#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, x;

    cin >> n;

    fflush(stdout);

    vector <pair <int, int> > counter(n + 1);
    vector <int> path;
    deque <int> dq;

    counter[0] = make_pair(-1, -1);

    for (i = 1; i <= n; i++) {
        counter[i].second = i;
    }

    for (i = 1; i <= n; i++) {
        cout << "? " << i << " " << n << " ";

        for (j = 1; j <= n; j++) {
            cout << j << " ";
        }

        cout << endl;

        fflush(stdout);

        cin >> x;

        fflush(stdout);

        counter[i].first = x;
    }

    sort(counter.begin(), counter.end(), greater <> ());

    path.push_back(counter[0].second);

    for (i = 1; i < n; i++) {
        if (counter[i].first < counter[0].first) {
            break;
        }
    }

    while (i < n) {
        if (counter[i].first != counter[i + 1].first) {
            path.push_back(counter[i].second);

            i++;

            continue;
        }

        for (j = i; j < n; j++) {
            if (counter[j].first == counter[i].first) {
                vector <int> temp;
                for (auto &it : path) {
                    temp.push_back(it);
                }

                temp.push_back(counter[j].second);

                for (k = j + 1; k < n; k++) {
                    if (counter[j].first > counter[k].first) {
                        temp.push_back(counter[k].second);
                    }
                }

                cout << "? " << path[0] << " " << temp.size() << " ";

                for (auto &it : temp) {
                    cout << it << " ";
                }

                cout << endl;

                fflush(stdout);

                cin >> x;

                fflush(stdout);

                if (x == counter[0].first) {
                    path.push_back(counter[j].second);

                    for (j; j < n; j++) {
                        if (counter[j].first != counter[i].first) {
                            break;
                        }
                    }

                    break;
                }
            }
        }

        i = j;
    }

    cout << "! " << path.size() << " ";

    for (auto &it : path) {
        cout << it << " ";
    }

    cout << endl;

    fflush(stdout);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    fflush(stdout);

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}