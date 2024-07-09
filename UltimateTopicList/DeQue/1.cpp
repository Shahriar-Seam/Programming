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

class Deque {
private:
    node *head, *tail;

public:
    Deque() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int data) {
        if (head == NULL) {
            head = tail = create_node(data, NULL, NULL);
        }
        else {
            tail = create_node(data, tail, NULL);

            tail->prev->next = tail;
        }
    }

    void push_front(int data) {
        if (head == NULL) {
            head = tail = create_node(data, NULL, NULL);
        }
        else {
            head = create_node(data, NULL, head);

            head->next->prev = head;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "Empty\n";
        }
        else {
            node *old_tail;
            if (tail == head) {
                old_tail = tail;

                tail = head = NULL;
            }
            else {
                old_tail = tail;

                tail = tail->prev;

                tail->next = NULL;
            }

            cout << old_tail->data << "\n";

            free(old_tail);
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "Empty\n";
        }
        else {
            node *old_head;

            if (head == tail) {
                old_head = head;

                head = tail = NULL;
            }
            else {
                old_head = head;

                head = head->next;
                head->prev = NULL;
            }

            cout << old_head->data << "\n";

            free(old_head);
        }
    }

    void show() {
        node *current_node = head;

        cout << "h to t:\n";

        while (current_node != NULL) {
            cout << current_node->data << " ";

            current_node = current_node->next;
        }

        cout << "\nt to h:\n";

        current_node = tail;

        while (current_node != NULL) {
            cout << current_node->data << " ";

            current_node = current_node->prev;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Deque dq = Deque();
    int t, x;
    string op;

    cin >> t;

    while (t--) {
        cin >> op;

        if (op == "push_back") {
            cin >> x;

            dq.push_back(x);
        }
        else if (op == "push_front") {
            cin >> x;

            dq.push_front(x);
        }
        else if (op == "pop_back") {
            dq.pop_back();
        }
        else {
            dq.pop_front();
        }
    }

    return 0;
}