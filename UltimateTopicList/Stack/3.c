#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef struct stack stack;

struct node {
    char data;
    node *next;
};

struct stack {
    node *head;
};

node *create_node(char data, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

bool empty(stack *st) {
    return st->head == NULL;
}

void push(stack *st, char data)
{
    st->head = create_node(data, st->head);
}

void pop(stack *st)
{
    if (st->head != NULL) {
        node *temp = st->head->next;
        
        free(st->head);

        st->head = temp;
    }
}

char top(stack *st)
{
    return st->head->data;
}

void show(stack *st)
{
    node *current_node = st->head;

    while (current_node != NULL) {
        printf("%c\n", current_node->data);

        current_node = current_node->next;
    }

    printf("\n");
}

bool solve()
{
    char s[1005], c;
    stack st;
    int i;

    st.head = NULL;

    scanf(" %s", s);

    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&st, c);
        }
        else {
            if (empty(&st)) {
                return false;
            }

            if ((c == ')' && top(&st) == '(') || (c == '}' && top(&st) == '{') || (c == ']' && top(&st) == '[')) {
                pop(&st);
            }
            else {
                return false;
            }
        }
    }

    return empty(&st) ? true : false;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        puts(solve() ? "YES" : "NO");
    }

    return 0;
}