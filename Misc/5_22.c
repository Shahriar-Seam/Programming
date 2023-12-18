#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Employee {
    char employee_name[100];
    int employee_id;
    char company_name[100];
    int salary;
};

void PrintEmployee(struct Employee e)
{
    printf("Name: %s\n", e.employee_name);
    printf("%d\n", e.employee_id);
    printf("Company Name: %s\n", e.company_name);
    printf("%d\n", e.salary);
}

int main()
{
    struct Employee employees[1000];
    int i, max_salary = INT_MIN;
    char temp[10];

    for (i = 0; i < 2; i++) {
        gets(employees[i].employee_name);
        gets(temp);
        employees[i].employee_id = atoi(temp);
        gets(employees[i].company_name);
        gets(temp);
        employees[i].salary = atoi(temp);

        if (employees[i].salary > max_salary) {
            max_salary = employees[i].salary;
        } 
    }

    printf("Highest salary = %d\n", max_salary);

    PrintEmployee(employees[0]);

    return 0;
}