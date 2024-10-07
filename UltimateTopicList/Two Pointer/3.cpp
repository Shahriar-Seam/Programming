#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s, i, j, length = LONG_LONG_MAX;

    cin >> n >> s;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0, j = 1; j <= n; ) {
        if (prefix[j] - prefix[i] >= s) {
            while (i < j && prefix[j] - prefix[i] >= s) {
                i++;
            }

            length = min(length, j - i + 1);
        }
        else {
            j++;
        }
    }

    cout << (length < LONG_LONG_MAX ? length : -1) << "\n";

    return 0;
}