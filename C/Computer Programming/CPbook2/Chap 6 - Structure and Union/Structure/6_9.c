#include <stdio.h>
#include <string.h>

typedef struct {
    char first[40];
    char last[40];
} nametype;

typedef struct {
    int id;
    nametype name;
    char grade[3];
} student_type;

void calculate_grade(student_type *s, int mark)
{
    if (mark >= 80) strcpy(s->grade, "A+");
    else if (mark >= 70) strcpy(s->grade, "A");
    else if (mark >= 60) strcpy(s->grade, "A-");
    else if (mark >= 50) strcpy(s->grade, "B");
    else if (mark >= 40) strcpy(s->grade, "C");
    else strcpy(s->grade, "F");
}

int main()
{
    student_type student[5];
    int i, n = 3;
    int marks[] = {100, 82, 72, 20, 50};

    for (i = 0; i < n; i++) {
        printf("Enter the ID of the student %d: ", i + 1);
        scanf("%d", &student[i].id);
        getchar();
        printf("Enter the first name of the student %d: ", i + 1);
        gets(student[i].name.first);
        printf("Enter the last name of the student %d: ", i + 1);
        gets(student[i].name.last);
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        calculate_grade(&student[i], marks[i]);
    }

    printf("Output:\n\n");
    printf("ID\tName\t\t\t\tGrade\n");

    for (i = 0; i < n; i++) {
        printf("%d\t", student[i].id);
        printf("%s %s\t", student[i].name.first, student[i].name.last);
        printf("%s\n", student[i].grade);
    }

    return 0;
}