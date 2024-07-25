#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    int op, t, x;

    cin >> n >> q;

    vector <priority_queue <int> > vpq(n, priority_queue <int> ());

    while (q--) {
        cin >> op >> t;

        if (op == 0) {
            cin >> x;

            vpq[t].push(x);
        }
        else if (op == 1) {
            if (!vpq[t].empty()) {
                cout << vpq[t].top() << "\n";
            }
        }
        else {
            if (!vpq[t].empty()) {
                vpq[t].pop();
            }
        }
    }

    return 0;
}