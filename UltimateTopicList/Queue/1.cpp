#include <bits/stdc++.h>

using namespace std;

typedef struct node node;

struct node {
    int data;
    node *prev;
    node *next;
};

node *create_node(int data, node *prev, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));

    new_node->data = data;
    new_node->prev = prev;
    new_node->next = next;

    return new_node;
}

class Queue {
private:
    node *head, *tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void Enqueue(int data) {
        if (head == NULL) {
            head = tail = create_node(data, NULL, NULL);
        }
        else {
            tail = create_node(data, tail, NULL);

            tail->prev->next = tail;
        }
    }

    node *Dequeue() {
        if (head == NULL) {
            return NULL;
        }
        else {
            node *old_head = head;

            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }

            return old_head;
        }
    }

    void show() {
        node *current_node = head;

        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x;
    string op;
    Queue q = Queue();

    cin >> t;

    while (t--) {
        cin >> op;

        if (op == "Enqueue") {
            cin >> x;

            q.Enqueue(x);
        }
        else {
            node *top = q.Dequeue();

            if (top == NULL) {
                cout << "Empty\n";
            }
            else {
                cout << top->data << "\n";
            }
        }
    }

    return 0;
}