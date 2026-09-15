#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    stack <char> st;

    cin >> s;

    for (auto &c : s) {
        if (st.empty()) {
            st.push(c);
        }
        else {
            if (st.top() == c) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
    }

    while (!st.empty()) {
        t += st.top();
        st.pop();
    }

    ranges::reverse(t);

    cout << t << "\n";

    return 0;
}