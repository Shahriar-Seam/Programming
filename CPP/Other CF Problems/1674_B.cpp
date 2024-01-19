#include <bits/stdc++.h>

using namespace std;

void fill_array(vector <string> &v)
{
    char i, j;
    string s;

    for (i = 'a'; i <= 'z'; i++) {
        for (j = 'a'; j <= 'z'; j++) {
            if (i != j) {
                s = i;
                s += j;

                v.push_back(s);
            }
        }
    }
}

int find_index(vector <string> &v, string s)
{
    int i;

    for (i = 0; i < v.size(); i++) {
        if (v.at(i) == s) {
            return i + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, n;
    string s;
    vector <string> str;

    fill_array(str);

    cin >> n;

    while (n--) {
        cin >> s;

        cout << find_index(str, s) << "\n";
    }

    return 0;
}