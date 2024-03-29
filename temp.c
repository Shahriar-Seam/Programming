#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the end of the linked list
void insert(Node** head, int data) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Set data for the new node
    newNode->data = data;
    // Set the next pointer of the new node to NULL as it will be the last node
    newNode->next = NULL;

    // If the linked list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    } 
    // If the linked list is not empty, traverse to the end and insert the new node
    else {
        // Temporary pointer to traverse the list
        Node* temp = *head;
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Recursive function to print the linked list
void printListRecursive(Node* head) {
    // Base case: if the head is NULL, we've reached the end of the list
    if (head == NULL) {
        printf("\n");
        return;
    }
    // Print the data of the current node
    printf("%d ", head->data);
    // Recursively call the function for the next node
    printListRecursive(head->next);
}

// Function to create a linked list with given elements
Node* createList(int posCount, int negCount, int pos[], int neg[]) {
    // Initialize the head pointer to NULL
    Node* head = NULL;
    // Initialize indices for positive and negative arrays
    int posIndex = 0, negIndex = 0;

    // Iterate through both positive and negative arrays alternately
    while (posIndex < posCount && negIndex < negCount) {
        // Insert positive integer
        insert(&head, pos[posIndex++]);
        // Insert negative integer
        insert(&head, neg[negIndex++]);
    }

    // If there are remaining elements in positive array, add them to the list
    while (posIndex < posCount) {
        insert(&head, pos[posIndex++]);
    }

    // If there are remaining elements in negative array, add them to the list
    while (negIndex < negCount) {
        insert(&head, neg[negIndex++]);
    }

    return head;
}

int main() {
    int n;
    // Input the total number of elements
    scanf("%d", &n);

    // Initialize arrays to store positive and negative integers
    int pos[n], neg[n];
    // Initialize counters for positive and negative integers
    int posCount = 0, negCount = 0;

    // Input the elements and categorize them as positive or negative
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num >= 0)
            pos[posCount++] = num;
        else
            neg[negCount++] = num;
    }

    // Create the linked list with alternating positive and negative integers
    Node* head = createList(posCount, negCount, pos, neg);

    // Print the final linked list using recursion
    printListRecursive(head);

    return 0;
}