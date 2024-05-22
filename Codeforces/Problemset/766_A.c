#include <stdio.h>
#include <string.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    char s1[100005], s2[100005];

    scanf("%s %s", s1, s2);

    if (strcmp(s1, s2) == 0) {
        puts("-1");
    }
    else {
        printf("%d\n", _max(strlen(s1), strlen(s2)));
    }

    return 0;
}