#include <stdio.h>
int main()
{
    double gpa[8], credit[8], product, sum = 0, sum1 = 0;
    int i, j, k;
    for (i = 0; i < 8; i++)
    {
        //    taking gpa as input
        scanf("%lf", &gpa[i]);
        // taking credit as input
        scanf("%lf", &credit[i]);
    }

    // finding the multiplication of gpa and credit hours
    for (i = 0; i < 8; i++)
    {
        product = gpa[i] * credit[i];
        sum = sum + product;
        sum1 = sum1 + credit[i];
    }

    double cgpa = (sum / sum1);
    printf("%lf", cgpa);
    return 0;
}