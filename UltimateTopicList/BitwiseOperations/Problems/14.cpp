#include <bits/stdc++.h>

using namespace std;

set <long long> s;

void find_all()
{
    long long len, mask, i, num, seven, four;

    for (len = 1; len <= 10; len++) {
        for (mask = 0; mask < (1 << len); mask++) {
            num = 0;
            seven = 0;
            four = 0;

            for (i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    num *= 10;
                    num += 7;
                    seven++;
                }
                else {
                    num *= 10;
                    num += 4;
                    four++;
                }
            }

            if (seven == four) {
                s.insert(num);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    find_all();

    long long n;

    cin >> n;

    cout << *lower_bound(begin(s), end(s), n);

    return 0;
}