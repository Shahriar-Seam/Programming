#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i;
    long long sum = 0, temp;
    deque <long long> dq1, dq2;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> temp;

        dq1.push_back(temp);
    }
    for (i = 0; i < m; i++) {
        cin >> temp;

        dq2.push_back(temp);
    }

    sort(dq1.begin(), dq1.end());
    sort(dq2.begin(), dq2.end());

    while (!dq1.empty()) {
        if (abs(dq2.back() - dq1.front()) > abs(dq1.back() - dq2.front())) {
            sum += abs(dq2.back() - dq1.front());

            dq2.pop_back();

            dq1.pop_front();
        }
        else {
            sum += abs(dq1.back() - dq2.front());

            dq1.pop_back();

            dq2.pop_front();
        }
    }

    cout << sum << "\n";
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