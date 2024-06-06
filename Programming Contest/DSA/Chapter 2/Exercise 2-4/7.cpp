#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int j;
    double x, n, i, sum = 0;

    cin >> x >> n;

    for (i = j = 0; i <= n; i += 2, j++) {
        if (j % 2 == 0) {
            sum += pow(x, i) / tgamma(i + 1);
        }
        else {
            sum -= pow(x, i) / tgamma(i + 1);
        }
    }

    printf("%g\n", sum);

    return 0;
}