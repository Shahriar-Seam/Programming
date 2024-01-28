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

int count(Node *head)
{
    Node *current_node = head;
    int cnt = 0;

    while (current_node != NULL) {
        cnt++;

        current_node = current_node->next;
    }

    return cnt;
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

    head = current_node = create_node(0, NULL);

    for (i = 1; i <= 5; i++) {
        new_node = create_node(i * 10, NULL);

        current_node->next = new_node;
        current_node = new_node;
    }

    print_linked_list(head);

    printf("Total nodes = %d\n", count(head));

    return 0;
}