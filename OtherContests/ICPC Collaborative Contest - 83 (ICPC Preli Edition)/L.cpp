#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max_gcd = 0, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    max_gcd = *min_element(v.begin(), v.end());

    if (max_gcd == 1) {
        cout << 1 << "\n";

        return 0;
    }

    for (i = 0; i < n; i++) {
        if (v[i] % max_gcd != 0 && v[i] < 2 * max_gcd) {
            max_gcd /= 2;

            break;
        }
    }

    cout << max_gcd << "\n";

    return 0;
}