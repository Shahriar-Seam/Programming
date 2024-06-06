#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, temp;
    vector <int> v, vv;
    set <int> s, st, ss;

    cin >> t;

    while (t--) {
        cin >> n;

        for (i = 0; i < n; i++) {
            cin >> temp;

            v.push_back(temp);
            vv.push_back(temp);
        }

        while (!v.empty()) {
            auto m = max_element(v.begin(), v.end());

            s.insert(*m + (m - v.begin()) + 1);

            v.erase(m);
        }

        while (!vv.empty()) {
            auto m = min_element(vv.begin(), vv.end());

            st.insert(*m + (m - vv.begin()) + 1);

            vv.erase(m);
        }

        // for (auto it : s) {
        //     cout << it << " ";
        // }

        // cout << "\n";

        // for (auto it : st) {
        //     cout << it << " ";
        // }

        // cout << "\n";

        while (s.empty() == false && st.empty() == false) {
            if (!s.empty() && !st.empty()) {
                auto it1 = s.begin();
                auto it2 = st.begin();

                ss.insert(max(*it1, *it2));

                s.erase(*it1);
                st.erase(*it2);
            }
            else if (s.empty()) {
                auto it2 = st.begin();

                ss.insert(*it2);

                st.erase(*it2);
            }
            else {
                auto it1 = s.begin();

                ss.insert(*it1);

                s.erase(*it1);
            }
        }

        vector <int> vs;

        //set_union(ss.begin(), ss.end(), st.begin(), st.end(), vs.begin());

        for (auto it : ss) {
            cout << it << " ";
        }

        cout << "\n";

        for (auto it : st) {
            cout << it << " ";
        }

        cout << "\n";

        v.clear();
        vs.clear();
        s.clear();
        st.clear();
        ss.clear();
    }

    return 0;
}