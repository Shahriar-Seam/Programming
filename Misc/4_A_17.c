#include <stdio.h>

int main()
{
    int m = 10;

    do
    {
        m += 3;
        printf("%d\n", m);

        if (m < 11) {
            break;
        }
    } while (m <= 25);    

    return 0;
}