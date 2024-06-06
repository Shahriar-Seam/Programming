#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, l1, l2;
    char *str1, *str2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &l1, &l2);
        getchar();

        str1 = (char *) malloc(sizeof(char) * l1);
        str2 = (char *) malloc(sizeof(char) * l2);

        gets (str1);
        gets (str2);

        if (l1 == 1 && l2 == 1) {
            yes;
        }
        else {
            if ((strstr(str1, "11") != 0) && (strstr(str2, "0") == 0)) {
                no;
            }
            else if ((strstr(str1, "11") != 0) && ((str2[0] == '1') || (str2[l2 - 1] == '1'))) {
                no;
            }
            else if ((strstr(str1, "00") != 0) && (strstr(str2, "1") == 0)) {
                no;
            }
            else if ((strstr(str1, "00") != 0) && ((str2[0] == '0') || (str2[l2 - 1] == '0'))) {
                no;
            }
            else if (((strstr(str1, "00") != 0) && (strstr(str2, "11") != 0)) || ((strstr(str1, "11") != 0) && (strstr(str2, "00") != 0))) {
                no;
            }
            else if ((strstr(str2, "00") != 0) || (strstr(str2, "11") != 0)) {
                no;
            }
            else {
                yes;
            }
        }
    }

    return 0;
}