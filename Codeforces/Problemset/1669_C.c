#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int check(int arr[], int n)
{
    int odd = arr[0] % 2;
    int flag = 0, i;

    if (odd) {
        for (i = 1; i < n; i++) {
            if (arr[i] % 2 == 0) {
                flag = 1;
            }
        }
    }
    else {
        for (i = 1; i < n; i++) {
            if (arr[i] % 2 == 1) {
                flag = 1;
            }
        }
    }

    return flag;
}

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        int arr[n];

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int flag = check(arr, n);

        if (!flag) {
            yes;
        }
        else {
            for (i = 0; i < n; i += 2) {
                arr[i]++;
            }

            if(!check(arr, n)) {
                yes;
            }
            else {
                no;
            }
        }
    }

    return 0;
}