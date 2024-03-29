#include <bits/stdc++.h>

using namespace std;

void get_divisors(priority_queue <int, vector <int>, greater <int> > &divisors, int n)
{
    int i;

    while (divisors.empty() == false) {
        divisors.pop();
    }

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push(i);
            divisors.push(n / i);
        }
    }
}

void solve()
{
    int n, k, i, len, cnt, cnt_again;
    string s, new_s, sub;
    priority_queue <int, vector <int>, greater <int> > divisors;

    cin >> n >> s;

    len = s.size();

    get_divisors(divisors, len);

    while (divisors.empty() == false) {
        new_s = "";
        cnt = cnt_again = 0;

        k = divisors.top();
        divisors.pop();

        sub = s.substr(0, k);

        for (i = 0; i < n / k; i++) {
            new_s += sub;
        }

        for (i = 0; i < len; i++) {
            cnt += (s[i] != new_s[i]);
        }


        if (k < n) {
            new_s = "";

            sub = s.substr(k, k);

            for (i = 0; i < n / k; i++) {
                new_s += sub;
            }

            for (i = 0; i < len; i++) {
                cnt_again += (s[i] != new_s[i]);
            }
        }

        if (cnt <= 1 || cnt_again <= 1) {
            cout << k << "\n";
            break;
        }
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