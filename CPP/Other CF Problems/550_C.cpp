#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int i, len, n = 0, temp, f = 0;

    cin >> s;

    len = s.size();

    if (count(s.begin(), s.end(), '0') > 0) {
        f = 1;
        n = 0;
    }
    
    else if (count(s.begin(), s.end(), '8') > 0) {
        f = 1;
        n = 8;
    }

    else if (len < 3) {
        temp = stoi(s);

        if (temp % 8 == 0) {
            f = 1;
            n = temp;
        }
    }

    else {
        for (i = len - 1; i >= 0; i--) {
            n = s[i] - '0';

            if (n % 8 == 0) {
                f = 1;
                break;
            }

            if (n % 2 == 0) {
                i--;

                for ( i; i >= 0; i--) {
                    temp = (s[i] - '0') * 10 + n;

                    if (temp % 8 == 0) {
                        f = 1;
                        n = temp;
                        break;
                    }

                    if (temp % 4 == 0) {
                        i--;
                        n = temp;

                        for ( i; i >= 0; i--) {
                            temp = (s[i] - '0') * 100 + n;

                            if (temp % 8 == 0) {
                                n = temp;
                                f = 1;
                                break;
                            }
                        }
                    }

                    if (f) {
                        break;
                    }
                }
            }

            if (f) {
                break;
            }
        }
    }

    f ? cout << "YES\n" << n : cout << "NO\n";

    return 0;
}