#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, l, r, pos;
    char ch;
    string s, qq;

    cin >> n >> q;
    cin >> s;

    while (q--) {
        cin >> qq;

        if (qq == "pop_back") {
            s.pop_back();
        }
        else if (qq == "front") {
            cout << s[0] << "\n";
        }
        else if (qq == "back") {
            cout << s.back() << "\n";
        }
        else if (qq == "sort") {
            cin >> l >> r;

            sort (s.begin() + l - 1, s.begin() + r);
        }
        else if (qq == "reverse") {
            cin >> l >> r;

            reverse (s.begin() + l - 1, s.begin() + r);
        }
        else if (qq == "print") {
            cin >> pos;

            cout << s[pos - 1];
        }
        else if (qq == "substr") {
            cin >> l >> r;

            cout << s.substr(l - 1, r - l + 1) << "\n";
        }
        else if (qq == "push_back") {
            cin >> ch;

            s.push_back(ch);
        }
    }

    return 0;
}