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

Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);

    return new_node;
}

Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);
    Node *current_node = head;

    if (current_node == NULL) {
        return new_node;
    }

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    int i = 1;

    while (current_node != NULL) {
        printf("Item % d = %d\n", i++, current_node->data);

        current_node = current_node->next;
    }
}

int main()
{
    Node *head;

    head = create_node(50, NULL);

    head = prepend(head, 20);

    head = append(head, 10);

    print_linked_list(head);

    return 0;
}