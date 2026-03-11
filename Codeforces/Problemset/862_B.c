#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} node;

node *create_node(int val)
{
    node *n = (node *) malloc(sizeof(node));

    n->val = val;
    n->next = NULL;

    return n;
}

node *prepend(node *n, int val)
{
    node *new_n = create_node(val);

    new_n->next = n;

    return new_n;
}

int32_t main()
{
    int n, i, j = 0, k = 1, u, v, vis = 0;
    int z = 0, o = 0;

    scanf("%d", &n);

    node *adj_list[n + 1];
    int visited[n + 1], color[n + 1];
    int q[2 * n + 10];

    memset(visited, 0, (n + 1) * sizeof(int));
    memset(color, -1, (n + 1) * sizeof(int));
    memset(q, 0, (2 * n + 10) * sizeof(int));

    for (i = 1; i <= n; i++) {
        adj_list[i] = create_node(i);
    }

    for (i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);

        adj_list[u] = prepend(adj_list[u], v);
        adj_list[v] = prepend(adj_list[v], u);
    }

    q[0] = 1;
    color[1] = 0;

    while (vis < n) {
        u = q[j++];

        visited[u] = 1;
        vis++;

        node *current = adj_list[u];

        while (current != NULL) {
            v = current->val;

            if (!visited[v]) {
                q[k++] = v;

                color[v] = color[u] ^ 1;
            }

            current = current->next;
        }
    }

    for (i = 1; i <= n; i++) {
        z += !color[i];
        o += color[i];
    }

    printf("%lld\n", 1LL * z * o - n + 1);

    return 0;
}