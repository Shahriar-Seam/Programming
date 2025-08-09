#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, count = 0, cnt = 0, z = 0;
    string s;

    cin >> n >> s;

    for (i = 0; i < n; ) {
        if (s[i] == '0') {
            cnt = 0;

            while (i < n && s[i] == '0') {
                i++;

                z++;

                count += z / 2;

                cnt++;
            }

            count += cnt * (cnt / 2) - (cnt / 2) * (cnt / 2);
        }
        else {
            cnt = 0;

            while (i < n && s[i] == '1') {
                i++;

                cnt++;
            }

            count += (cnt * (cnt + 1)) / 2;

            count += cnt * (z / 2);
        }
    }

    cout << count << "\n";

    return 0;
}