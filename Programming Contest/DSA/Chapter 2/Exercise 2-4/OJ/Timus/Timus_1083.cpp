#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, i, fact = 1;
    string s;

    cin >> n >> s;

    k = s.size();

    if (n % k == 0) {
        for (i = 0; n - i * k >= k; i++) {
            fact *= (n - i * k);
        }
    }
    else {
        for (i = 0; n - i * k >= n % k; i++) {
            fact *= (n - i * k);
        }
    }

    cout << fact;

    return 0;
}