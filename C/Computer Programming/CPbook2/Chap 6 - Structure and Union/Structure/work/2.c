#include <stdio.h>
#include <string.h>

typedef struct {
    char first[40];
    char last[40];
} own_name;

typedef struct {
    char father[50];
    char mother[50];
} name_of_parents;

typedef struct {
    int day;
    int mon;
    int year;
} DOB;

typedef struct {
    int id;
    own_name name;
    DOB dob;
    name_of_parents parents;
    char BG[3]; 
} student_type;

void take_input(student_type *student)
{
    printf("First name of the student: ");
    gets(student->name.first);
    printf("Last name of the student: ");
    gets(student->name.last);
    printf("Fathers name: ");
    gets(student->parents.father);
    printf("Mothers name: ");
    gets(student->parents.mother);
    printf("Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &student->dob.day, &student->dob.mon, &student->dob.year);
    printf("ID NO: ");
    scanf("%d", &student->id);
    printf("Blood Group: ");
    scanf("%s", student->BG);
}

void print_output(student_type *std)
{
    printf("-------------------------------------------------\n");
    printf("|\t\tKhulna University\t\t|\n");
    printf("|\t\t    ID Card\t\t\t|\n");
    printf("|-----------------------------------------------|\n");
    printf("|    ---------    Name\t: %s %s\t\t|\n", std->name.first, std->name.last);
    printf("|    |       |    Fathers Name: %s\t|\n", std->parents.father);
    printf("|    | Image |    Mothers Name: %s\t|\n", std->parents.mother);
    printf("|    |       |    Date of Birth: %d/%d/%d\t|\n", std->dob.day, std->dob.mon, std->dob.year);
    printf("|    ---------    ID NO: %d\t\t\t|\n", std->id);
    printf("|                 Blood Group: %s\t\t|\n", std->BG);
    printf("|    Signature\t\t\t\t\t|\n");
    printf("-------------------------------------------------\n");
}

int main()
{
    student_type student;

    take_input(&student);
    print_output(&student);

    return 0;
}