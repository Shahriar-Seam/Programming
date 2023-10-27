#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, j, c = 0;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (j = 0; j < 32; j++) {
        for (i = 0; i < n; i++) {
            if (arr[i] % 2 == 1) {
                c = 1;
                break;
            }
            else {
                arr[i] /= 2;
            }
        }

        if (c == 1) {
            break;
        }
    }

    cout << j;
}