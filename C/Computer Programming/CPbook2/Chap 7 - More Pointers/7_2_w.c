#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *marks;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    marks = (int *) calloc(n, sizeof(int));

    printf("Enter marks of the students: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    printf("Marks of the students: \n");
    for (i = 0; i < n; i++) {
        printf("%d\n", marks[i]);
    }

    free(marks);

    return 0;
}