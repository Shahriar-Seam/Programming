#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue <int> q1, q2;
    int n, k1, k2, i, temp, fights = 0, bleh = 0;

    cin >> n;

    cin >> k1;

    for (i = 0; i < k1; i++) {
        cin >> temp;

        q1.push(temp);
    }

    cin >> k2;

    for (i = 0; i < k2; i++) {
        cin >> temp;

        q2.push(temp);
    }

    while (++bleh < 500 && !q1.empty() && !q2.empty()) {
        if (q1.front() > q2.front()) {
            q1.push(q2.front());

            q2.pop();

            q1.push(q1.front());

            q1.pop();
        }
        else {
            q2.push(q1.front());

            q1.pop();

            q2.push(q2.front());

            q2.pop();
        }

        fights++;
    }

    if (bleh == 500) {
        cout << -1;
    }
    else {
        cout << fights << " " << (q1.empty() ? 2 : 1) << "\n";
    }

    return 0;
}