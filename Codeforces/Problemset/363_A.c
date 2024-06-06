#include <stdio.h>
#include <string.h>

int main()
{
    int n, r;

    scanf("%d", &n);

    do {
        r = n % 10;
        n /= 10;

        switch (r)
        {
        case 0:
            puts("O-|-OOOO");
            break;

        case 1:
            puts("O-|O-OOO");
            break;
            
        case 2:
            puts("O-|OO-OO");
            break;

        case 3:
            puts("O-|OOO-O");
            break;

        case 4:
            puts("O-|OOOO-");
            break;
        
        case 5:
            puts("-O|-OOOO");
            break;

        case 6:
            puts("-O|O-OOO");
            break;

        case 7:
            puts("-O|OO-OO");
            break;

        case 8:
            puts("-O|OOO-O");
            break;

        case 9:
            puts("-O|OOOO-");
            break;
        }
    } while (n != 0);

    return 0;
}