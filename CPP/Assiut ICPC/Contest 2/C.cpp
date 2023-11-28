#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, *num, *K, i, j, s;

    cin >> n >> k;

    s = ceil((double) n / k);

    num = (int *) calloc(n + k, sizeof(int));
    K = (int *) calloc(s, sizeof(int));

    for (i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (i = n; i < n + k; i++) {
        num[i] = 1000000002;
    }

    for (i = 0, j = 0; i < n; i += k, j++) {
        K[j] = *min_element(&num[i], &(num[i]) + k);
    }

    for (i = 0; i < s; i++) {
        cout << K[i] << " ";
    }

    return 0;
}