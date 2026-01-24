#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, h, l, i, j, count = 0;

    cin >> n >> h >> l;

    if (h > l) {
        swap(h, l);
    }

    deque <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    while (!v.empty() && v.back() > l) {
        v.pop_back();
    }

    while (v.size() > 1) {
        if (v.front() <= h && v.back() <= l) {
            count++;

            v.pop_front();
            v.pop_back();
        }
        else {
            break;
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