#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
    // Doesn't work
    // Maybe tomorrow
};

int to_int(char c)
{
    return c - 'A' + 1;
}

void solve()
{
    char c;
    disjoint_set ds;
    string e;
    int tc;
    set <int> s;
    
    cin >> c;

    cin.ignore();

    ds.init(to_int(c) + 1);

    while (1) {
        getline(cin, e);

        if (e.empty()) {
            break;
        }

        ds._union(to_int(e[0]), to_int(e[1]));
    }

    cout << ds.number_of_connected_graphs() << "\n\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}