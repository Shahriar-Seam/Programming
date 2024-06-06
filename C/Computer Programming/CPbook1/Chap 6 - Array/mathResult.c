#include <stdio.h>

int main()
{
    int term1, term2, final_marks;
    double total_marks;

    scanf("%d %d %d", &term1, &term2, &final_marks);

    total_marks = term1 * 0.25 + term2 * 0.25 + final_marks * 0.5;

    printf("%.0lf\n", total_marks);

    return 0;
}