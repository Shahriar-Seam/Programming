#include <stdio.h>

int main()
{
    int it_is_friday, cousin_came, computer_ok, play_in_field;
    int i, j, k;

    for (i = 0; i <= 1; i++) {
        for (j = 0; j <= 1; j++) {
            for (k = 0; k <= 1; k++) {
                it_is_friday = i;
                cousin_came = j;
                computer_ok = k;

                play_in_field = it_is_friday && !(cousin_came && computer_ok);

                printf("%d\t%d\t%d\t=>\t%d\n", it_is_friday, cousin_came, computer_ok, play_in_field);
            }
        }
    }

    return 0;
}