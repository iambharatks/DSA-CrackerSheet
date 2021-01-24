#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

class Deque
{
    Node *head, *tail;
    int sz;

public:
    Deque() : head(NULL), tail(NULL), sz(0) {}
    bool isEmpty() { return !head; }
    int size() { return sz; }
    int front()
    {
        if (!head)
            return INT_MAX;
        return head->data;
    }
    int back()
    {
        if (!tail)
            return INT_MAX;
        return tail->data;
    }
    void push_front(int data)
    {
        sz++;
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(int data)
    {
        sz++;
        Node *newNode = new Node(data);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (isEmpty())
            cout << "Is Empty\n";
        else
        {
            sz--;
            Node *poppedNode = head;
            head = head->next;
            if (!head)
                tail = NULL;
            else
                head->prev = NULL;
            delete poppedNode;
        }
    }
    void pop_back()
    {
        if (isEmpty())
            cout << "Is Empty\n";
        else
        {
            sz--;
            Node *poppedNode = tail;
            tail = tail->prev;
            if (!tail)
                head = NULL;
            else
                tail->next = NULL;
            delete poppedNode;
        }
    }
    void printDeque()
    {
        if (!head)
            return;
        Node *current = head;
        cout << "Printing queue\n";
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        current = tail;
        cout << "\nPrinting stack\n";
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << '\n';
    }
};
//for stack and queue can easily be implemented uaing stack
int main()
{
    Deque dq;
    cout << "Enter your choice\n"
         << "\t1.push_front\n"
         << "\t2.push_back\n"
         << "\t3.pop_front\n"
         << "\t4.pop_back\n"
         << "\t5.front\n"
         << "\t6.back\n"
         << "\t7.print\n"
         << "\t0.Quite\n";
    int choice, data;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            dq.push_front(data);
            break;
        case 2:
            cin >> data;
            dq.push_back(data);
            break;
        case 3:
            dq.pop_front();
            break;
        case 4:
            dq.pop_back();
            break;
        case 5:
            cout << dq.front() << "\n";
            break;
        case 6:
            cout << dq.back() << "\n";
            break;
        case 7:
            dq.printDeque();
        case 0:
            cout << "Quiting\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice);
    cout << "Thankyou\n";
}