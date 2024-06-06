#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;

    cin >> n;

    deque <int> dq(n);

    for (auto &it : dq) {
        cin >> it;
    }

    sort(dq.begin(), dq.end());

    m = dq.back();
    dq.pop_back();

    if (n <= 2) {
        cout << 0 << "\n";
        for (auto it : dq) {
            cout << it << " ";
        }

        cout << m;

        return 0;
    }

    cout << n / 2 << "\n";

    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            cout << dq.front() << " ";

            dq.pop_front();
        }
        else {
            cout << dq.back() << " ";

            dq.pop_back();
        }
    }

    cout << m;

    return 0;
}