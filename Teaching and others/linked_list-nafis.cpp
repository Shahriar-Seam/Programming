#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int value)
    {
        val = value;
        next = NULL;
    }
};
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void delete_at_pos(Node *&head, Node *&tail, int idx)
{
    if (head == NULL)
        return;

    if (idx == 0)
    {
        Node *temp = head;
        head = head->next;

        // when there is only 1 node in the list then head = tail
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        if (temp == NULL || temp->next == NULL)
            return;
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    Node *deletenode = temp->next;

    // if the node that is going to be deleted is the tail then tail needs to be updated
    // tail becomes the previous node of the tail :D
    if (temp->next == tail) {
        tail = temp;
    }

    temp->next = temp->next->next;

    delete deletenode;
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        if (X == 0)
        {
            insert_at_head(head, tail, V);
        }
        else if (X == 1)
        {
            insert_at_tail(head, tail, V);
        }
        else if (X == 2)
        {
            delete_at_pos(head, tail, V);
        }
        print_linked_list(head);
    }
    return 0;
}