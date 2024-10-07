#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t, i, j, length = 0;

    cin >> n >> t;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0, j = 1; j <= n; ) {
        if (prefix[j] - prefix[i] <= t) {
            length = max(length, j - i);

            j++;
        }
        else {
            while (i < j && prefix[j] - prefix[i] > t) {
                i++;
            }
        }
    }

    cout << length << "\n";

    return 0;
}