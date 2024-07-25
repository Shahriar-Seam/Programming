#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack <char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                return false;
            }
            if ((c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.size() == 0 ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    cout << (isValid(s) ? "Yes" : "No");

    return 0;
}