#include <bits/stdc++.h>

using namespace std;

string s = "1";

void fill_string()
{
    int i;
    string temp = "1";

    for (i = 0; i < 1000; i++) {
        temp += "0";

        s += temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    fill_string();

    cout << s.size();

    return 0;

    cin >> t;

    while (t--) {
        cin >> n;

        cout << s[n - 1] << " ";
    }

    return 0;
}