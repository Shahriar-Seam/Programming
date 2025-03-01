#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, n, f = 1;
    stack <char> st;

    cin >> s;

    n = s.size();

    for (i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<') {
            st.push(s[i]);
        }
        else if ((!st.empty()) && ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '>' && st.top() == '<'))) {
            st.pop();
        }
        else if (st.empty()) {
            f = 0;
        }
    }

    if (!st.empty()) {
        f = 0;
    }

    cout << (f ? "Yes" : "No") << "\n";

    return 0;
}