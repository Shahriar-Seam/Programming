#include <bits/stdc++.h>

using namespace std;

#define max_size 100000
int marked_array[max_size + 1];
vector <vector <int> > factors(max_size + 5, vector <int> ());

void sieve()
{
    int i, j;

    for (i = 2; i <= max_size; i += 2) {
        marked_array[i] = 2;
    }
    
    for (i = 1; i <= max_size; i += 2) {
        marked_array[i] = i;
    }

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked_array[i] == i) {
            for (j = i * i; j <= max_size; j += i + i) {
                if (marked_array[j] == j) {
                    marked_array[j] = i;
                }
            }
        }
    }
}

void fill_factors()
{
    int i, n, p;

    for (i = 2; i <= 100000; i++) {
        n = i;

        while (n > 1) {
            p = marked_array[n];

            factors[i].push_back(p);

            while (n % p == 0) {
                n /= p;
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill_factors();

    int i;

    for (i = 2; i <= 100000; i++) {
        cout << i << ": ";

        for (auto it : factors[i]) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}