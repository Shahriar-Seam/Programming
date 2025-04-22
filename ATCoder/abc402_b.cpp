#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q, op, x;
    queue <int> q;

    cin >> Q;

    while (Q--) {
        cin >> op;

        if (op == 1) {
            cin >> x;

            q.push(x);
        }
        else {
            cout << q.front() << "\n";

            q.pop();
        }
    }

    return 0;
}