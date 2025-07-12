#include <bits/stdc++.h>

using namespace std;

#define int long long

bool is_palindrome(string s)
{
    int i, n = s.size();

    for (i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }

    return true;
}

string convert(int n, int a)
{
    string num = "";

    while (n > 0) {
        num += n % a + '0';

        n /= a;
    }

    reverse(num.begin(), num.end());

    return num;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, n, sum = 0, i, j;

    cin >> a >> n;

    for (i = 1; i <= n; i++) {
        string s = to_string(i);
        string num = s;

        reverse(s.begin(), s.end());

        num += s;

        if (stoll(num) <= n) {
            if (is_palindrome(num) && is_palindrome(convert(stoll(num), a))) {
                sum += stoll(num);
            }
        }
        else {
            break;
        }
    }

    for (i = 1; i <= min(9LL, n); i++) {
        string num = to_string(i);

        if (is_palindrome(num) && is_palindrome(convert(stoll(num), a))) {
            sum += stoll(num);
        }
    }

    for (i = 1; i <= min((long long) 1e6 + 5, n); i++) {
        for (j = 0; j <= 9; j++) {
            string s = to_string(i);
            string num = s;

            reverse(s.begin(), s.end());

            num += to_string(j) + s;

            if (stoll(num) <= n) {
                if (is_palindrome(num) && is_palindrome(convert(stoll(num), a))) {
                    sum += stoll(num);
                }
            }
            else {
                break;
            }
        }
    }

    cout << sum << "\n";

    return 0;
}