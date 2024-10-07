#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, s, count = 0, i, j;

    cin >> n >> s;

    vector <long long> v(n), prefix(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = 0, j = 1; j <= n; ) {
        if (prefix[j] - prefix[i] <= s) {
            j++;

            long long temp = j - i + 1;

            count += (temp * (temp + 1)) / 2;
        }
        else {
            while (i < j && prefix[j] - prefix[i] > s) {
                i++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}