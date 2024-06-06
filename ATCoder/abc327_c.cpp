#include <bits/stdc++.h>

using namespace std;

int is_once(int *arr)
{
    int i;

    sort(arr, arr + 9);

    for (i = 1; i < 10; i++) {
        if (arr[i - 1] != i) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int arr[9][9], arr2[9];
    int i, j, k, x, y;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            arr2[j] = arr[i][j];
        }

        if (!is_once(arr2)) {
            cout << "No";

            return 0;
        }
    }
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            arr2[j] = arr[j][i];
        }

        if (!is_once(arr2)) {
            cout << "No";

            return 0;
        }
    }

    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            k = 0;

            for (x = i; x < i + 3; x++) {
                for (y = j; y < j + 3; y++) {
                    arr2[k++] = arr[x][y];
                }
            }

            if (!is_once(arr2)) {
                cout << "No";

                return 0;
            }
        }
    }

    cout << "Yes";

    return 0;
}