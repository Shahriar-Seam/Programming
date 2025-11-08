#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, i, count = 0;
    vector <int> f = {1};

    for (i = 1; i <= 10; i++) {
        f.push_back(f.back() * i);
    }

    cin >> p;

    for (i = f.size() - 1; i > 0; i--) {
        if (p >= f[i]) {
            count += p / f[i];

            p %= f[i];
        }
    }

    cout << count << "\n";

    return 0;
}