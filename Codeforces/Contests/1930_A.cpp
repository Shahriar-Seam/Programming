#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp;
    long long sum;
    vector <int> v;

    cin >> t;

    while (t--) {
        cin >> n;

        sum = 0;

        for (i = 0; i < 2 * n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        sort(v.begin(), v.end());

        for (i = 0; i < 2 * n; i += 2) {
            sum += 1LL * v[i];
        }

        cout << sum << "\n";

        v.clear();
    }

    return 0;
}