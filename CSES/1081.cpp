#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, gcd, j, divisors;

    cin >> n;

    vector <int> v(n), counter(sz, 0);

    for (auto &it : v) {
        cin >> it;

        counter[it]++;
    }
    
    for (gcd = sz; gcd > 0; gcd--) {
        divisors = 0;

        for (j = gcd; j < sz; j += gcd) {
            divisors += counter[j];
        }

        if (divisors > 1) {
            cout << gcd << "\n";

            return 0;
        }
    }

    return 0;
}