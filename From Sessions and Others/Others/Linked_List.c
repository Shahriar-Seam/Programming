#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

Node *create_node (int data, Node *next) {
    Node *new_node = (Node *) malloc (sizeof(Node));

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

bool is_prime(int n)
{
    int i, r = sqrt(n);

    if (n == 2) {
        return true;
    }

    if ((n < 2) || (n % 2 == 0)) {
        return false;
    }

    for (i = 3; i <= r; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

void print_list(Node *head)
{
    Node *current_node = head;

    while (current_node != NULL) {
        if (is_prime(current_node->data)) {
            printf("Data = %d\n", current_node->data);
        }

        current_node = current_node->next;
    }
}

int main()
{
    Node *head, *current_node;
    int i, t, data;

    printf("Number of nodes: \n");
    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &data);

        if (i == 0) {
            head = create_node(data, NULL);
            current_node = head;
        }
        else {
            current_node->next = create_node(data, NULL);
            current_node = current_node->next;
        }
    }

    print_list(head);

    return 0;
}