#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, i;
    set <long long> s;

    cin >> n >> k;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert(n / i);
        }
    }

    if (s.size() < k) {
        cout << -1;
    }
    else {
        i = 0;

        for (auto it : s) {
            i++;

            if (i == k) {
                cout << it;
            }
        }
    }

    return 0;
}