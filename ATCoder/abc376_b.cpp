#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, l = 1, r = 2, t, count = 0;
    char h;

    cin >> n >> q;

    while (q--) {
        cin >> h >> t;

        if (h == 'L') {
            if (l < t && t < r) {
                count += t - l;
            }
            else if (l < r && r < t) {
                count += l + n - t;
            }
            else if (r < t && t < l) {
                count += l - t;
            }
            else if (r < l && l < t) {
                count += t - l;
            }
            else if (t < l && l < r) {
                count += l - t;
            }
            else if (t < r && r < l) {
                count += t + n - l;
            }

            l = t;
        }
        else {
            if (l < t && t < r) {
                count += r - t;
            }
            else if (l < r && r < t) {
                count += t - r;
            }
            else if (r < t && t < l) {
                count += t - r;
            }
            else if (r < l && l < t) {
                count += r + n - t;
            }
            else if (t < l && l < r) {
                count += t + n - r;
            }
            else if (t < r && r < l) {
                count += r - t;
            }

            r = t;
        }
    }

    cout << count << "\n";

    return 0;
}