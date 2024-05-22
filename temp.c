#include <stdio.h>
#include <time.h>

int main()
{
    time_t start = time(NULL);
    int s = 0, i;

    // Main program

    for (i = 0; i < 1000000000; i++) {
        s += i;
    }

    time_t end = time(NULL);

    printf("%0.4f\n", difftime(end, start));

    return 0;
}