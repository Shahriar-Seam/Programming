#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, beauty = 0, temp;
    priority_queue <int> even, odd;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        if (it % 2 == 0) {
            even.push(it);
        }
        else {
            odd.push(it);
        }
    }

    if (odd.empty()) {
        cout << even.top() << "\n";

        return;
    }

    if (even.empty()) {
        cout << odd.top() << "\n";

        return;
    }

    if (odd.top() > even.top()) {
        beauty += odd.top();
        odd.pop();
    }
    else {
        beauty += even.top();
        even.pop();
    }

    while (true) {
        if (even.empty() || odd.empty()) {
            break;
        }

        if (beauty % 2 == 0) {
            temp = odd.top();
            odd.pop();

            beauty += temp;
        }
        else {
            temp = even.top();
            even.pop();

            beauty += temp - 1;

            if (temp > 1) {
                odd.push(1);
            }
        }
    }

    if (beauty % 2 == 0) {
        while (odd.size() > 1) {
            beauty += odd.top() - 1;
            odd.pop();
        }

        if (!odd.empty()) {
            beauty += odd.top();
        }
    }
    else {
        while (!even.empty()) {
            beauty += even.top();
            even.pop();
        }
    }

    cout << beauty << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}