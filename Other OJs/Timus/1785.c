#include <stdio.h>

#define p(s) puts((s))

int main()
{
    int n;

    scanf("%d", &n);

    if (n >= 1000) {
        p("legion");
    }
    else if (n >= 500) {
        p("zounds");
    }
    else if (n >= 250) {
        p("swarm");
    }
    else if (n >= 100) {
        p("throng");
    }
    else if (n >= 50) {
        p("horde");
    }
    else if (n >= 20) {
        p("lots");
    }
    else if (n >= 10) {
        p("pack");
    }
    else if (n >= 5) {
        p("several");
    }
    else {
        p("few");
    }

    return 0;
}