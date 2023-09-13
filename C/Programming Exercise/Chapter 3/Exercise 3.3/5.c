#include <stdio.h>
#include <string.h>

int main()
{
    char shoes[3][10] = {"White", "Violate", "Red"};
    char pants[3][10] = {"Black", "Blue", "Brown"};
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%s & %s\n", shoes[i], pants[j]);
        }
    }

    return 0;
}