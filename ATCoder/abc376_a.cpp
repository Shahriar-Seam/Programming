#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, i, prev = 0, temp, candies = 0;

    cin >> n >> c;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (i == 0) {
            prev = temp;

            candies++;
        }
        else {
            if (temp - prev >= c) {
                candies++;
                prev = temp;
            }
        }
    }

    cout << candies << "\n";

    return 0;
}