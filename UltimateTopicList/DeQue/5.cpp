#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    deque <int> dq1, dq2;
    int n, k1, k2, i, temp, fights = 0, bleh = 0;

    cin >> n;

    cin >> k1;

    for (i = 0; i < k1; i++) {
        cin >> temp;

        dq1.push_back(temp);
    }

    cin >> k2;

    for (i = 0; i < k2; i++) {
        cin >> temp;

        dq2.push_back(temp);
    }

    while (!dq1.empty() && !dq2.empty()) {
        if (dq1.front() > dq2.front()) {
            dq1.push_back(dq2.front());

            dq2.pop_front();

            dq1.push_back(dq1.front());

            dq1.pop_front();
        }
        else {
            dq2.push_back(dq1.front());

            dq1.pop_front();

            dq2.push_back(dq2.front());

            dq2.pop_front();
        }

        fights++;

        if (fights == 500) {
            bleh = 1;
            break;
        }
    }

    if (bleh == 1) {
        cout << -1;
    }
    else {
        cout << fights << " " << (dq1.empty() ? 2 : 1) << "\n";
    }

    return 0;
}