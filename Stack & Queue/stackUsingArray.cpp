#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack
{
    T *arr;
    int size;
    int capacity;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->size = 0;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
    bool isFull()
    {
        return size == capacity;
    }
    void push(T value)
    {
        if (!isFull())
        {
            arr[size] = value;
            size++;
        }
        else
        {
            cout << "Stack is full\n";
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            size--;
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }
    void print()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    void deleteStack()
    {
        if (isEmpty())
        {
            cout << "Cannot delete an empty stack\n";
            return;
        }
        free(arr);
        size = 0;
        capacity = 0;
    }
    T bottom()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        else
        {
            return arr[0];
        }
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        else
        {
            return arr[size - 1];
        }
    }
};
void printStack(Stack<int> s)
{
    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    int choice, data;
    Stack<int> s(1000);

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
            printStack(s);
            break;
        case 4:
            cout << s.top() << "\n";
            break;
        }
    }
}