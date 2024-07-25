#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset <int> s;
    int n, q, S, op, x;

    cin >> n >> q;

    while (n--) {
        cin >> S;

        s.insert(S);
    }

    while (q--) {
        cin >> op;

        if (op == 0) {
            cin >> x;

            s.insert(x);
        }
        else if (op == 1) {
            cout << *begin(s) << "\n";

            s.erase(s.find(*begin(s)));
        }
        else {
            cout << *rbegin(s) << "\n";

            s.erase(s.find(*rbegin(s))); 
        }
    }

    return 0;
}