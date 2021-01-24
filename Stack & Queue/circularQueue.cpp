#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue
{
    int capacity, rear, frnt;
    T *arr;

public:
    Queue(int size) : capacity(size), arr(new int[size]), rear(-1), frnt(-1) {}
    bool isFull() { return (rear + 1) % capacity == frnt; }
    bool isEmpty() { return frnt == -1; }
    void push(T newElement)
    {
        if (isFull())
        {
            cout << "Queue overflow\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = newElement;
        frnt = (frnt == -1) ? 0 : frnt;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue underflow\n";
            return;
        }
        if (frnt == rear)
            frnt = rear = -1;
        else
            frnt = (frnt + 1) % capacity;
    }
    int size() { return (capacity - frnt + rear) % capacity + 1; }
    T front()
    {
        T front;
        if (!isEmpty())
            front = arr[frnt];
        return front;
    }
};
void printQueue(Queue<int> q)
{

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter capacity of circular Queue\n";
    cin >> n;
    Queue<int> queue(n);
    cout << "Enter your choice\n"
         << "\t1.Push value into Queue\n"
         << "\t2.Pop element from Queue\n"
         << "\t3.Print elements of Queue\n"
         << "\t4.Front of Queue\n"
         << "\t5.Size of Queue\n"
         << "\t0.Quite\n";
    int choice, data;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            queue.push(data);
            break;
        case 2:
            queue.pop();
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            cout << queue.front() << "\n";
            break;
        case 5:
            cout << queue.size() << "\n";
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