#include <stdio.h>
#include <ctype.h>

#define true printf("TRUE\n")
#define false printf("FALSE\n")

int main()
{
    char ch;
    int a, b, c, d, e, f;

    ch = getchar();

    a = isalnum(ch);
    b = isdigit(ch);
    c = isprint(ch);
    d = isalpha(ch);
    e = isupper(ch);

    if (a != 0) {
        true;
    }
    else {
        false;
    }
    
    if (b != 0) {
        true;
    }
    else {
        false;
    }

    if (c != 0) {
        true;
    }
    else {
        false;
    }

    if (d != 0) {
        true;
    }
    else {
        false;
    }

    if (e != 0) {
        true;
    }
    else {
        false;
    }

    return 0;
}