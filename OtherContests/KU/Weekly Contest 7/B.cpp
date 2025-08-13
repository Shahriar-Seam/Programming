#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, z = 0, o = 0;
    string s;
    stack <char> st;

    cin >> s;

    n = s.size();

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            st.push(s[i]);
        }
        else {
            if (st.empty()) {
                st.push(s[i]);
            }
            else {
                if (st.top() == '0') {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
    }

    string ss;

    while (!st.empty()) {
        ss += st.top();

        st.pop();
    }

    reverse(ss.begin(), ss.end());

    cout << ss.size() << "\n";

    cout << ss << "\n";

    return 0;
}