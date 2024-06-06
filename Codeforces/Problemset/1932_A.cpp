#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    string s;

    cin >> t;

    while (t--) {
        cin >> n >> s;

        unsigned long long pos = s.find("**");
        pos = n > pos ? pos : n;

        string sub = s.substr(0, pos);

        cout << count(sub.begin(), sub.end(), '@') << "\n";
    }

    return 0;
}