#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    string cmd;
    list <int> l;

    cin >> n;

    while (n--) {
        cin >> cmd;

        if (cmd == "insert") {
            cin >> x;

            l.push_front(x);
        }
        else if (cmd == "delete") {
            cin >> x;

            auto it = find(l.begin(), l.end(), x);

            if (it != l.end()) {
                l.erase(it);
            }
        }
        else if (cmd == "deleteFirst") {
            l.pop_front();
        }
        else {
            l.pop_back();
        }
    }

    vector <int> v(l.begin(), l.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];

        if (i != v.size() - 1) {
            cout << " ";
        }
        else {
            cout << "\n";
        }
    }

    return 0;
}