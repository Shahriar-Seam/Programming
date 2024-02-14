#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5][5] = {};
    int i, j, a, b;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (arr[i][j] == 1) {
                a = i;
                b = j;
            }
        }
    }

    cout << abs(2 - a) + abs(2 - b);

    return 0;
}