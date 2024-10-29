#include <bits/stdc++.h>

using namespace std;

int possible(vector <long long> &v, long long k)
{
    long long n = v.size(), i = -1, f = 0;
    set <long long> s;
    deque <long long> dq(v.begin(), v.end());

    while (!dq.empty()) {
        long long a = dq.front();
        s.insert(a);
        dq.pop_front();

        if (dq.empty()) {
            s.insert(i--);
            f++;
        }
        else if (!dq.empty() && (a + k >= dq.front())) {
            s.insert(dq.front());
            dq.pop_front();
        }
        else {
            s.insert(i--);
        }
    }

    return s.size() <= n + 1;
}

void solve()
{
    long long n, i, k = 1;
    set <long long> s;

    cin >> n;

    vector <long long> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        s.insert(v[i] - v[i - 1]);
    }

    for (auto it : s) {
        if (possible(v, it)) {
            k = it;

            break;
        }
    }

    cout << k << "\n";
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