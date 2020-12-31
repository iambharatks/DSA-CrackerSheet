#include <bits/stdc++.h>

using namespace std;

//138. Check If Circular Linked List
//139. Split cll in two clls
//141. Deletion in cll 

class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *next = NULL) : data(data), next(next) {}
};

class CircularLinkedList
{
    Node *head, *tail;

public:
    CircularLinkedList(Node *head = NULL, Node *tail = NULL) : head(head), tail(tail) {}

    void push_back(int data)
    {
        Node *newNode = new Node(data, head);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            tail->next = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void print()
    {
        Node *current = head;
        if (!head)
        {
            cout << "Empty List\n";
            return;
        }
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << "\n";
    }

    bool isCircular() { return (head) && (tail->next == head); }

    void splitInTwo(CircularLinkedList &cll1, CircularLinkedList &cll2)
    {
        Node *middle = head, *fast = head, *current = head;
        Node *first, *second;
        Node *prev;
        do
        {
            middle = middle->next;
            fast = fast->next->next;

        } while (middle != head && fast != head && fast->next != head);

        while (current != middle)
        {
            first = new Node(current->data);
            if (cll1.head == NULL)
                cll1.head = first;
            else
                prev->next = first;
            prev = first;
            current = current->next;
        }
        if (fast->next == head)
        {
            first = new Node(current->data);
            prev->next = first;
            current = current->next;
        }
        cll1.tail = first;
        cll1.tail->next = cll1.head;
        while (current != head)
        {
            second = new Node(current->data);
            if (cll2.head == NULL)
                cll2.head = second;
            else
                prev->next = second;
            prev = second;
            current = current->next;
        }
        cll2.tail = second;
        cll2.tail->next = cll2.head;
    }

    void pop_back()
    {
        if (!head)
        {
            cout << "Cannot delete from empty list\n";
            return;
        }
        Node *current = head, *prev = NULL;
        while (current->next !=  head)
        {
            prev = current;
            current = current->next;
        }
        if (prev == NULL)
            head = tail = NULL;
        else
        {
            tail = prev;
            tail->next = head;
        }
        free(current);
    }
    void pop_front()
    {
        if (!head)
        {
            cout << "Cannot delete from empty list\n";
            return;
        }
        Node *current = head;
        if (current->next == head)
        {
            head = tail = NULL;
        }
        else
        {
            head = current->next;
            tail->next = head;
        }
        free(current);
    }
    void pop(int position = 1)
    {
        if (position <= 0)
            return;
        Node *prev = NULL, *current = head;
        if (position == 1)
        {
            if (current->next == head)
                head = tail = NULL;
            else
            {
                head = head->next;
                tail->next = head;
            }
            free(current);
            return;
        }

        while (--position && current->next != head)
        {
            prev = current;
            current = current->next;
        }
        if (position > 0)
        {
            return;
        }
        else if (position == 0)
        {
            prev->next = current->next;
            if (current->next == head)
                tail = prev;
            free(current);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    CircularLinkedList cll, cll1, cll2;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        cll.push_back(data);
    }
    cll.print();
    cll.splitInTwo(cll1, cll2);
    cll1.print();
    cll2.print();
    cll1.pop();
    cll1.print();
}