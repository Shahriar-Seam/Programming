#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, i, r;

    cin >> t;

    while (t--) {
        cin >> n;

        r = sqrt(n);

        set<long long> num;

        for (i = 1; i <= r; i++) {
            if ((i * i <= n)) {
                num.insert(i * i);
            }
            if ((i * i * i <= n)) {
                num.insert(i * i * i);
            }
        }

        cout << num.size() << "\n";
    }

    return 0;
}
