#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string op;
    int n;
    stack <int> s;

    while (true) {
        cin >> op;

        if (op == "exit") {
            cout << "bye\n";

            break;
        }
        else if (op == "push") {
            cin >> n;

            s.push(n);

            cout << "ok\n";
        }
        else if (op == "back") {
            cout << s.top() << "\n";
        }
        else if (op == "pop") {
            cout << s.top() << "\n";

            s.pop();
        }
        else if (op == "size") {
            cout << s.size() << "\n";
        }
        else if (op == "clear") {
            while (!s.empty()) {
                s.pop();
            }

            cout << "ok\n";
        }
    }

    return 0;
}