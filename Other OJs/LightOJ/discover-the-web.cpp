#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string op;
    stack <string> st_f, st_b;
    string current = "http://www.lightoj.com/";

    while (true) {
        cin >> op;

        if (op == "QUIT") {
            break;
        }
        else if (op == "BACK") {
            if (st_b.empty()) {
                cout << "Ignored\n";
            }
            else {
                st_f.push(current);

                current = st_b.top();
                st_b.pop();

                cout << current << "\n";
            }
        }
        else if (op == "FORWARD") {
            if (st_f.empty()) {
                cout << "Ignored\n";
            }
            else {
                st_b.push(current);

                current = st_f.top();
                st_f.pop();

                cout << current << "\n";
            }
        }
        else if (op == "VISIT") {
            st_b.push(current);

            while (!st_f.empty()) {
                st_f.pop();
            }

            cin >> current;

            cout << current << "\n";
        }
    }
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