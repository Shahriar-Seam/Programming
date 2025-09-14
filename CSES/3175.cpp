#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;

    cin >> n;

    vector <int> v(n);

    if (n == 1) {
        cout << 1 << "\n";
    }
    else if (n <= 4) {
        cout << "NO SOLUTION\n";
    }
    else {
        v[0] = 1;
        v[1] = 3;
        v[2] = 5;

        v[n - 1] = n - (n % 2);
        v[n - 2] = v[n - 1] - 2;

        for (i = 3, j = 0, k = 5; i < n - 2; i++) {
            if (i & 1) {
                v[i] = j += 2;
            }
            else {
                v[i] = k += 2;
            }
        }

        for (auto &it : v) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}