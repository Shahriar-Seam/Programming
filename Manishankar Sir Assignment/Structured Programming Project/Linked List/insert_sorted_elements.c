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

Node *insert_sorted(Node *head, int data)
{
    Node *current_node = head, *new_node;

    if (head->data > data) {
        head = create_node(data, head);

        return head;
    }

    while (current_node->next != NULL) {
        if (current_node->next->data > data) {
            new_node = create_node(data, current_node->next);
            current_node->next = new_node;

            return head;
        }

        current_node = current_node->next;
    }

    
    new_node = create_node(data, current_node->next);
    current_node->next = new_node;

    return head;
}

void print_nodes(Node *head)
{
    Node *current_node = head;
    int i = 1;

    while (current_node != NULL) {
        printf("Data %d = %d\n", i++, current_node->data);

        current_node = current_node->next;
    }
}

int main()
{
    Node *head;
    int i, data, size;

    printf("Enter size of the linked list: \n");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        scanf("%d", &data);

        if (i == 0) {
            head = create_node(data, NULL);
        }
        else {
            head = insert_sorted(head, data);
        }
    }

    print_nodes(head);

    return 0;
}