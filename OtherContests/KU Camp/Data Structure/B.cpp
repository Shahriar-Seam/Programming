#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q, i, temp;
    char op;
    deque <int> dq;

    cin >> n >> q;

    for (i = 0; i < n; i++) {
        cin >> temp;

        dq.push_back(temp);
    }

    while (q--) {
        cin >> op >> temp;

        if (op == 'c') {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}