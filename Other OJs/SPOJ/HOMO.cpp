#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, count = 0;
    string op;
    map <int, int> mp;

    cin >> n;

    while (n--) {
        cin >> op >> k;

        if (op == "insert") {
            mp[k]++;

            if (mp[k] == 2) {
                count++;
            }
        }
        else {
            if (mp.find(k) != mp.end()) {
                mp[k]--;

                if (mp[k] == 1) {
                    count--;
                }

                if (mp[k] == 0) {
                    mp.erase(k);
                }
            }
        }

        if (count > 0 && mp.size() > 1) {
            cout << "both\n";
        }
        else if (count > 0) {
            cout << "homo\n";
        }
        else if (mp.size() > 1) {
            cout << "hetero\n";
        }
        else {
            cout << "neither\n";
        }
    }

    return 0;
}