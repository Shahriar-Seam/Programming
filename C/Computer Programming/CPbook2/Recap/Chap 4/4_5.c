#include <stdio.h>

void recurse()
{
    char *s = "Hurray, I am learning recursion!";

    printf("%s\n", s);

    recurse();
}

int main()
{
    recurse();

    return 0;
}