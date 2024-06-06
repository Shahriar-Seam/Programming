/**
 *    author:  Anonymous_HF
 *    created: 19/05/2024 00:32:40
**/

#include <stdio.h>
#include <math.h>
// #include "sqrt.c"

int main()
{
    char s[50];
    double a = 0, b = 0, c = 0, m_a = 1, m_b = 1, m_c = 1;
    double d, x1, x2, re, im;
    int i = 0;

    printf("Format the equation in the form ax^2 + bx + c = 0\n");
    gets(s);

    if (s[0] == '-') {
        m_a = -1;

        i++;
    }

    for (i; s[i] != 'x'; i++) {
        a *= 10;
        a += s[i] - '0';
    }

    i += 4;

    if (s[i] == '-') {
        m_b = -1;
    }

    i += 2;

    for (i; s[i] != 'x'; i++) {
        b *= 10;
        b += s[i] - '0';
    }

    i += 2;
    
    if (s[i] == '-') {
        m_c = -1;
    }

    i += 2;

    for (i; s[i] != ' '; i++) {
        c *= 10;
        c += s[i] - '0';
    }

    a *= m_a;
    b *= m_b;
    c *= m_c;

    d = b * b - 4 * a * c;

    if (d < 0) {
        re = (-b) / (2 * a);
        im = sqrt(-d) / (2 * a);

        if (im < 0) {
            im *= -1;
        }

        printf("x1 = %g + %gi\nx2 = %g - %gi\n", re, im, re, im);
    }
    else if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("x1 = %g\nx2 = %g\n", x1, x2);
    }
    else {
        x1 = x2 = (-b) / (2 * a);

        printf("x = %g\n", x1);
    }

    return 0;
}