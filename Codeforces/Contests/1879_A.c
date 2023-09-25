#include <stdio.h>

int main()
{
    long long int t, n, i;
    long long int max_e, m_e_index;

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld", &n);

        long long int arr[n][2];
        m_e_index = 1;

        for (i = 0; i < n; i++) {
            scanf("%lld %lld", &arr[i][0], &arr[i][1]);
        }

        max_e = arr[1][1];

        for (i = 2; i < n; i++) {
            if (arr[i][1] > max_e) {
                max_e = arr[i][1];
                m_e_index = i;
            }
        }

        if (arr[m_e_index][0] >= arr[0][0]) {
            printf("-1\n");
        }
        else if (max_e == arr[0][1]) {
            printf("-1\n");
        }
        else if (arr[m_e_index][0] + 1 > 1000000000) {
            printf("-1\n");
        }
        else {
            printf("%lld\n", arr[m_e_index][0] + 1);
        }
    }

    return 0;
}