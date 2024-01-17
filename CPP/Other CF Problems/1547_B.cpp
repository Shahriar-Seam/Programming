#include <bits/stdc++.h>

using namespace std;


void solve()
{
    string s1, s2;
    deque<char> dq;
    int size, t, low, pos, high, c = 1;
    char ch;

    cin >> s1;

    size = s1.size();
    t = s1.find('a');
    low = t - 1;
    high = t + 1;

    dq.push_front('a');

    for (ch = 'b'; ; ch++) {

        if (low < 0 && high >= size) {
            break;
        }

        pos = s1.find(ch);

        if (s1[low] == ch && low >= 0) {
            dq.push_front(ch);

            low--;
        }

        else if (s1[high] == ch && high < size) {
            dq.push_back(ch);

            high++;
        }
        else {
            break;
        }
    }

    string str(dq.begin(), dq.end());

    set <char> ss(dq.begin(), dq.end());

    if (str == s1 && ss.size() == s1.size()) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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