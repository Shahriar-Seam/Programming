#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <int> get_divisors(int n)
{
    vector <int> divisors {1};
    int i, j, x, count = 0, current_size;
    bool flag;

    for (i = 2; i * i <= n; i++) {
        count = 0;

        while (n % i == 0) {
            n /= i;
            count++;
        }

        flag = false;
        x = i;
        current_size = divisors.size();
        
        while (count--) {
            if (flag) {
                for (j = 0; j < current_size; j++) {
                    divisors.push_back(x * divisors[j]);
                }
            }
            else {
                for (j = current_size - 1; j >= 0; j--) {
                    divisors.push_back(x * divisors[j]);
                }
            }

            flag ^= true;
            x *= i;
        }
    }

    if (n > 1) {
        for (j = divisors.size() - 1; j >= 0; j--) {
            divisors.push_back(divisors[j] * n);
        }
    }

    return divisors;
}

void solve()
{
    int n;

    cin >> n;

    vector <int> divisors = get_divisors(n);
    
    for (auto it : divisors) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";

        solve();
    }

    return 0;
}