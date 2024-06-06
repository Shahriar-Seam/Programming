#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, n, num, sum;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> n;

        sum = 0;

        while (n--) {
            cin >> num;

            if (num > 0) {
                sum += num;
            }
        }

        cout << "Case " << i << ": " << sum << "\n";
    }

    return 0;
}