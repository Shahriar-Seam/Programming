#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, cnt = 0;
    string s;
    map <char, int> mp;
    deque <char> dq;

    cin >> s;

    for (i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }

    for (auto it : mp) {
        cnt += (it.second % 2);
    }

    if (cnt > 1) {
        cout << "NO SOLUTION\n";
    }
    else {
        for (auto it : mp) {
            if (it.second % 2 == 1) {
                while (it.second > 0) {
                    dq.push_back(it.first);

                    it.second = it.second - 1;
                }

                mp.erase(it.first);

                break;
            }
        }

        for (auto it : mp) {
            while (it.second > 0) {
                if (it.second % 2 == 0) {
                    dq.push_back(it.first);
                }
                else {
                    dq.push_front(it.first);
                }

                it.second = it.second - 1;
            }
        }

        for (auto it : dq) {
            cout << it;
        }
    }

    return 0;
}