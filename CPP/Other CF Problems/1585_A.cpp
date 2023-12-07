
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, pre, post, i, cnt, dead;

    cin >> t;

    while (t--) {
        cin >> n >> pre;

        if (n == 1) {
            cout << 1 + pre << "\n";
            continue;
        }

        cnt = 1 + pre;
        dead = 0;

        for (i = 1; i < n; i++) {          
            cin >> post;

            if (dead) {
                continue;
            }

            if (post == 1) {
                if (pre == 1) {
                    cnt += 5;
                }
                else {
                    cnt += 1;
                }
            }
            else if (pre == 0) {
                dead = 1;
            }

            pre = post;
        }

        dead ? cout << "-1\n" : cout << cnt << "\n";
    }

    return 0;
}