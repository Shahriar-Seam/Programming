#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, count = 0;

    cin >> n;

    vector <int> a(n), b(n), v(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i] = a[i] - b[i];
    }

    sort(v.begin(), v.end());

    deque <int> dq(v.begin(), v.end());

    while (!dq.empty()) {
        if (dq.back() > -dq.front()) {
            dq.pop_back();
        }
        else {
            if (dq.size() >= 2) {
                dq.pop_front();
                dq.pop_back();

                count++;
            }
            else {
                dq.pop_back();
            }
        }
    }

    cout << count << "\n";
}

int main()
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