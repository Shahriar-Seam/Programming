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

    if (new_node == NULL) {
        printf("Error! Could not create a new node.\n");
        exit(1);
    }

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

    if (head == NULL) {
        return new_node;
    }

    Node *current_node = head;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    return head;
}

void print_nodes(Node *head)
{
    int i = 1;
    Node *current_node = head;

    while (current_node != NULL) {
        printf("Data %d = %d\n", i, current_node->data);
        
        current_node = current_node->next;

        i++;
    }
}

int main()
{
    Node *head, *n1, *n2, *n3;

    n1 = create_node(10, NULL);
    head = n1;

    head = prepend(head, 20);
    head = append(head, 50);

    print_nodes(head);

    return 0;
}