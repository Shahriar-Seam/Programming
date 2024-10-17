#include <bits/stdc++.h>

using namespace std;

#define sz 1000005
vector <int> marked(sz, 1);
vector <int> prefix(sz + 1, 0);

bool is_scary(int n)
{
    while (n > 0) {
        if (n % 10 == 0) {
            return false;
        }

        n /= 10;
    }

    return true;
}

bool changu_mangu(int n)
{
    int mod = 1;

    while (n % mod != n) {
        mod *= 10;

        if (!marked[n % mod]) {
            return false;
        }
    }

    return true;
}

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

    for (i = 3; i < sz; i += 2) {
        if (marked[i] && (!is_scary(i) || !changu_mangu(i))) {
            marked[i] = 0;
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

        cout << prefix[n + 1] << "\n";
    }

    return 0;
}