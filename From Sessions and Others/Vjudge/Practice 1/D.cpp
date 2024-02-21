#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp;
    long long sum;

    cin >> t;

    while (t--) {
        cin >> n;

        sum = 0;
        priority_queue <int> pq;

        for (i = 0; i < n; i++) {
            cin >> temp;

            if (temp == 0) {
                if (pq.empty() == false) {
                    sum += 1LL * pq.top();

                    pq.pop();
                }
            }
            else {
                pq.push(temp);
            }
        }

        cout << sum << "\n";
    }

    return 0;
}