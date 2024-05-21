#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve()
{
    int l, i, n = 0, e = 0, tn = 0, te = 0, rn, re;

    scanf("%d", &l);

    char s[l + 1];

    scanf(" %s", s);

    for (i = 0; i < l; i++) {
        if (s[i] == 'N') {
            n++;

            tn++;
        }
        else if (s[i] == 'S') {
            n--;
        }
        else if (s[i] == 'E') {
            e++;

            te++;
        }
        else if (s[i] == 'W') {
            e--;
        }
    }

    if ((abs(n) % 2 == 1) || (abs(e) % 2 == 1)) {
        puts("NO");
    }
    else if (strlen(s) == 2 && (n == 0 && e == 0)) {
        puts("NO");
    }
    else {
        rn = ceil(n / 2.0);
        re = ceil(e / 2.0);

        if (rn != 0) {
            int temp = 0;

            for (i = 0; i < l; i++) {
                if (s[i] == 'N' && temp != rn) {
                    s[i] = 'R';
                    temp++;
                }
                else if (s[i] == 'S' && temp != rn) {
                    s[i] = 'R';
                    temp--;
                }
            }
            for (i = 0; i < l; i++) {
                if (s[i] == 'N' || s[i] == 'S') {
                    s[i] = 'H';
                }
            }
        }
        else {
            int temp_n = ceil(tn / 2.0);
            int temp_s = ceil(tn / 2.0);

            for (i = 0; i < l; i++) {
                if (temp_n > 0 && s[i] == 'N') {
                    s[i] = 'R';

                    temp_n--;
                }
                else if (temp_s > 0 && s[i] == 'S') {
                    s[i] = 'R';

                    temp_s--;
                }

                if (temp_n == 0 && temp_s == 0) {
                    break;
                }
            }

            for (i = 0; i < l; i++) {
                if (s[i] == 'N' || s[i] == 'S') {
                    s[i] = 'H';
                }
            }
        }

        if (re != 0) {
            int temp = 0;

            for (i = 0; i < l; i++) {
                if (s[i] == 'E' && temp != re) {
                    s[i] = 'R';
                    temp++;
                }
                else if (s[i] == 'W' && temp != re) {
                    s[i] = 'R';
                    temp--;
                }
            }
            for (i = 0; i < l; i++) {
                if (s[i] == 'E' || s[i] == 'W') {
                    s[i] = 'H';
                }
            }
        }
        else if (re == 0) {
            int temp_e = te / 2;
            int temp_w = te / 2;

            for (i = 0; i < l; i++) {
                if (temp_e > 0 && s[i] == 'E') {
                    s[i] = 'R';

                    temp_e--;
                }
                else if (temp_w > 0 && s[i] == 'W') {
                    s[i] = 'R';

                    temp_w--;
                }

                if (temp_e == 0 && temp_w == 0) {
                    break;
                }
            }

            for (i = 0; i < l; i++) {
                if (s[i] == 'E' || s[i] == 'W') {
                    s[i] = 'H';
                }
            }
        }

        puts(s);
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}