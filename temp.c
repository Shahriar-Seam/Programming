#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

Node *create_node(int data, Node *next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

int main()
{
    Node *head, *current_node, *new_node;
    int data, i, n;

    printf("Enter number of nodes\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data);

        new_node = create_node(data, NULL);

        if (i == 0) {
            head = new_node;
            current_node = new_node;
        }
        else {
            current_node->next = new_node;

            current_node = current_node->next;
        }
    }

    current_node = head;

    while (current_node != NULL) {
        printf("%d\n", current_node->data);

        current_node = current_node->next;
    }

    return 0;
}