#include <bits/stdc++.h>

using namespace std;

typedef struct node node;

struct node {
    int data;
    node *next;
};

class Stack {
private:
    node *head;

    node *create_node(int data, node *next) {
        node *new_node = (node *) malloc(sizeof(node));

        new_node->data = data;
        new_node->next = next;

        return new_node;
    }

public:
    Stack() {
        head = NULL;
    }

    void push(int data) {
        head = create_node(data, head);
    }

    node *pop() {
        if (head == NULL) {
            return NULL;
        }
        else {
            node *top_node = head;

            head = head->next;

            return top_node;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x;
    string op;
    Stack s = Stack();

    cin >> t;

    while (t--) {
        cin >> op;

        if (op == "push") {
            cin >> x;

            s.push(x);
        }
        else {
            node *top_node = s.pop();

            if (top_node == NULL) {
                cout << "Empty\n";
            }
            else {
                cout << top_node->data << "\n";
            }
        }
    }

    return 0;
}