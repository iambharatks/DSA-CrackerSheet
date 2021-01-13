#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int data, Node *prev = NULL, Node *next = NULL) : data(data), prev(prev), next(next) {}
};

class Stack
{
    Node *node;
    Node *middle;
    int size;

public:
    Stack() : node(NULL), middle(NULL), size(0) {}

    void push(int data)
    {
        Node *newNode = new Node(data);
        size++;
        if (!node)
        {
            node = newNode;
            middle = node;
            return;
        }
        node->prev = newNode;
        newNode->next = node;
        node = newNode;
        if (size & 1)
            middle = middle->prev;
    }
    void pop()
    {
        if (!node)
            return;
        size--;
        Node *tmp = node;
        node = node->next;
        if (node)
            node->prev = NULL;
        if ((size & 1) == 0)
            middle = middle->next;
        free(tmp);
    }
    int middleElement()
    {
        if (!middle)
            return INT_MIN;
        return middle->data;
    }
    int top()
    {
        if (!node)
            return INT_MIN;
        return node->data;
    }
    bool isEmpty() { return (node == NULL); }
    void print()
    {
        Node *current = node;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    int choice = 1, data;
    Stack s;
    while (choice)
    {
        cout << "Enter choice\n1.Push\n2.Pop\n3.Display\n4.Top of stack\n5.Middle of stack\n0.Quite\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Quiting...\n";
            break;
        case 1:
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.print();
            break;
        case 4:
            cout << s.top() << "\n";
            break;
        case 5:
            cout << s.middleElement() << "\n";
            break;
        }
    }
}