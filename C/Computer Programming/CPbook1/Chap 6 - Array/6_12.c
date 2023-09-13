#include <stdio.h>

int main()
{
    int term1_marks[40] = {
        83, 86, 97, 95, 93, 95, 86, 52, 49, 41, 42, 47, 90, 59, 63, 86, 40, 46, 92, 56, 51, 48, 67, 49, 42, 90, 42, 83, 47, 95, 69, 82, 82, 58, 69, 67, 53, 56, 71, 62
    };
    int term2_marks[40] = {
        86, 97, 95, 93, 95, 86, 52, 49, 41, 42, 47, 90, 59, 63, 86, 40, 46, 92, 56, 51, 48, 67, 49, 42, 90, 42, 83, 47, 95, 69, 82, 82, 58, 69, 67, 53, 56, 71, 62, 49
    };
    int final_marks[40] = {
        87, 64, 91, 43, 89, 66, 58, 73, 99, 81, 100, 64, 55, 69, 85, 81, 80, 67, 88, 71, 62, 78, 58, 66, 98, 75, 86, 90, 80, 85, 100, 64, 55, 69, 85, 81, 80, 67, 88, 71
    };
    int count, i, marks, stud = 0;
    double total_marks[40];

    for (i = 0; i < 40; i++) {
        total_marks[i] = term1_marks[i] / 4.0 + term2_marks[i] / 4.0 + final_marks[i] / 2.0;
    }

    for (marks = 50; marks <= 100; marks++) {
        count = 0;

        for (i = 0; i < 40; i++) {
            if ((int) total_marks[i] == marks) {
                count++;
            }
        }

        printf("Marks: %d\tCount: %d\n", marks, count);

        stud += count;
    }

    printf("Total Students = %d\n", stud);
    return 0;
}