#include <stdio.h>

int main()
{
    double loan_amount, interest, number_of_years, number_of_months, total_amount, monthly_amount;

    printf("Enter loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Enter interest rate (if 43%% enter 0.43): ");
    scanf("%lf", &interest);
    printf("Enter number of years: ");
    scanf("%lf", &number_of_years);

    total_amount = loan_amount + loan_amount * interest * number_of_years;
    number_of_months = number_of_years * 12;
    monthly_amount = total_amount / number_of_months;

    printf("\nTotal amount to be paid is %.2lf.\nMonthly amount needs to be paid is %.2lf.", total_amount, monthly_amount);

    return 0;
}