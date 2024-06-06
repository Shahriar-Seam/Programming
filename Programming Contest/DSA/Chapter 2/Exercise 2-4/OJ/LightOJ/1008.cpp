#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;
    long long s, root, r, c, l, temp;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cin >> s;

        root = ceil(sqrt((double) s));

        l = root * root - s;

        if (l < root) {
            r = root;
            c = l + 1;
        }
        else {
            c = root;
            r = s - (root - 1) * (root - 1);
        }

        if (root % 2 == 0) {
            temp = r;
            r = c;
            c = temp;
        }

        cout << "Case " << i << ": " << c << " " << r << "\n";
    }

    return 0;
}