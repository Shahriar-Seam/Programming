#include <bits/stdc++.h>

using namespace std;

struct brackets {
    char ch;
    int prefix;
    int position;
};

typedef brackets brackets;

bool compare(brackets a, brackets b)
{
    if (a.prefix != b.prefix) {
        return a.prefix > b.prefix;
    }
    else {
        return a.position < b.position;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, prefix_balance = 0;
    string s;
    vector <brackets> b;
    brackets temp;

    cin >> s;

    // reverse(s.begin(), s.end());

    for (i = 0; i < s.size(); i++) {
        if (i > 0) {
            if (s[i - 1] == '(') {
                prefix_balance++;
            }
            else {
                prefix_balance--;
            }
        }

        temp.ch = s[i];
        temp.prefix = prefix_balance;
        temp.position = i + 1;

        b.push_back(temp);
    }

    sort(b.begin(), b.end(), compare);

    for (auto it = b.rbegin(); it != b.rend(); it++) {
        cout << (*it).ch;
    }

    return 0;
}