#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, i, j, count = 0;

    cin >> n >> x;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0, j = 1; j <= n; ) {
        if (prefix[j] - prefix[i] == x) {
            count++;
            j++;
            i++;
        }
        else if (prefix[j] - prefix[i] < x) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << count << "\n";

    return 0;
}