#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque <int> dq;
    int q, op, d, x, p;

    cin >> q;

    while (q--) {
        cin >> op;

        if (op == 0) {
            cin >> d >> x;

            if (d == 0) {
                dq.push_front(x);
            }
            else {
                dq.push_back(x);
            }
        }
        else if (op == 1) {
            cin >> p;

            cout << dq.at(p) << "\n";
        }
        else {
            cin >> d;

            if (d == 0) {
                dq.pop_front();
            }
            else {
                dq.pop_back();
            }
        }
    }

    return 0;
}