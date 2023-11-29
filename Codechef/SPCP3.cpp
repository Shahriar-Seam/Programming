#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, a1, b1, a2, b2, cnt1, cnt2;

    cin >> t;

    while (t--) {
        cin >> a1 >> b1;

        a2 = a1;
        b2 = b1;

        cnt1 = cnt2 = 0;

        while (a1 % b1 != 0) {
            a1++;
            b1--;
            cnt1++;
        }
        while (a2 % b2 != 0) {
            a2--;
            b2++;
            cnt2++;
        }

        cout << min(cnt1, cnt2) << "\n";
    }

    return 0;
}