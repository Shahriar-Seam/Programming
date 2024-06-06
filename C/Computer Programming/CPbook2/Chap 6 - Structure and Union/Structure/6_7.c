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

void calculate_grade(student_type s, int mark)
{
    if (mark >= 80) {
        strcpy(s.grade, "A+");
    }
    else if (mark >= 70) {
        strcpy(s.grade, "A");
    }
    else if (mark >= 60) {
        strcpy(s.grade, "A-");
    }
    else if (mark >= 50) {
        strcpy(s.grade, "B");
    }
    else if (mark >= 40) {
        strcpy(s.grade, "C");
    }
    else {
        strcpy(s.grade, "F");
    }
}

int main()
{
    student_type student[3];
    int i, n = 3;
    int marks[] = {100, 72, 60};

    for (i = 0; i < n; i++) {
        printf("Enter the ID of student %d: ", i + 1);
        scanf("%d", &student[i].id);
        printf("Enter the first name of student %d: ", i + 1);
        scanf("%s", student[i].name.first);
        printf("Enter the last name of student %d: ", i + 1);
        scanf("%s", student[i].name.last);
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        calculate_grade(student[i], marks[i]);
    }

    printf("Output:\n\n");

    for (i = 0; i < n; i++) {
        printf("ID: %d\t", student[i].id);
        printf("Name: %s %s\t", student[i].name.first, student[i].name.last);
        printf("Grade: %s\n", student[i].grade);
    }

    return 0;
}