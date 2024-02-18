#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, odd, even, temp, type, x;
    long long sum;

    cin >> t;

    while (t--) {
        cin >> n >> q;

        odd = even = 0;
        sum = 0LL;

        while (n--) {
            cin >> temp;

            sum += 1LL * temp;

            if (temp % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        while (q--) {
            cin >> type >> x;

            if (type == 0) {
                sum += 1LL * x * even;

                if (x % 2 == 1) {
                    odd += even;
                    even = 0;
                }
            }
            else {
                sum += 1LL * x * odd;

                if (x % 2 == 1) {
                    even += odd;
                    odd = 0;
                }
            }

            cout << sum << "\n";
        }
    }

    return 0;
}


