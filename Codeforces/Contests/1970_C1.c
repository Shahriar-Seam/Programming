#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node node;

struct tree_node {
    int nodeid;
    node *left;
    node *right;
};

int count = 0;
int flag = 0;

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
        if (count % 2 == 1) {
            flag = 1;
        }

        count = 0;

        return;
    }

    // Preorder

    count++;

    // printf("%d ", root->nodeid);
    print_tree(root->left);
    print_tree(root->right);

    // Inorder    
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
    int rnode, cnode, pnode, n, t, i, arr[200005][2];

    scanf("%d %d", &n, &t);

    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    scanf("%d", &rnode);

    root = create_node(rnode);

    for (i = 0; i < n - 1; i++) {
        pnode = arr[i][0];
        cnode = arr[i][1];

        add_node(cnode, pnode, root);
    }

    print_tree(root);

    puts((flag == 1) ? "Ron" : "Hermione");

    return 0;
}