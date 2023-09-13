#include <stdio.h>

int main()
{
    int m_date, m_mon, m_year, a_date, a_mon, a_year, maliha, anindita;

    printf("Enter Malihas birth date (DD MM YYYY): ");
    scanf("%d %d %d", &m_date, &m_mon, &m_year);
    printf("Enter Aninditas birth date (DD MM YYYY): ");
    scanf("%d %d %d", &a_date, &a_mon, &a_year);

    if (m_year < a_year) {
        printf("Maliha is elder.\n");
    }
    else if (m_year > a_year) {
        printf("Anindita is elder.\n");
    }
    else {
        if (m_mon < a_mon) {
            printf("Maliha is elder.\n");
        }
        else if (m_mon > a_mon) {
            printf("Anindita is elder.\n");
        }
        else {
            if (m_date < a_date) {
                printf("Maliha is elder.\n");
            }
            else if (m_date > a_date) {
                printf("Anindita is elder.\n");
            }
            else {
                printf("They are same age.\n");
            }
        }
    }

    return 0;
}