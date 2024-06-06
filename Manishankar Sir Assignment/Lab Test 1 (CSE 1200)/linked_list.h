#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a linked list node
typedef struct node Node;

struct node {
    int data;
    Node *next;
};

// Function to create a new node with the given data and next pointer
Node *create_node(int data, Node *next)
{
    // Allocate memory for the new node
    Node *new_node = (Node *) malloc(sizeof(Node));

    // Check if memory allocation was successful
    if (new_node == NULL) {
        printf("Error! Could not create a new node.\n");
        exit(1);
    }

    // Initialize the new node with the provided data and next pointer
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

// Function to prepend a new node with the given data to the beginning of the list
Node *prepend(Node *head, int data)
{
    // Create a new node with the given data and next pointer pointing to the current head
    Node *new_node = create_node(data, head);

    return new_node;
}

// Function to append a new node with the given data to the end of the list
Node *append(Node *head, int data)
{
    // Create a new node with the given data and next pointer set to NULL
    Node *new_node = create_node(data, NULL);

    // If the list is empty, set the new node as the head and return
    if (head == NULL) {
        return new_node;
    }

    // Traverse the list to find the last node
    Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Attach the new node to the last node's next pointer
    current_node->next = new_node;

    return head;
}

// Function to insert a new node with the given data after the specified node
void insert(Node *node, int data)
{
    // Create a new node with the given data and next pointer pointing to the next node of the specified node
    Node *new_node = create_node(data, node->next);

    // Update the specified node's next pointer to point to the new node
    node->next = new_node;
}

// Function to remove a node from the list
Node *remove_node(Node *head, Node *node)
{
    // If the node to be removed is the head, update the head pointer
    if (node == head) {
        head = node->next;
        free(node);
        return head;
    }

    // Traverse the list to find the node before the node to be removed
    Node *current_node = head;
    while (current_node != NULL) {
        if (current_node->next == node) {
            break;
        }
        current_node = current_node->next;
    }

    // If the node to be removed is not found, return the head unchanged
    if (current_node == NULL) {
        return head;
    }

    // Update the previous node's next pointer to skip the node to be removed
    current_node->next = node->next;

    // Free the memory allocated for the removed node
    free(node);

    return head;
}

// Function to search for a node with the given data in the list
Node *search(Node *head, int data)
{
    Node *current_node = head;

    // Traverse the list to find the node with the given data
    while (current_node != NULL) {
        if (current_node->data == data) {
            return current_node;
        } else {
            current_node = current_node->next;
        }
    }

    return current_node; // Return NULL if the node is not found
}

// Function to insert a new node with the given data into a sorted list
Node *insert_sorted(Node *head, int data)
{
    // If the list is empty or the data is smaller than the head's data, prepend the new node
    if (head == NULL || head->data > data) {
        head = prepend(head, data);
        return head;
    }

    // Traverse the list to find the appropriate position to insert the new node
    Node *current_node = head;
    while (current_node->next != NULL && current_node->next->data < data) {
        current_node = current_node->next;
    }

    // Insert the new node after the current node
    insert(current_node, data);

    return head;
}

// Function to count the number of nodes in the list
int count(Node *head)
{
    int cnt = 0;
    Node *current_node = head;

    // Traverse the list and count the nodes
    while (current_node != NULL) {
        cnt++;
        current_node = current_node->next;
    }

    return cnt;
}

// Function to create a linked list with specified size and data distribution
Node *create_list(int size, char *str)
{
    Node *head, *current_node, *new_node;
    int i;

    current_node = NULL;
    head = NULL;

    // Create a list with linearly increasing data values from 1 to size
    if (strcmp(str, "linear") == 0) {
        for (i = 1; i <= size; i++) {
            new_node = create_node(i, NULL);
            if (i == 1) {
                head = current_node = new_node;
                continue;
            }
            current_node->next = new_node;
            current_node = new_node;
        }
    }
    // Create a list with random data values in the range [0, 100]
    else if (strcmp(str, "random") == 0) {
        for (i = 1; i <= size; i++) {
            new_node = create_node(rand() % 101, NULL);
            if (i == 1) {
                head = current_node = new_node;
                continue;
            }
            current_node->next = new_node;
            current_node = new_node;
        }
    }

    return head;
}

// Function to print the data values of nodes in the list
void print_nodes(Node *head)
{
    int i = 1;
    Node *current_node = head;

    // Traverse the list and print the data values of each node
    while (current_node != NULL) {
        printf("Data %d = %d\n", i, current_node->data);
        current_node = current_node->next;
        i++;
    }
}
