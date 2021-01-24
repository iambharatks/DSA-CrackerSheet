#include <bits/stdc++.h>

using namespace std;


// Stack using two queues 
template <typename T>
class Stack
{
    queue<T> q1, q2;
    T tp;

public:
    //O(1)
    void push(T newElement)
    {
        q1.push(newElement);
        tp = newElement;
    }
    T pop()
    {
        if (q1.empty())
            return -1;
        T poppedElement;
        if (q1.size() == 1)
        {
            poppedElement = q1.front();
            tp = -1;
            q1.pop();
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                tp = q1.front();
                q1.pop();
            }
            poppedElement = q1.front();
            q1.pop();
            swap(q1, q2);
        }
        return poppedElement;
    }
    T top() { return tp; }
    bool isEmpty() { return q1.empty(); }
};

void printStack(Stack<int> s)
{
    while (!s.isEmpty())
    {
        cout << s.pop() << " ";
    }
    cout << "\n";
}

int main()
{
    Stack<int> s;
    cout << "Enter your choice\n"
         << "\t1.Push value into Stack\n"
         << "\t2.Pop element from Stack\n"
         << "\t3.Print elements of Stack\n"
         << "\t4.Top of Stack\n"
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
        case 0:
            cout << "Quiting\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice);
    cout << "Thankyou\n";
}