#include <stdio.h>
#include <string.h>
int main()
{
    char pla[101];
    scanf("%s", pla);
    int len = strlen(pla);

    for (int i = 0; i < len - 6; i++)
    {

        if (pla[i] == '1' && pla[i + 1] == '1' && pla[i + 2] == '1' && pla[i + 3] == '1' &&
            pla[i + 4] == '1' && pla[i + 5] == '1' && pla[i + 6] == '1')
        {
            printf("YES\n");
            return 0;
        }
        if (pla[i] == '0' && pla[i + 1] == '0' && pla[i + 2] == '0' && pla[i + 3] == '0' &&
            pla[i + 4] == '0' && pla[i + 5] == '0' && pla[i + 6] == '0')
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}