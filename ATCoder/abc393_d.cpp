#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    int i, j, ops = 1e12;
    int count_1 = 0, count = 0, start = -1, end = -1, mid;
    int max_contiguous = 0;
    int l, r;
    vector <int> mids;

    cin >> n >> s;
    // cin >> s;
    // n = s.size();

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (start == -1) {
                start = i;
            }

            j = i;
            count = 0;
            end = i;

            while (j < n && s[j] == '1') {
                j++;

                count++;
            }

            if (count > max_contiguous) {
                max_contiguous = count;
            }

            i = j - 1;
        }
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            j = i;
            count = 0;

            while (j < n && s[j] == '1') {
                j++;

                count++;
            }

            if (count == max_contiguous) {
                mids.push_back((i + j) / 2);
            }

            i = j - 1;
        }
    }

    auto it = upper_bound(mids.begin(), mids.end(), (end + start) / 2);

    if (it == mids.end()) {
        it--;
    }

    if (it == mids.begin()) {
        mid = *it;
    }
    else {
        r = *it;
        l = *--it;
        mid = (end + start) / 2;

        if (abs(r - mid) > abs(l - mid)) {
            mid = l;
        }
        else {
            mid = r;
        }
    }

    int temp = mid;

    for (j = 0; j < mids.size(); j++) {
        mid = mids[j];

        l = mid;
        r = mid - 1;
        count = 0;

        for (i = l; i < n; i++) {
            if (s[i] == '1') {
                count += i - l;

                l++;
            }
        }

        for (i = r; i >= 0; i--) {
            if (s[i] == '1') {
                count += r - i;

                r--;
            }
        }

        ops = min(ops, count);
    }

    cout << ops << "\n";

    return 0;
}