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
        head = tail = NULL;
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

    void Dequeue() {
        if (head != NULL) {
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }
        }
    }

    node *Top() {
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, op, n;
    Queue q = Queue();

    cin >> t;

    while (t--) {
        cin >> op;

        if (op == 1) {
            cin >> n;

            q.Enqueue(n);
        }
        else if (op == 2) {
            q.Dequeue();
        }
        else {
            cout << (q.Top() == NULL ? "Empty!" : to_string(q.Top()->data)) << "\n";
        }
    }

    return 0;
}