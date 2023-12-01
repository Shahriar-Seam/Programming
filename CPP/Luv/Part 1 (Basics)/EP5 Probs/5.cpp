#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string command;

    cin >> command;

    int i, l = command.size();
    string s;

    for (i = 0; i < l; ) {
        if (command[i] == '(') {
            if (command[i + 1] == ')') {
                s.push_back('o');
                i += 2;
            }
            else {
                s += "al";
                i += 4;
            }
        }
        else {
            s.push_back(command[i]);
            i++;
        }
    }

    cout << s;

    return 0;
}