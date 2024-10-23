#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, op, n;
    stack <int> st;

    cin >> t;

    while (t--) {
        cin >> op;

        if (op == 1) {
            cin >> n;

            st.push(n);
        }
        else if (op == 2) {
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            if (!st.empty()) {
                cout << st.top() << "\n";
            }
            else {
                cout << "Empty!\n";
            }
        }
    }

    return 0;
}