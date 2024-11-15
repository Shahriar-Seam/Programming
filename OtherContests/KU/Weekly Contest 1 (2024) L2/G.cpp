#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    stack <int> st;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        while (!st.empty()) {
            if (v[st.top()] >= v[i]) {
                st.pop();
            }
            else {
                break;
            }
        }

        if (st.empty()) {
            cout << 0 << " ";
        }
        else {
            cout << st.top() + 1 << " ";
        }

        st.push(i);
    }

    return 0;
}