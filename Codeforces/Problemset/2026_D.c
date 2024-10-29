#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long *arr, long long n, long long val)
{
    long long l = 0, r = n - 1, mid;

    while (l < r) {
        mid = (l + r) / 2;

        if (arr[mid] >= val) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}

int main()
{
    long long n, i, q, l, r;
    long long sum_of_first_block = 0, sum = 0;

    scanf("%lld", &n);

    long long arr[n];
    long long *brr = (long long *) calloc(n + 1, sizeof(long long));
    long long *index_pref = (long long *) calloc(n + 1, sizeof(long long));
    long long *sums_of_blocks = (long long *) calloc(n + 1, sizeof(long long));
    long long *b_pref = (long long *) calloc(n + 1, sizeof(long long));

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    for (i = 0; i < n; i++) {
        brr[i + 1] = brr[i] + arr[i];
    }

    for (i = 0; i < n; i++) {
        index_pref[i + 1] = index_pref[i] + n - i;
    }

    for (i = 1; i <= n; i++) {
        sum_of_first_block += brr[i];
    }

    for (i = 1; i <= n; i++) {
        b_pref[i] = b_pref[i - 1] + brr[i];
    }

    for (i = 0; i < n; i++) {

    }

    printf("%lld\n", sum_of_first_block);

    sums_of_blocks[0] = sum_of_first_block;

    for (i = 0; i < n; i++) {
        sums_of_blocks[i + 1] = sums_of_blocks[i] - arr[i] * (n - i);
    }

    // 1 based
    for (i = n; i > 0; i--) {
        sums_of_blocks[i] = sums_of_blocks[i - 1];
    }

    sums_of_blocks[0] = 0;

    l = 3, r = 6;

    long long index1 = lower_bound(index_pref, n + 1, l);
    long long index2 = lower_bound(index_pref, n + 1, r);

    printf("%lld %lld\n", index1, index2);

    for (i = index1; i <= index2; i++) {
        sum += sums_of_blocks[i];
    }

    printf("%lld\n", index_pref[index2]);
    printf("%lld\n", sums_of_blocks[index2]);
    printf("%lld\n", b_pref[index2]);

    printf("%lld\n", sum);

    // scanf("%lld", &q);

    // while (q--) {
    //     scanf("%lld %lld", &l, &r);


    // }

    for (i = 1; i <= n; i++) {
        printf("%lld ", brr[i]);
    }

    printf("\n");

    for (i = 1; i <= n; i++) {
        printf("%lld ", b_pref[i]);
    }

    printf("\n");

    for (i = 1; i <= n; i++) {
        printf("%lld ", sums_of_blocks[i]);
    }

    printf("\n");

    // long long index = lower_bound(index_pref, n + 1, 8);

    // printf("%lld\n", pref[n - _pref[index] + 8] - pref[_pref[index] - 8 + 1]);


    return 0;
}