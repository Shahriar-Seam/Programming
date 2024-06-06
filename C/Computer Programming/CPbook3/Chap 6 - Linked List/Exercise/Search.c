#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *search(Node *head, int item)
{
    Node *current_node = head;

    while (current_node != NULL) {
        if (current_node->data == item) {
            return current_node;
        }
        else {
            current_node = current_node->next;
        }
    }

    return current_node;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    int i = 1;

    while (current_node != NULL) {
        printf("Item %d = %d\n", i++, current_node->data);

        current_node = current_node->next;
    }
}

int main()
{
    Node *head, *current_node, *new_node;
    int i;

    head = current_node = NULL;

    for (i = 1; i <= 10; i++) {
        new_node = create_node(i * 10, current_node);

        new_node->next = current_node;
        current_node = new_node;
    }

    head = current_node;

    print_linked_list(head);

    return 0;
}