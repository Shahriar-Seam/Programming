#include <stdio.h>

#define print(c, n) printf("%d %d\n", c, n)
#define move(a, b, c) \
            print(a, b);\
            print(a, c);\
            print(b, c);\

void tower_of_hanoi(int n, int current, int next)
{
    if (n == 1) {
        print(current, next);

        return;
    }
    else if (n == 2) {
        if (current == 1) {
            if (next == 2) {
                move(1, 3, 2);
            }
            else {
                move(1, 2, 3);
            }
        }
        else if (current == 2) {
            if (next == 1) {
                move(2, 3, 1);
            }
            else {
                move(2, 1, 3);
            }
        }
        else {
            if (next == 1) {
                move(3, 2, 1);
            }
            else {
                move(3, 1, 2);
            }
        }

        return;
    }
    else {
        if (current == 1) {
            if (next == 2) {
                tower_of_hanoi(n - 1, current, 3);
                print(current, next);
                tower_of_hanoi(n - 1, 3, next);
            }
            else {
                tower_of_hanoi(n - 1, current, 2);
                print(current, next);
                tower_of_hanoi(n - 1, 2, next);
            }
        }
        else if (current == 2) {
            if (next == 1) {
                tower_of_hanoi(n - 1, current, 3);
                print(current, next);
                tower_of_hanoi(n - 1, 3, next);
            }
            else {
                tower_of_hanoi(n - 1, current, 1);
                print(current, next);
                tower_of_hanoi(n - 1, 1, next);
            }
        }
        else {
            if (next == 1) {
                tower_of_hanoi(n - 1, current, 2);
                print(current, next);
                tower_of_hanoi(n - 1, 2, next);
            }
            else {
                tower_of_hanoi(n - 1, current, 1);
                print(current, next);
                tower_of_hanoi(n - 1, 1, next);
            }
        }
    }
}

int main()
{
    int n, current = 1, next = 3;

    scanf("%d", &n);

    printf("%d\n", (1 << n) - 1);

    tower_of_hanoi(n, current, next);

    return 0;
}