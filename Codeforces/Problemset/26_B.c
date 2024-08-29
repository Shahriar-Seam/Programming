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

int main()
{
    char s[1000005];
    int i, count = 0;
    stack st;

    st.head = NULL;

    gets(s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            push(&st, s[i]);
        }
        else if (!empty(&st)) {
            count += 2;

            pop(&st);
        }
    }

    printf("%d\n", count);

    return 0;
}