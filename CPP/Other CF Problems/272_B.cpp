#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, temp;
    long long pairs = 0;
    vector <int> v(35, 0);

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> temp;

        v[__popcount(temp)]++;
    }

    for (i = 0; i < 35; i++) {
        pairs += (1LL * v[i] * (v[i] - 1)) / 2;
    }

    cout << pairs << "\n";

    return 0;
}