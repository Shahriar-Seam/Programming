#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef struct stack stack;
typedef struct pair pair;

struct node {
    char data;
    node *next;
};

struct stack {
    node *head;
    int size;
};

struct pair {
    int value;
    int count;
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

    st->size++;
}

void pop(stack *st)
{
    if (st->head != NULL) {
        node *temp = st->head->next;
        
        free(st->head);

        st->head = temp;

        st->size--;
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

int get_size(stack *st)
{
    return st->size;
}

int main()
{
    char s[1000005], c;
    stack st;
    int i, cnt = 0;
    int count[1000005] = {};
    pair p;

    p.value = 0;
    p.count = 1;

    st.head = NULL;
    st.size = 0;

    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++) {
        c = s[i];
        
        if (c == '(') {
            push(&st, c);

            // printf("%c", c);
        }
        else {
            if (empty(&st)) {
                count[2 * cnt]++;
                cnt = 0;

                printf("\n");
            }
            else {
                printf("%c%c", top(&st), c);
                pop(&st);

                cnt++;
            }
        }
    }

    count[2 * (cnt - get_size(&st))]++;

    for (i = 1000000; i > 0; i -= 2) {
        if (count[i] > 0) {
            p.value = i;
            p.count = count[i];

            break;
        }
    }

    printf("%d %d\n", p.value, p.count);

    return 0;
}

// doesn't work