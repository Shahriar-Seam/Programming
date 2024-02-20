#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int d1, d2, m1, m2, y1, y2;

int year(char *s)
{
    char temp[5];

    temp[0] = s[6];
    temp[1] = s[7];
    temp[2] = s[8];
    temp[3] = s[9];
    temp[4] = '\0';

    return atoi(temp);
}

int month(char *s)
{
    char temp[3];

    temp[0] = s[3];
    temp[1] = s[4];
    temp[2] = '\0';

    return atoi(temp);
}

int day(char *s)
{
    char temp[3];

    temp[0] = s[0];
    temp[1] = s[1];
    temp[2] = '\0';

    return atoi(temp);
}

bool valid_date(int d, int m, int y)
{
    if (m == 1 && d > 31) {
        return false;
    }
    else if (m == 2) {
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) {
            if (d > 29) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            if (d > 28) {
                return false;
            }
            else {
                return true;
            }
        }
    }
    else if (m == 3 && d > 31) {
        return false;
    }
    else if (m == 4 && d > 30) {
        return false;
    }
    else if (m == 5 && d > 31) {
        return false;
    }
    else if (m == 6 && d > 30) {
        return false;
    }
    else if (m == 7 && d > 31) {
        return false;
    }
    else if (m == 8 && d > 31) {
        return false;
    }
    else if (m == 9 && d > 30) {
        return false;
    }
    else if (m == 10 && d > 31) {
        return false;
    }
    else if (m == 11 && d > 30) {
        return false;
    }
    else if (m == 12 && d > 31) {
        return false;
    }
    else {
        return true;
    }
}

bool is_valid(int n, int flag)
{
    int rev_num = 0, temp = n, size = 0;

    while (temp > 0) {
        rev_num *= 10;
        rev_num += temp % 10;
        temp /= 10;

        size++;
    }

    if (size != 4) {
        return false;
    }
    else {
        int m_n = rev_num % 100;
        int d_n = rev_num / 100;

        if (!valid_date(d_n, m_n, n)) {
            return false;
        }
        else if (flag == 0) {
            return true;
        }

        else if (m_n > m1 && m_n < m2) {
            return true;
        }
        else if (m_n == m1) {
            if (d_n >= d1) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (m_n == m2) {
            if (d_n <= d2) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}

int main()
{
    char date1[] = "01-01-2002", date2[] = "31-12-2050";
    int cnt = 0;

    y1 = year(date1);
    y2 = year(date2);
    m1 = month(date1);
    m2 = month(date2);
    d1 = day(date1);
    d2 = day(date2);

    int i;

    for (i = y1; i <= y2; i++) {
        if (i > y1 && i < y2) {
            if (is_valid(i, 0)) {
                cnt++;
            }
        }
        else {
            if (is_valid(i, 1)) {
                cnt++;
            }
        }
    }

    printf("%d", cnt);
}