#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s, i, j, length = 0;

    cin >> n >> s;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0, j = 0; j < n; ) {
        if (prefix[j + 1] - prefix[i] <= s) {
            length = max(length, j - i + 1);

            j++;
        }
        else {
            while (i <= j && prefix[j + 1] - prefix[i] > s) {
                i++;
            }
        }
    }

    cout << length << "\n";

    return 0;
}