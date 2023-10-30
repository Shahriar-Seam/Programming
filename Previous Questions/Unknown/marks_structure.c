#include <stdio.h>
#include <string.h>

typedef struct {
    int math;
    int english;
} Marks;

typedef struct {
    char student_name[52];
    char discipline_name[4];
    int student_id;
    Marks marks;
} Student;

int main()
{
    Student student[50];
    int n = 4, i, temp_cse, temp_ece, max_cse = -1, max_ece = -1, max_i_cse, max_i_ece;

    for (i = 0; i < n; i++) {
        printf("Enter name:\n");
        scanf(" %[^\n]", student[i].student_name);
        printf("Enter student id:\n");
        scanf("%d", &student[i].student_id);
        printf("Enter discipline:\n");
        scanf(" %[^\n]", student[i].discipline_name);
        printf("Enter marks in Math:\n");
        scanf("%d", &student[i].marks.math);
        printf("Enter marks in English:\n");
        scanf("%d", &student[i].marks.english);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(student[i].discipline_name, "CSE") == 0) {
            temp_cse = student[i].marks.math + student[i].marks.english;
            max_i_cse = i;
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (strcmp(student[i].discipline_name, "ECE") == 0) {
            temp_ece = student[i].marks.math + student[i].marks.english;
            max_i_ece = i;
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (strcmp(student[i].discipline_name, "CSE") == 0) {
            temp_cse = student[i].marks.math + student[i].marks.english;
            if (temp_cse > max_cse) {
                max_cse = temp_cse;
                max_i_cse = i;
            }
        }
        else if (strcmp(student[i].discipline_name, "ECE") == 0) {
            temp_ece = student[i].marks.math + student[i].marks.english;
            if (temp_ece > max_ece) {
                max_ece = temp_ece;
                max_i_ece = i;
            }
        }
    }

    printf("\n\n");
    printf("Highest Marks:\n");
    printf("Discipline\tID\t\tMarks\n");
    printf("---------------------------------------\n");
    printf("%s\t\t%d\t%d\n", student[max_i_cse].discipline_name, student[max_i_cse].student_id, max_cse);
    printf("%s\t\t%d\t%d\n", student[max_i_ece].discipline_name, student[max_i_ece].student_id, max_ece);

    return 0;
}