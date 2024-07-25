#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, x;
    string op;
    priority_queue <int, vector <int>, greater <int> > pq;

    cin >> q;

    while (q--) {
        cin >> op;

        if (op == "push") {
            cin >> x;

            pq.push(x);
        }
        else if (op == "top") {
            cout << pq.top() << "\n";
        }
        else {
            pq.pop();
        }
    }

    return 0;
}