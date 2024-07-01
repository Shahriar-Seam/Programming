#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, temp;

    priority_queue <int> pq;

    cin >> n;

    while (n--) {
        cin >> temp;

        pq.push(temp);
    }

    while (!pq.empty()) {
        temp = pq.top();

        pq.pop();

        if (temp > 1) {
            pq.push(temp / 2);
        }

        cout << temp << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}