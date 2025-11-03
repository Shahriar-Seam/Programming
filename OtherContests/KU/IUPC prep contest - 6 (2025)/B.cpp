#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    int current = 0, count = 0, f = 1;

    cin >> n >> d;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : v) {
        if (it == 0) {
            if (current < 0) {
                current = 0;
                count++;
            }
        }
        else {
            current += it;
        }

        if (current > d) {
            f = 0;
        }
    }

    cout << (f ? count : -1) << "\n";

    return 0;
}