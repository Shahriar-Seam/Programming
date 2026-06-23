#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e6 + 5;
vector <int> phi(sz), p(sz, 0), g(sz, 0);
vector <bool> marked(sz, false);

void sieve_phi()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        phi[i] = i;
    }

    phi[1] = 1;
    marked[1] = true;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = true;

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void fill()
{
    int i, j, k;

    for (k = 2; k < sz; k++) {
        for (j = 1; j * k < sz; j++) {
            p[j * k] += j * phi[k];
        }
    }

    g[2] = 1;

    for (i = 3; i < sz; i++) {
        g[i] = g[i - 1] + p[i];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();
    fill();

    int n;
    
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        cout << g[n] << "\n";
    }

    return 0;
}