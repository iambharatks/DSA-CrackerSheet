#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data, Node *next = NULL) : data(data), next(next) {}
};

template <typename T>
class Stack
{
    Node<T> *sp;
    T _top;

public:
    Stack() : sp(NULL){};
    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        _top = newNode->data;
        if (!sp)
        {
            sp = newNode;
            return;
        }
        newNode->next = sp;
        sp = newNode;
    }
    void pop()
    {
        if (!sp)
        {
            cout << "stack underflow\n";
            return;
        }
        Node<T> *tmp = sp;
        sp = sp->next;
        free(tmp);
        if (sp)
            _top = sp->data;
    }
    bool isEmpty() { return (!sp); }

    T top() { return _top; }
};

void printStack(Stack<int> s)
{
    if (s.isEmpty())
        return;
    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}

int main()
{
    int data, choice = 1;
    Stack<int> s;
    while (choice)
    {
        cout << "Enter choice\n1.Push\n2.Pop\n3.Display\n4.Top of stack\n0.Quite\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Quiting\n";
            break;
        case 1:
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            printStack(s);
            break;
        case 4:
            cout << s.top() << "\n";
            break;
        }
    }
}