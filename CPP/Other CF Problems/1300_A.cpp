#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, sum, temp, steps;

    cin >> t;

    while (t--) {
        cin >> n;

        sum = steps = 0;

        for (i = 0; i < n; i++) {
            cin >> temp;

            if (temp == 0) {
                steps++;
                temp++;
            }

            sum += temp;
        }

        if (sum == 0) {
            steps++;
        }

        cout << steps << "\n";
    }

    return 0;
}