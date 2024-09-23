#include <stdio.h>
#include <stdlib.h>

// Definition of the TreeNode structure
typedef struct TreeNode {
    int id;                  // Unique identifier for the node
    struct TreeNode *left;   // Pointer to the left child node
    struct TreeNode *right;  // Pointer to the right child node
} TreeNode;

// Function to create a new tree node
// Parameters:
// - id: The unique identifier for the new node
// Returns: A pointer to the newly created TreeNode
TreeNode *create_tree_node(int id) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode)); // Allocate memory for a new node
    
    if (newNode == NULL) { // Check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit if allocation failed
    }

    newNode->id = id; // Set the node's ID
    newNode->left = NULL; // Initialize left child as NULL
    newNode->right = NULL; // Initialize right child as NULL

    return newNode; // Return the pointer to the new node
}

// Function to add a node to the tree
// Parameters:
// - childId: The ID of the child node to be added
// - parentId: The ID of the parent node to which the child will be added
// - parentNode: Pointer to the current parent node in the tree
void add_tree_node(int childId, int parentId, TreeNode *parentNode) {
    if (parentNode == NULL) { // Base case: if the parent node is NULL, return
        return;
    }

    // If the current parent node's ID matches the specified parent ID
    if (parentNode->id == parentId) {
        TreeNode *newNode = create_tree_node(childId); // Create the new child node

        // Add the new node as a left or right child
        if (parentNode->left == NULL) {
            parentNode->left = newNode; // Add as left child
        }
        else if (parentNode->right == NULL) {
            parentNode->right = newNode; // Add as right child
        }
        else {
            printf("Error: Parent node already has two children\n"); // Error if both children are occupied

            return;
        }
    }
    else {
        // Recursively attempt to add the new node to the left and right subtrees
        add_tree_node(childId, parentId, parentNode->left);
        add_tree_node(childId, parentId, parentNode->right);
    }
}

// Function to print the tree in preorder traversal
// Parameters:
// - rootNode: Pointer to the root node of the tree to be printed
void print_tree_preorder(TreeNode *rootNode) {
    if (rootNode == NULL) { // Base case: if the root node is NULL, return
        return;
    }

    // Preorder traversal: print the root node, then recurse on left and right children
    printf("%d ", rootNode->id);
    print_tree_preorder(rootNode->left);
    print_tree_preorder(rootNode->right);
}

int main() {
    // Uncomment the following line to read input from a file
    // freopen("input.txt", "r", stdin);

    TreeNode *rootNode; // Pointer to the root of the tree
    int rootId, childId, parentId; // IDs for root, child, and parent nodes

    // Read the ID of the root node from standard input
    scanf("%d", &rootId);
    rootNode = create_tree_node(rootId); // Create the root node

    // Read child-parent pairs until "0 0" is input
    while (1) {
        scanf("%d %d", &childId, &parentId);
        
        if (childId == 0 && parentId == 0) { // Break the loop if "0 0" is input
            break;
        }

        add_tree_node(childId, parentId, rootNode); // Add the child node to the tree
    }

    // Print the tree structure using preorder traversal
    print_tree_preorder(rootNode);
    printf("\n");

    return 0; // Indicate that the program ended successfully
}
