#include <stdio.h>
#include <stdlib.h>

typedef struct pair pair;
typedef struct node node;
typedef struct stack stack;

struct pair {
    char ch;
    int id;
};

struct node {
    pair p;
    node *next;
};

struct stack {
    node *head;
    int size;
};

pair make_pair(char ch, int id)
{
    pair p;

    p.ch = ch;
    p.id = id;

    return p;
}

node *create_node(pair p, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->p = p;
    new_node->next = next;

    return new_node;
}

void init(stack *st)
{
    st->head = NULL;
    st->size = 0;
}

int is_empty(stack *st)
{
    return st->size == 0;
}

void push(stack *st, pair p)
{
    st->head = create_node(p, st->head);

    st->size = st->size + 1;
}

pair top(stack *st)
{
    return st->head->p;
}

void pop(stack *st)
{
    if (!is_empty(st)) {
        st->head = st->head->next;

        st->size = st->size - 1;
    }
}

void solve()
{
    int n, i, cost = 0;
    stack st;
    pair p;

    init(&st);

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 0; i < n; i++) {
        if (is_empty(&st)) {
            push(&st, make_pair(s[i], i));
        }
        else if (s[i] == ')' && (top(&st).ch == '_' || top(&st).ch == '(')) {
            p = top(&st);
            pop(&st);

            s[p.id] = '(';

            cost += i - p.id;
        }
        else if (s[i] == '_' && (top(&st).ch == '_' || top(&st).ch == '(')) {
            p = top(&st);
            pop(&st);

            s[i] = ')';

            cost += i - p.id;
        }
        else {
            push(&st, make_pair(s[i], i));
        }
    }

    printf("%d\n", cost);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}