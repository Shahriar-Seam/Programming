#include <bits/stdc++.h>

using namespace std;

typedef struct node node;

struct node {
    pair <string, int> data;
    node *prev;
    node *next;
};

node *create_node(pair <string, int> data, node *prev, node *next)
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

    void Enqueue(pair <string, int> data) {
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

    pair <string, int> Top() {
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    Queue qq = Queue();
    string name;
    int time, total_time = 0;
    pair <string, int> p;

    cin >> n >> q;

    while (n--) {
        cin >> name >> time;

        qq.Enqueue({name, time});
    }

    while (!qq.empty()) {
        p = qq.Top();

        if (p.second <= q) {
            total_time += p.second;

            cout << p.first << " " << total_time << "\n";

            qq.Dequeue();
        }
        else {
            total_time += q;
            p.second -= q;

            qq.Dequeue();
            qq.Enqueue(p);
        }
    }

    return 0;
}