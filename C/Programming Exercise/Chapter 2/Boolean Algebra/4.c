#include <stdio.h>

int main()
{
    int friday, cousin, computer, play_in_field;

    // Case 1 -> 0 0 0
    friday = 0, cousin = 0, computer = 0;
    play_in_field = friday && !(cousin && computer);
    printf("0 0 0 => %d\n", play_in_field);

    // Case 1 -> 0 0 1
    friday = 0, cousin = 0, computer = 1;
    play_in_field = friday && !(cousin && computer);
    printf("0 0 1 => %d\n", play_in_field);

    // Case 1 -> 0 1 0
    friday = 0, cousin = 1, computer = 0;
    play_in_field = friday && !(cousin && computer);
    printf("0 1 0 => %d\n", play_in_field);

    // Case 1 -> 0 1 1
    friday = 0, cousin = 1, computer = 1;
    play_in_field = friday && !(cousin && computer);
    printf("0 1 1 => %d\n", play_in_field);

    // Case 1 -> 1 0 0
    friday = 1, cousin = 0, computer = 0;
    play_in_field = friday && !(cousin && computer);
    printf("1 0 0 => %d\n", play_in_field);

    // Case 1 -> 1 0 1
    friday = 1, cousin = 0, computer = 1;
    play_in_field = friday && !(cousin && computer);
    printf("1 0 1 => %d\n", play_in_field);

    // Case 1 -> 1 1 0
    friday = 1, cousin = 1, computer = 0;
    play_in_field = friday && !(cousin && computer);
    printf("1 1 0 => %d\n", play_in_field);

    // Case 1 -> 1 1 1
    friday = 1, cousin = 1, computer = 1;
    play_in_field = friday && !(cousin && computer);
    printf("1 1 1 => %d\n", play_in_field);

    return 0;
}