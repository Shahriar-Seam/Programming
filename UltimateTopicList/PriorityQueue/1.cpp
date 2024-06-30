#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue <int> pq;
    string op;
    int k;

    while (1) {
        cin >> op;

        if (op == "end") {
            break;
        }
        else if (op == "insert") {
            cin >> k;

            pq.push(k);
        }
        else {
            cout << pq.top() << "\n";

            pq.pop();
        }
    }

    return 0;
}