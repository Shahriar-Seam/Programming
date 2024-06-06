#include <bits/stdc++.h>

using namespace std;

int max_size = 10000005;
int *marked;

void sieve()
{
    int i, j;

    marked = (int *) calloc(max_size, sizeof(int));
    marked[0] = 1;

    for (i = 1; i < max_size; i += 2) {
        marked[i] = i;
    }
    
    for (i = 2; i < max_size; i += 2) {
        marked[i] = 2;
    }

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked[i] == i) {
            for (j = i * i; j <= max_size; j += i + i) {
                if (marked[j] == j) {
                    marked[j] = i;
                }
            }
        }
    }
}

void find_divisor(int n, int *d1, int *d2)
{
    int i, p;
    
    p = marked[n];

    *d1 = p;

    while (n % p == 0) {
        n /= p;
    }

    *d2 = marked[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, i, d1, d2;

    cin >> n;

    int arr[n];
    int d[n][2];

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        d1 = d2 = -1;

        find_divisor(arr[i], &d1, &d2);

        if (d2 == -1 || d2 == 1) {
            d1 = -1;
            d2 = -1;
        }

        d[i][0] = d1;
        d[i][1] = d2;
    }

    for (i = 0; i < n; i++) {
        cout << d[i][0] << " ";
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        cout << d[i][1] << " ";
    }

    return 0;
}
