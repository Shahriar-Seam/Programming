#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e5 + 5;
vector <bool> marked(sz, true);
vector <int> primes;

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    for (i = 4; i < sz; i += 2) {
        marked[i] = false;
    }

    marked[2] = true;

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

void test(vector <int> &v, int n)
{
    int p = 1;

    for (auto &it : v) {
        p *= it;

        p %= n;
    }

    if (p != 1) {
        v.pop_back();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, i;
    vector <int> v;

    cin >> n;

    if (marked[n]) {
        for (i = 1; i < n - 1; i++) {
            v.push_back(i);
        }
    }
    else {
        if (n & 1) {
            for (i = 1; i < n; i++) {
                if (gcd(i, n) == 1) {
                    v.push_back(i);
                }
            }
        }
        else {
            for (i = 1; i < n; i += 2) {
                if (gcd(i, n) == 1) {
                    v.push_back(i);
                }
            }
        }
    }

    if (v.size() <= 2) {
        cout << "1\n1\n";

        return 0;
    }

    test(v, n);

    cout << v.size() << "\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}