#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue
{
    stack<T> s1, s2;

public:
    bool isEmpty() { return s1.empty(); }
    void push(T newElement) { s1.push(newElement); }
    T pop()
    {
        T poppedElement;
        if (s1.empty())
            return poppedElement;
        if (s1.size() == 1)
        {
            poppedElement = s1.top();
            s1.pop();
            return poppedElement;
        }
        while (s1.size() != 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        poppedElement = s1.top();
        s1.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());

            s2.pop();
        }
        return poppedElement;
    }
    //single stack used
    T popRecursive()
    {
        if (s1.empty())
            return -1;
        T current = s1.top();
        s1.pop();
        if (s1.empty())
            return current;
        T poppedElement = popRecursive();
        s1.push(current);
        return poppedElement;
    }
};

void printQueue(Queue<int> q)
{
    while (!q.isEmpty())
        cout << q.pop() << " ";
    cout << endl;
}

int main()
{
    Queue<int> q;
    cout << "Enter your choice\n"
         << "\t1.Push value into Stack\n"
         << "\t2.Pop element from Stack\n"
         << "\t3.Print elements of Stack\n"
         << "\t0.Quite\n";
    int choice, data;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            q.push(data);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            printQueue(q);
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