#include <stdio.h>

int main()
{
    unsigned long long int t, n, i;
    unsigned long long int max_e, m_e_index, max_s, m_s_index;

    scanf("%llu", &t);

    while (t--) {
        scanf("%llu", &n);

        unsigned long long int arr[n][2];
        m_e_index = 0;
        m_s_index = 1;

        for (i = 0; i < n; i++) {
            scanf("%llu %llu", &arr[i][0], &arr[i][1]);
        }

        max_e = arr[0][1];
        max_s = arr[1][0];

        for (i = 1; i < n; i++) {
            if (arr[i][1] > max_e) {
                max_e = arr[i][1];
                m_e_index = i;
            }
            if (max_s < arr[i][0]) {
                max_s = arr[i][0];
                m_s_index = i;
            }
        }

        if (arr[m_e_index][0] >= arr[0][0]) {
            printf("-1\n");
        }
        else {
            printf("%llu\n", arr[0][0]);
        }
    }

    return 0;
}