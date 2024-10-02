#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct node node;
typedef struct stack stack;
typedef struct node_d node_d;
typedef struct stack_d stack_d;

struct node {
    int data;
    node *next;
};

struct stack {
    node *head;
};

node *create_node(int data, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

bool empty(stack *st) {
    return st->head == NULL;
}

void push(stack *st, int data)
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

int top(stack *st)
{
    return st->head->data;
}

void show(stack *st)
{
    node *current_node = st->head;

    while (current_node != NULL) {
        printf("%c ", current_node->data);

        current_node = current_node->next;
    }

    printf(" ");
}

// Double
struct node_d {
    double data;
    node_d *next;
};

struct stack_d {
    node_d *head;
};

node_d *create_node_d(double data, node_d *next)
{
    node_d *new_node = (node_d *) malloc(sizeof(node_d));

    new_node->data = data;
    new_node->next = next;

    return new_node;
}

bool empty_d(stack_d *st) {
    return st->head == NULL;
}

void push_d(stack_d *st, double data)
{
    st->head = create_node_d(data, st->head);
}

void pop_d(stack_d *st)
{
    if (st->head != NULL) {
        node_d *temp = st->head->next;
        
        free(st->head);

        st->head = temp;
    }
}

double top_d(stack_d *st)
{
    return st->head->data;
}

void show_d(stack_d *st)
{
    node_d *current_node = st->head;

    while (current_node != NULL) {
        printf("%c ", current_node->data);

        current_node = current_node->next;
    }

    printf(" ");
}

int index_of(char *s, char c)
{
    int i, index = -1;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            index = i;

            break;
        }
    }

    return index;
}

char *infix_to_postfix(char *e)
{
    int i, j, n = strlen(e);
    char *s = (char *) malloc(sizeof(char) * 50);
    char digits[] = "0123465789";
    char operators[] = "+-*/";
    char opening[] = "({[";
    char closing[] = ")}]";
    stack st;

    st.head = NULL;

    for (i = 0, j = 0; i < n; i++) {
        char c = e[i];

        if (index_of(digits, c) != -1) {
            while (i < n && index_of(digits, c) != -1) {
                s[j++] = c;

                c = e[++i];
            }

            i--;

            s[j++] = ',';
        }
        else if (index_of(opening, c) != -1) {
            push(&st, c);
        }
        else if (index_of(operators, c) != -1) {
            if (empty(&st)) {
                push(&st, c);
            }
            else if (!empty(&st) && index_of(operators, top(&st)) >= index_of(operators, c)) {
                if (!empty(&st)) {
                    s[j++] = top(&st);
                    pop(&st);

                    while (!empty(&st) && index_of(operators, top(&st)) >= index_of(operators, c)) {
                        s[j++] = top(&st);
                        pop(&st);
                    }
                }

                push(&st, c);
            }
            else {
                push(&st, c);
            }
        }
        else if (index_of(closing, c) != -1) {
            while (!empty(&st) && index_of(opening, top(&st)) != index_of(closing, c)) {
                s[j++] = top(&st);

                pop(&st);
            }

            pop(&st);
        }
    }

    while (!empty(&st)) {
        s[j++] = top(&st);

        pop(&st);
    }

    s[j] = '\0';

    return s;
}

double eval(char *s)
{
    stack_d st;
    int i, n = strlen(s);
    double a, b, num;

    st.head = NULL;

    for (i = 0; i < n; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = 0;

            while (isdigit(c)) {
                num *= 10;

                num += c - '0';

                c = s[++i];
            }

            push_d(&st, num);
        }
        else if (c == '+') {
            a = top_d(&st);
            pop_d(&st);
            b = top_d(&st);
            pop_d(&st);

            push_d(&st, a + b);
        }
        else if (c == '-') {
            a = top_d(&st);
            pop_d(&st);
            b = top_d(&st);
            pop_d(&st);

            push_d(&st, b - a);
        }
        else if (c == '*') {
            a = top_d(&st);
            pop_d(&st);
            b = top_d(&st);
            pop_d(&st);

            push_d(&st, a * b);
        }
        else if (c == '/') {
            a = top_d(&st);
            pop_d(&st);
            b = top_d(&st);
            pop_d(&st);

            push_d(&st, b / a);
        }
    }

    return top_d(&st);
}

int main()
{
    char e[50], p[50];

    gets(e);
    puts(e);

    strcpy(p, infix_to_postfix(e));

    puts(p);

    printf("%g\n", eval(p));

    return 0;
}