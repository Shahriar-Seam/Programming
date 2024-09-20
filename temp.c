#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node node;

struct tree_node {
    int nodeid;
    node *left;
    node *right;
};

node *create_node(int nodeid)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->nodeid = nodeid;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_node(int cid, int pid, node *parent)
{
    if (parent == NULL) {
        return;
    }

    if (parent->nodeid == pid) {
        node *new_node = create_node(cid);

        if (parent->left == NULL) {
            parent->left = new_node;
        }
        else if (parent->right == NULL) {
            parent->right = new_node;
        }
        else {
            printf("Wrong case\n");
        }
    }
    else {
        add_node(cid, pid, parent->left);
        add_node(cid, pid, parent->right);
    }
}

void print_tree(node *root)
{
    if (root == NULL) {
        return;
    }

    // Preorder
    printf("%d ", root->nodeid);
    print_tree(root->left);
    print_tree(root->right);

    // // Inorder    
    // print_tree(root->left);
    // printf("%d ", root->nodeid);
    // print_tree(root->right);

    // // Postorder
    // print_tree(root->left);
    // print_tree(root->right);
    // printf("%d ", root->nodeid);    
}

int main()
{
    // freopen ("input.txt", "r", stdin);
    node *root;
    int rnode, cnode, pnode;

    scanf("%d", &rnode);

    root = create_node(rnode);

    while (1) {
        scanf("%d %d", &cnode, &pnode);

        if (cnode == 0 && pnode == 0) {
            break;
        }

        add_node(cnode, pnode, root);
    }

    print_tree(root);

    return 0;
}