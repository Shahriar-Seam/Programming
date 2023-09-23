#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr[5], num[5];
    int i, j, n;

    for (i = 0; i < 5; i++) {
        printf("Enter the number of students in class %d: ", i + 1);
        scanf("%d", &n);

        num[i] = n;
        arr[i] = (int *) malloc (sizeof(int) * n);

        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (j = 0; j < n; j++) {
            printf("Enter marks for student %d: ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Output:\n");

    for (i = 0; i < 5; i++) {
        printf("Class %d : ", i + 1);

        for (j = 0; j < num[i]; j++) {
            printf("%4d", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}