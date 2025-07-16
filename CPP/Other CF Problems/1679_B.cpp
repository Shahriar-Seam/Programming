#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, Q, q, t, i, x, sum = 0;
    pair <int, int> s_query = {-1, 0};

    cin >> n >> Q;

    vector <int> v(n);
    vector <pair <int, int> > f_query;

    for (auto &it : v) {
        cin >> it;

        sum += it;

        f_query.push_back({0, it});
    }

    for (q = 1; q <= Q; q++) {
        cin >> t;

        if (t == 1) {
            cin >> i >> x;

            if (s_query.first > f_query[i - 1].first) {
                sum -= s_query.second;
            }
            else {
                sum -= f_query[i - 1].second;
            }

            f_query[i - 1] = {q, x};
            sum += x;
        }
        else {
            cin >> x;

            sum = x * n;

            s_query = {q, x};
        }

        cout << sum << "\n";
    }

    return 0;
}