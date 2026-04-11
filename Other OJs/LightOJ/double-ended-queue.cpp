#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, x;
    deque <int> dq;
    string op;

    cin >> n >> m;

    while (m--) {
        cin >> op;

        if (op == "pushLeft") {
            cin >> x;

            if (dq.size() == n) {
                cout << "The queue is full\n";
            }
            else {
                dq.push_front(x);

                cout << "Pushed in left: " << x << "\n";
            }
        }
        else if (op == "pushRight") {
            cin >> x;

            if (dq.size() == n) {
                cout << "The queue is full\n";
            }
            else {
                dq.push_back(x);

                cout << "Pushed in right: " << x << "\n";
            }
        }
        else if (op == "popLeft") {
            if (dq.empty()) {
                cout << "The queue is empty\n";
            }
            else {
                x = dq.front();
                dq.pop_front();

                cout << "Popped from left: " << x << "\n";
            }
        }
        else if (op == "popRight") {
            if (dq.empty()) {
                cout << "The queue is empty\n";
            }
            else {
                x = dq.back();
                dq.pop_back();

                cout << "Popped from right: " << x << "\n";
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";

        solve();
    }

    return 0;
}