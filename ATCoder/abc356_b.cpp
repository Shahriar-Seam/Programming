#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, sum, f = 1;
    
    cin >> n >> m;

    vector <int> target(m);
    int arr[n][m];

    for (auto &it : target) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        sum = 0;

        for (j = 0; j < n; j++) {
            sum += arr[j][i];
        }

        if (sum < target[i]) {
            f = 0;

            break;
        }
    }

    cout << (f == 1 ? "Yes" : "No");

    return 0;
}