#include <stdio.h>

int main()
{
    int n;
    int m, c, m_count = 0, c_count = 0;

    scanf("%d", &n);
 
    while (n--) {
        scanf("%d %d", &m, &c);

        (m > c) ? m_count++ : (m == c) ? : c_count++;
    }

    (m_count > c_count) ? printf("Mishka") : (m_count == c_count) ? printf("Friendship is magic!^^") : printf("Chris");

    return 0;
}