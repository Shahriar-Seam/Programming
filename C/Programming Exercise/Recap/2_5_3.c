#include <stdio.h>

int main()
{
    int a_year, a_mon, a_day, m_year, m_mon, m_day;

    printf("Enter Aninditas birth date (DD MM YYYY): ");
    scanf("%d %d %d", &a_day, &a_mon, &a_year);
    printf("Enter Malihas birth date (DD MM YYYY): ");
    scanf("%d %d %d", &m_day, &m_mon, &m_year);

    if (a_year > m_year) {
        printf("Maliha is elder.\n");
    }
    else if (a_year < m_year) {
        printf("Anindita is elder.\n");
    }

    else {
        if (a_mon > m_mon) {
            printf("Maliha is elder.\n");
        }
        else if (a_mon < m_mon) {
            printf("Anindita is elder.\n");
        }

        else {
            if (a_day > m_day) {
                printf("Maliha is elder.\n");
            }
            else if (a_day < m_day) {
                printf("Anindita is elder.\n");
            }

            else {
                printf("They both are of same age.\n");
            }
        }
    }

    return 0;
}