#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int t, n, i, temp, j;
    vector <unsigned int> v;
    int lower, upper, odd, even;

    cin >> t;

    while (t--) {
        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
        }

        lower = upper = 0;
        odd = even = 0;

        for (i = 0; i < n; i++) {
            if (v[i] < 1073741824) {
                lower++;
            }
            else {
                upper++;
            }

            if (v[i] % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        v.clear();

        cout << max({lower, upper, odd, even}) << "\n";
    }

    return 0;
}