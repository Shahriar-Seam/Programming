#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, temp, a, b;
    priority_queue <int> pq;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        pq.push(temp);

        if (i < 2) {
            cout << -1 << "\n";
        }
        else {
            a = pq.top();
            pq.pop();

            b = pq.top();
            pq.pop();

            cout << 1LL * a * b * pq.top() << "\n";

            pq.push(a);
            pq.push(b);
        }
    }

    return 0;
}