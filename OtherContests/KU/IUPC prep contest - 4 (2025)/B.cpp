#include <bits/stdc++.h>

using namespace std;

vector <int> get_divisors(int n)
{
    int i;
    vector <int> divisors;

    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            
            divisors.push_back(n / i);
        }
    }

    if (i * i == n) {
        divisors.push_back(i);
    }

    return divisors;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, max_gcd = 1;
    map <int, int> divisors;

    cin >> n;

    vector <int> v(n), temp;

    for (auto &it : v) {
        cin >> it;
    }

    temp = get_divisors(v[0]);

    for (auto it : temp) {
        divisors[it]++;
    }

    temp = get_divisors(v[1]);

    for (auto it : temp) {
        divisors[it]++;
    }

    for (i = 2; i < n; i++) {
        for (auto &it : divisors) {
            if (v[i] % it.first == 0) {
                it.second++;
            }
        }
    }

    for (auto it : divisors) {
        if (it.second >= n - 1) {
            max_gcd = max(max_gcd, it.first);
        }
    }

    cout << max_gcd << "\n";

    return 0;
}