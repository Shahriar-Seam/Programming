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

    bool empty() {
        return head == NULL;
    }

public:
    Deque() {
        head = tail = NULL;
    }

    // Front
    void push_front(int data) {
        if (this->empty()) {
            head = tail = create_node(data, NULL, NULL);
        }
        else {
            head = create_node(data, NULL, head);

            if (head->next != NULL) {
                head->next->prev = head;
            }
        }
    }

    void pop_front() {
        if (this->empty()) {
            cout << "Empty\n";
        }
        else {
            int data = head->data;
            node *old_head = head;

            head = head->next;
            if (!this->empty()) {
                head->prev = NULL;
            }
            else {
                tail = NULL;
            }

            free(old_head);

            cout << data << "\n";
        }
    }

    // Back
    void push_back(int data) {
        if (this->empty()) {
            head = tail = create_node(data, NULL, NULL);
        }
        else {
            tail = create_node(data, tail, NULL);

            if (tail->prev != NULL) {
                tail->prev->next = tail;
            }
        }
    }

    void pop_back() {
        if (this->empty()) {
            cout << "Empty\n";
        }
        else {
            int data = tail->data;
            node *old_tail = tail;

            tail = tail->prev;
            if (!this->empty()) {
                tail->next = NULL;
            }
            else {
                head = NULL;
            }

            free(old_tail);

            cout << data << "\n";
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

// segmentation fault