#include <bits/stdc++.h>

using namespace std;

#define sz 100000005
vector <int> marked(sz, 1);
vector <int> prefix(sz + 1, 0);

void sieve()
{
    int i, j;

    marked[0] = marked[1] = 0;
    
    for (i = 4; i < sz; i += 2) {
        marked[i] = 0;
    }

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += i + i) {
                marked[j] = 0;
            }
        }
    }

    for (i = 0; i < sz; i++) {
        prefix[i + 1] = prefix[i] + marked[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i;

    sieve();

    cin >> t;

    while (t--) {
        cin >> n;

        if (!marked[n]) {
            cout << -1 << "\n";
        }
        else {
            long long row = (-1 + sqrt(1 + 8 * prefix[n])) / 2;
            long long col = prefix[n] - (row * (row + 1)) / 2;

            cout << row + 1 << " " << col + 1 << "\n";
        }
    }

    return 0;
}