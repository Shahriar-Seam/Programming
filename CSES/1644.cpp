#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b, max_sum = LONG_LONG_MIN;
    int i;

    cin >> n >> a >> b;

    vector <long long> v(n), prefix(n + 1, 0);
    multiset <long long> ms;
 
    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + v[i];
    }

    for (i = a; i <= n; i++) {
        if (i > b) {
            ms.erase(ms.find(prefix[i - b - 1]));
        }

        ms.insert(prefix[i - a]);

        max_sum = max(max_sum, prefix[i] - *ms.begin());
    }

    cout << max_sum << "\n";

    return 0;
}
