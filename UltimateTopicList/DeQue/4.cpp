#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque <int> dq;
    int q, n, r = 0;
    string op;

    cin >> q;

    while (q--) {
        cin >> op;

        if (op == "reverse") {
            r = !r;

            continue;
        }

        if (r == 0) {
            if (op == "back") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                }
                else {
                    cout << dq.back() << "\n";

                    dq.pop_back();
                }
            }
            else if (op == "front") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                }
                else {
                    cout << dq.front() << "\n";

                    dq.pop_front();
                }
            }
            else if (op == "push_back") {
                cin >> n;

                dq.push_back(n);
            }
            else {
                cin >> n;

                dq.push_front(n);
            }
        }
        else {
            if (op == "back") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                }
                else {
                    cout << dq.front() << "\n";

                    dq.pop_front();
                }
            }
            else if (op == "front") {
                if (dq.empty()) {
                    cout << "No job for Ada?\n";
                }
                else {
                    cout << dq.back() << "\n";

                    dq.pop_back();
                }
            }
            else if (op == "push_back") {
                cin >> n;

                dq.push_front(n);
            }
            else {
                cin >> n;

                dq.push_back(n);
            }
        }
    }

    return 0;
}