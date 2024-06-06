#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, i, len, j, cnt, index;
    string s;
    int b;
    char ch;

    cin >> t;

    while (t--) {
        cin >> n >> k;
        cin >> s;

        b = count(s.begin(), s.end(), 'B');
        len = s.length();
        cnt = 0;

        if (b == k) {
            cout << 0 << "\n";
        }
        else if (b > k) {
            for (i = 0; i < len; i++) {
                if (s[i] == 'B') {
                    cnt++;
                }

                if (b - cnt == k) {
                    index = i + 1;
                    break;
                }
            }

            cout << 1 << "\n";
            cout << index << " " << "A" << "\n";
        }
        else {
            for (i = 0; i < len; i++) {
                if (s[i] == 'A') {
                    cnt++;
                }

                if (b + cnt == k) {
                    index = i + 1;
                    break;
                }
            }

            cout << "1\n";
            cout << index << " B\n";
        }
    }

    return 0;
}