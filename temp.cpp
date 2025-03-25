#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clock_t start, end;

    start = clock();

    freopen("bleh.txt", "w", stdout);

    int n, i, j, x;

    cin >> n;

    vector <int> v(n + 1);

    for (i = 1; i <= n; i++) {
        x = 0;

        for (j = 1; j <= i; j++) {
            x ^= i % j;
        }

        v[i] = x;
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << ", ";
    }

    end = clock();
    cerr << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}