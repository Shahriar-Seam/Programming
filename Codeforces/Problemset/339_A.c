#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
void sort(char str[], int n)
{
    int i, j, temp;
    bool swapped;
 
    for (i = 0; i < n - 1; i++) {
        swapped = false;
 
        if (str[i] != '+') {
            for (j = 0; j < n - i - 2; j++) {
                if (str[j] > str[j + 2]) {
                    temp = str[j];
                    str[j] = str[j + 2];
                    str[j + 2] = temp;
    
                    swapped = true;
                }
            }
    
            if (swapped == false) {
                break;
            }
        }
    }
}

int main()
{
    char str[102];

    scanf("%s", str);

    int len = strlen(str);

    sort(str, len);

    puts(str);

    return 0;
}