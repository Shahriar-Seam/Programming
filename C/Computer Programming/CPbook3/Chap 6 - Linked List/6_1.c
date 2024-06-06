#include "linked_list.h"

int main()
{
    Node *head, *new_node, *current_node;

    new_node = create_node(10, NULL);
    head = new_node;

    head = prepend(head, 20);
    head = append(head, 50);

    print_nodes(head);

    head = remove_node(head, search(head, 20));

    puts("");

    print_nodes(head);

    puts("");

    head = create_list(10, "random");

    int x = 20;

    head = insert_sorted(head, x);

    print_nodes(head);

    return 0;
}