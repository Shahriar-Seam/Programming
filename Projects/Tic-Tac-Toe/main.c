#include <stdio.h>
#include <conio.h>

int main()
{
    char c1 = 49, c2 = 50, c3 = 51, c4 = 52, c5 = 53, c6 = 54, c7 = 55, c8 = 56, c9 = 57;
    int menu, c, i;

    printf("-----------------------------------------------------------------------------\n");
    printf("---------------------------------Tic Tac Toe---------------------------------\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n\n");

    printf("Choose an option:\n");
    printf("1. Play game\n");
    printf("2. Learn about the limitations\n");
    printf("3. About\n\n");

    scanf("%d", &menu);

    if (menu == 2) {
        printf("Players can overwrite.\n");
        printf("Can't determine if the game results in a draw.\n\n");

        printf("To play the game press 1: ");
        scanf("%d", &menu);
    }

    else if (menu == 3) {
        printf("Created by Ibnul Abrar Shahriar Seam.\n");
        printf("I am too lazy to fix it.\n\n");
        
        printf("To play the game press 1: ");
        scanf("%d", &menu);
    }

    if (menu == 1) {
        printf("1st player places X, 2nd player places O.\n");

        printf("---------------------------------------------\n");
        printf("|\t%c\t|\t%c\t|\t%c\t|\n", c1, c2, c3);
        printf("---------------------------------------------\n");
        printf("|\t%c\t|\t%c\t|\t%c\t|\n", c4, c5, c6);
        printf("---------------------------------------------\n");
        printf("|\t%c\t|\t%c\t|\t%c\t|\n", c7, c8, c9);
        printf("---------------------------------------------\n");

        for (i = 0; i < 9; i++) {
            if (i % 2 == 0) {
                printf("\nPlayer 1:");
            }
            else {
                printf("\nPlayer 2:");
            }

            printf("\nEnter cell number: ");
            scanf("%d", &c);

            if (i % 2 == 0) {
                switch (c) {
                case 1:
                    c1 = 'X';
                    break;
                
                case 2:
                    c2 = 'X';
                    break;
                
                case 3:
                    c3 = 'X';
                    break;
                
                case 4:
                    c4 = 'X';
                    break;
                
                case 5:
                    c5 = 'X';
                    break;
                
                case 6:
                    c6 = 'X';
                    break;
                
                case 7:
                    c7 = 'X';
                    break;
                
                case 8:
                    c8 = 'X';
                    break;
                
                case 9:
                    c9 = 'X';
                    break;

                default:
                    printf("Invalid Move. Try again.\n");
                    i--;
                }
            }
            else {
                switch (c) {
                case 1:
                    c1 = 'O';
                    break;
                
                case 2:
                    c2 = 'O';
                    break;
                
                case 3:
                    c3 = 'O';
                    break;
                
                case 4:
                    c4 = 'O';
                    break;
                
                case 5:
                    c5 = 'O';
                    break;
                
                case 6:
                    c6 = 'O';
                    break;
                
                case 7:
                    c7 = 'O';
                    break;
                
                case 8:
                    c8 = 'O';
                    break;
                
                case 9:
                    c9 = 'O';
                    break;

                default:
                    printf("Invalid Move. Try again.\n");
                    i--;
                }
            }

            printf("---------------------------------------------\n");
            printf("|\t%c\t|\t%c\t|\t%c\t|\n", c1, c2, c3);
            printf("---------------------------------------------\n");
            printf("|\t%c\t|\t%c\t|\t%c\t|\n", c4, c5, c6);
            printf("---------------------------------------------\n");
            printf("|\t%c\t|\t%c\t|\t%c\t|\n", c7, c8, c9);
            printf("---------------------------------------------\n");

            if (c1 == c2 && c1 == c3) {
                printf("\n\n%c won\n", c1);
                break;
            }
            else if (c4 == c5 && c4 == c6) {
                printf("\n\n%c won\n", c4);
                break;
            }
            else if (c7 == c8 && c7 == c9) {
                printf("\n\n%c won\n", c7);
                break;
            }
            else if (c1 == c4 && c1 == c7) {
                printf("\n\n%c won\n", c1);
                break;
            }
            else if (c2 == c5 && c2 == c8) {
                printf("\n\n%c won\n", c2);
                break;
            }
            else if (c3 == c6 && c3 == c9) {
                printf("\n\n%c won\n", c3);
                break;
            }
            else if (c1 == c5 && c1 == c9) {
                printf("\n\n%c won\n", c1);
                break;
            }
            else if (c3 == c5 && c3 == c7) {
                printf("\n\n%c won\n", c3);
                break;
            }
        }
    }

    printf("Bye Bye.");


    printf("\nPress any key to exit.\n");
    getch();

    return 0;
}