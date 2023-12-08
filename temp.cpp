#include <iostream>

// Define a simple singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a value at the head of the linked list
Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a value at the tail of the linked list
Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        return newNode;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node at the specified index
Node* deleteAtIndex(Node* head, int index) {
    if (!head || index < 0) {
        return head;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    int currentIndex = 0;

    while (current->next && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int Q;
    std::cin >> Q;

    Node* head = nullptr;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        std::cin >> X >> V;

        if (X == 0) {
            head = insertAtHead(head, V);
        } else if (X == 1) {
            head = insertAtTail(head, V);
        } else if (X == 2) {
            head = deleteAtIndex(head, V);
        }

        printLinkedList(head);
    }

    // Free the memory allocated for the linked list nodes
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
