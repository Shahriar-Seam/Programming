#include <bits/stdc++.h>

#define yes cout << "yes"
#define no cout << "no"

using namespace std;

int main()
{
    int n, *arr1, *arr2, f = 1, i;

    cin >> n;

    arr1 = (int *) malloc(sizeof(int) * n);
    arr2 = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);

    for (i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            f = 0;
            break;
        }
    }

    f ? yes : no;

    return 0;
}