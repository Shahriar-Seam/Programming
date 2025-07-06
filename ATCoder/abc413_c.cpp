#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, q, x, c, k, sum;

    deque <pair <int, int> > a;

    cin >> Q;

    while (Q--) {
        cin >> q;

        if (q == 1) {
            cin >> c >> x;

            a.push_back({c, x});
        }
        else {
            cin >> k;

            sum = 0;

            while (k > 0) {
                auto t = a.front();
                a.pop_front();

                if (t.first <= k) {
                    k -= t.first;

                    sum += t.first * t.second;
                }
                else {
                    sum += k * t.second;

                    a.push_front({t.first - k, t.second});

                    k = 0;
                }
            }

            cout << sum << "\n";
        }
    }

    return 0;
}