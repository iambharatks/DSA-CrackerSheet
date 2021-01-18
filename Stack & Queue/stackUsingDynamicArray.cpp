#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int size;
    int capacity;
    Stack(int capacity = 1)
    {
        size = 0;
        this->capacity = capacity;
        arr = new T[capacity];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void push(T data)
    {
        if (size == capacity)
        {
            capacity = capacity * 2;
            T *temp = new T[capacity];
            int i;
            for (i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            temp[i] = data;
            free(arr);
            arr = temp;
            size++;
        }
        else
        {
            arr[size] = data;
            size++;
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
        if (isEmpty())
        {
            cout << "stack is empty\n";
            return;
        }
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
            cout << "Cannot delete from an empty stack\n";
            return;
        }
        free(arr);
        size = 0;
        capacity = 1;
    }
    T top()
    {
        if (isEmpty())
        {
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
    Stack<int> s = Stack<int>();
    cout << "Enter your choice\n"
         << "\t1.Push value into stack\n"
         << "\t2.Pop element from stack\n"
         << "\t3.Print elements of stack\n"
         << "\t4.Top of stack\n"
         << "\t5.delete stack\n"
         << "\t0.Quite\n";
    int choice, data;
    do
    {
        cin >> choice;
        switch (choice)
        {
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
        case 5:
            s.deleteStack();
            break;
        case 0:
            cout << "Quiting\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice);
    cout << "Thankyou\n";
}