#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, *arr, i, j, temp;

    cin >> n;

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}