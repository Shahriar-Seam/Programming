// Graph All Paths

#include <stdio.h>

// Global variables
int graph[100][100] = {};
int indices[100];
int indices_count = 0;
int start_node;
int end_node;

// Functions
int get_index(int node);
int is_present_in_path(int *path, int count, int index);
void print_path(int *path, int count);
void search(int *path, int count);

int main()
{
    int a, b, c;
    int index1, index2;
    int start, end;
    int path[100], count = 0;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        index1 = get_index(a);
        index2 = get_index(b);

        graph[index1][index2] = c;
        graph[index2][index1] = c;
    }

    printf("Enter start: ");
    scanf("%d", &start);
    printf("Enter end: ");
    scanf("%d", &end);

    path[0] = get_index(start);
    count++;
    end_node = get_index(end);

    search(path, count);

    return 0;
}

int get_index(int node)
{
    int i;

    for (i = 0; i < indices_count; i++) {
        if (indices[i] == node) {
            return i;
        }
    }

    indices[indices_count] = node;
    indices_count++;
    return indices_count - 1;
}

int is_present_in_path(int *path, int count, int index)
{
    int i;

    for (i = 0; i < count; i++) {
        if (path[i] == index) {
            return 1;
        }
    }

    return 0;
}

void print_path(int *path, int count)
{
    int i;

    printf("\n");

    for (i = 0; i < count; i++) {
        printf("%d ", indices[path[i]]);
    }
}

void search(int *path, int count)
{
    int current_index = path[count - 1];
    int i;

    for (i = 0; i < indices_count; i++) {
        if (graph[current_index][i] > 0) {
            if (is_present_in_path(path, count, i) == 0) {
                path[count] = i;
                count++;

                if (i == end_node) {
                    print_path(path, count);
                }

                search(path, count);

                count--;
            }
        }
    }
}