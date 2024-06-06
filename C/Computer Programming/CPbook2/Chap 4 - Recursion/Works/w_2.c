#include <stdio.h>
#include <string.h>

void reverse_string(char str[], int low, int high)
{
    if (low > high) {
        return;
    }

    char temp = str[low];
    str[low] = str[high];
    str[high] = temp;

    reverse_string(str, low + 1, high - 1);
}

int main()
{
    char str[1000];

    scanf(" %[^\n]", str);

    reverse_string(str, 0, strlen(str) - 1);

    puts(str);

    return 0;
}