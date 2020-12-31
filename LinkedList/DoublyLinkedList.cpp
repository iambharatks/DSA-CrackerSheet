#include <bits/stdc++.h>

using namespace std;
//142. Reverse a dll
//143. Find pairs with given sum in dll
//144. Find triplets with given sum in dll
//145. Sort a k sorted dll
//146. Reverse a dll by k nodes

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int data = 0, Node *prev = NULL, Node *next = NULL) : data(data), prev(prev), next(next) {}
};

class DoublyLinkedList
{
public:
    Node *head, *tail;

    DoublyLinkedList(Node *head = NULL, Node *tail = NULL) : head(head), tail(tail) {}
    void push_back(int data)
    {
        Node *newNode = new Node(data, tail, NULL);
        Node *current = head;
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void print()
    {
        if (!head)
        {
            cout << "Empty List\n";
            return;
        }
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void printRev()
    {
        if (!tail)
        {
            cout << "Empty List\n";
            return;
        }
        Node *current = tail;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    void reverse()
    {
        if (!head)
            return;
        Node *current = head, *prev = NULL, *next = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }
    //distinct elements
    void twoSumSorted(int key)
    {
        Node *left = head, *right = tail;
        while (left->data < right->data)
        {
            if (left->data + right->data == key)
            {
                cout << "(" << left->data << ", " << right->data << "), ";
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data > key)
                right = right->prev;
            else
                left = left->next;
        }
        cout << endl;
    }

    void threeSumSorted(int key)
    {
        Node *i = head;
        while (i->next->next)
        {
            Node *left = i->next, *right = tail;
            while (left->data < right->data && left != right)
            {
                if (i->data + left->data + right->data == key)
                {
                    cout << "(" << i->data << ", " << left->data << ", " << right->data << "), ";
                    left = left->next;
                    right = right->prev;
                }
                else if (i->data + left->data + right->data > key)
                    right = right->prev;
                else
                    left = left->next;
            }
            i = i->next;
        }
        cout << endl;
    }

    int length()
    {
        int i = 0;
        Node *current = head;
        while (current)
        {
            ++i;
            current = current->next;
        }
        return i;
    }

    void rotate(int n)
    {
        Node *current = head;
        int size = length();
        n = n % size;
        int i = 0;
        while (i < n)
        {
            ++i;
            current = current->next;
        }
        tail->next = head;
        head->prev = tail;
        tail = current->prev;
        tail->next = NULL;
        head = current;
    }
    //TODO:=
    void reverseK(int k)
    {
        Node *current = head, *prev = NULL, *next = NULL, *prevTail = NULL, *prevHead = head;
        int i = 0;
        while (current)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
            ++i;
            if (i == k)
            {
                i = 0;
                if (prevTail != NULL)
                {
                    prev->prev = prevTail;
                    prevTail->next = prev;
                }
                else
                    head = prev;
                prevTail = prevHead;
                prevHead = current;
            }
        }
        if (i >= 0)
        {
            if (prevTail)
            {
                prev->prev = prevTail;
                prevTail->next = prev;
            }
            else
                head = prev;
        }
        tail = prevTail;
    }
};
class compare
{
public:
    bool operator()(Node *p1, Node *p2) { return p1->data > p2->data; }
};

DoublyLinkedList kSort(DoublyLinkedList dll, int k)
{
    int i = 0;
    Node *current = dll.head;
    priority_queue<Node *, vector<Node *>, compare> pq;
    while (current && i <= k)
    {
        i++;
        pq.push(current);
        current = current->next;
    }
    DoublyLinkedList newdll;
    while (!pq.empty())
    {
        if (newdll.head == NULL)
        {
            newdll.head = pq.top();
            newdll.head->prev = NULL;
            newdll.tail = newdll.head;
        }
        else
        {
            newdll.tail->next = pq.top();
            pq.top()->prev = newdll.tail;
            newdll.tail = pq.top();
        }
        pq.pop();
        if (current != NULL)
        {
            pq.push(current);

            current = current->next;
        }
    }
    newdll.tail->next = NULL;
    return newdll;
}

int main()
{
    int n;
    cin >> n;
    DoublyLinkedList dll;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        dll.push_back(data);
    }
    int key;
    cin >> key;
    DoublyLinkedList nll = kSort(dll, key);
    dll.print();
    nll.print();
}