#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue
{
    int capacity, rear, frnt;
    T *arr;
    bool isFull() { return (rear + 1) % capacity == frnt; }
    void resizeQueue()
    {
        int size = capacity;
        capacity *= 2;
        T *tmp = new int[capacity]{0};
        if (tmp == NULL)
        {
            cout << "Memory Error\n";
            return;
        }
        if (frnt < rear)
        {
            for (int i = 0; i < size; i++)
                tmp[i] = arr[i];
        }
        else
        {
            int i;
            for (i = frnt; i < size; i++)
                tmp[i - frnt] = arr[i];
            for (i = 0; i <= rear; i++)
                tmp[size - rear + i - 1] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    Queue() : arr(new int[1]{0}), capacity(1), rear(-1), frnt(-1) {}
    ~Queue() { delete[] arr; }
    bool isEmpty() { return frnt == -1; }

    void enQueue(T data)
    {
        if (isFull())
            resizeQueue();
        frnt = (frnt == -1) ? 0 : frnt;
        rear = (rear + 1) % capacity;
        arr[rear] = data;
    }
    void deQueue()
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
    int size()
    {
        return (capacity - frnt + rear + 1) % capacity;
    }
    T front()
    {
        if (isEmpty())
            return -1;
        return arr[frnt];
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Empty Queue\n";
            return;
        }
        if (frnt < rear)
            for (int i = frnt; i < rear; i++)
                cout << arr[i] << " ";
        else
        {
            for (int i = frnt; i < capacity; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void printQueue(Queue<int> q)
{

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.deQueue();
    }
    cout << "\n";
}
int main()
{
    Queue<int> queue;
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
            queue.enQueue(data);
            break;
        case 2:
            queue.deQueue();
            break;
        case 3:
            queue.print();
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