#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0, last = 0;

    cin >> n;

    count = n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }
    
    for (i = 0; i < n; i++) {
        if (i <= last) {
            last = max(last, i + v[i] - 1);
        }
        else {
            count = i;

            break;
        }
    }

    cout << count << "\n";

    return 0;
}