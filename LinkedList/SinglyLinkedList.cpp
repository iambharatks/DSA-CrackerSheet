#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

//123. Reverse a linked List
//124. Reverse a linked List in group of given size
//125. Detect Loop in linked list
//126. Remove Loop in linked list
//127. Find Starting Point of Loop In linked list
//128. Remove duplicate element from sorted Linked List
//129. Remove duplicate element from unsorted Linked List
//130. Move last element to front of a given Linked List
//131. Add one to last element
//132. Add two number represented by ll
//133. Intersection of 2 sorted lls
//134. Intersection point of 2 lls
//135. sort ll using merge Sort
//136. sort ll using quick Sort
//137. Middle element of ll
//140. Check if Linked List is Palindrome
//151. sort ll of 0,1 & 2 (DNF sort)
//155. Delete node which have greater values to its right side
//156. Segregate even and odd nodes in a Linked List
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *next = NULL) : data(data), next(next) {}
};

class LinkedList
{
public:
    Node *head, *tail;
    //constructor
    LinkedList(Node *head = NULL, Node *tail = NULL)
    {
        this->head = head;
        this->tail = tail;
    }

    void push_back(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *current = head, *next = NULL, *prev = NULL;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }
    void reverseK(int K)
    {
        Node *current = head, *next = NULL, *prev = NULL, *prevTail = NULL, *prevHead = head;
        int cnt = 0;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            ++cnt;
            if (cnt == K)
            {
                if (prevTail)
                    prevTail->next = prev;
                else
                {
                    head = prev;
                }
                cnt = 0;
                prevTail = prevHead;
                prevHead = current;
                prev = NULL;
            }
        }
        if (cnt >= 0)
        {
            if (prevTail)
                prevTail->next = prev;
            else
                head = prev;
        }
        tail = prevTail;
    }

    bool detectLoop()
    {
        Node *slow = head, *fast = head;
        if (head == NULL)
            return false;
        while (slow->next && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void removeLoop()
    {
        bool hasLoop = false;
        Node *slow = head, *fast = head;
        while (slow->next && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasLoop = true;
                break;
            }
        }
        if (!hasLoop)
            return;
        if (slow == head && fast == head)
        {
            while (slow->next != head)
            {
                slow = slow->next;
            }
            slow->next = NULL;
            return;
        }
        fast = head;
        Node *prev = head;
        while (fast != slow)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
    }

    Node *startPointOfloop()
    {
        bool hasLoop = false;
        Node *slow = head, *fast = head;
        while (slow->next && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (slow == fast && slow == head)
            return head;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    //sorted ll
    void removeDuplicatesSorted()
    {
        Node *current = head, *prev = NULL;
        while (current)
        {
            if (prev)
            {
                if (prev->data != current->data)
                {
                    prev->next = current;
                    prev = current;
                }
            }
            else
                prev = current;
            current = current->next;
        }
        prev->next = NULL;
        tail = prev;
    }

    //unsorted ll
    void removeDuplicatesUnsorted()
    {
        vector<bool> visited(N, 0);
        Node *current = head, *prev = NULL;
        while (current)
        {
            if (!prev)
            {
                visited[current->data] = true;
                prev = current;
                current = current->next;
                continue;
            }
            if (visited[current->data])
            {
                prev->next = current->next;
                Node *temp = current;
                current = current->next;
                free(temp);
            }
            else
            {
                visited[current->data] = true;
                prev = current;
                current = current->next;
            }
        }
        tail = prev;
    }

    void moveLastToFront()
    {
        Node *current = head, *prev = NULL;
        while (current->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        tail = prev;
        current->next = head;
        head = current;
    }

    void addOne()
    {
        reverse();
        Node *current = head;
        int carry = 1;
        while (current)
        {
            current->data += carry;
            carry = (current->data >= 10) ? 1 : 0;
            current->data = (current->data >= 10) ? current->data - 10 : current->data;
            current = current->next;
        }
        if (carry)
        {
            Node *newNode = new Node;
            newNode->data = carry;
            newNode->next;
            tail->next = newNode;
            tail = newNode;
        }
        reverse();
    }

    LinkedList operator+(LinkedList num)
    {
        reverse();
        num.reverse();
        int carry = 0;
        LinkedList sum;
        int s = 0;
        Node *first = head, *second = num.head;
        while (first && second)
        {
            s = first->data + second->data + carry;
            carry = (s / 10);
            s = s % 10;
            sum.push_back(s);
            first = first->next;
            second = second->next;
        }
        while (first)
        {
            s = first->data + carry;
            carry = (s / 10);
            s = s % 10;
            sum.push_back(s);
            first = first->next;
        }
        while (second)
        {
            s = second->data + carry;
            carry = (s / 10);
            s = s % 10;
            sum.push_back(s);
            second = second->next;
        }
        while (carry)
        {
            s = carry % 10;
            carry /= 10;
            sum.push_back(s);
        }
        sum.reverse();
        return sum;
    }
    LinkedList addTwoNumber(LinkedList num)
    {
        reverse();
        num.reverse();
        int carry = 0;
        LinkedList sum;
        int s = 0;
        Node *first = head, *second = num.head, *prev;
        Node *temp = NULL;
        while (first && second)
        {
            s = first->data + second->data + carry;
            carry = (s / 10);
            s = s % 10;
            if (sum.head == NULL)
            {
                temp = new Node(s);
                sum.head = temp;
                sum.tail = temp;
            }
            else
            {
                prev->next = temp;
                tail = temp;
            }
            prev = temp;
            first = first->next;
            second = second->next;
        }
        while (first)
        {
            s = first->data + carry;
            carry = (s / 10);
            s = s % 10;
            if (sum.head == NULL)
            {
                temp = new Node(s);
                sum.head = temp;
                sum.tail = temp;
            }
            else
            {
                prev->next = temp;
                tail = temp;
            }
            prev = temp;
            first = first->next;
        }
        while (second)
        {
            s = second->data + carry;
            carry = (s / 10);
            s = s % 10;
            s = first->data + carry;
            carry = (s / 10);
            s = s % 10;
            if (sum.head == NULL)
            {
                temp = new Node(s);
                sum.head = temp;
                sum.tail = temp;
            }
            else
            {
                prev->next = temp;
                tail = temp;
            }
            prev = temp;
            second = second->next;
        }
        while (carry)
        {
            s = carry % 10;
            carry /= 10;
            temp = new Node(s);
            prev->next = temp;
            prev = temp;
            tail = temp;
        }
        sum.reverse();
        return sum;
    }

    void intersectionSorted(LinkedList ll)
    {
        Node *first = head, *second = ll.head;
        while (first && second)
        {
            if (first->data == second->data)
            {
                cout << first->data << "\n";
                first = first->next;
                second = second->next;
            }
            else if (first->data < second->data)
                first = first->next;
            else
                second = second->next;
        }
    }

    int length()
    {
        Node *current = head;
        int cnt = 0;
        while (current)
            current = current->next, cnt++;
        return cnt;
    }

    int intersectionPoint(LinkedList ll)
    {
        Node *first = head, *second = ll.head;
        int n = ll.length();
        int m = length();
        int diff = abs(m - n);
        if (m > n)
        {
            while (diff--)
                first = first->next;
        }
        else
        {
            while (diff--)
                second = second->next;
        }
        while (first && second)
        {
            if (first == second)
                return first->data;
            first = first->next;
            second = second->next;
        }
        return -1;
    }

    int middle()
    {
        if (!head)
            return -1;
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    bool isPalindrome()
    {
        Node *fast = head, *middle = head;
        while (fast && fast->next)
        {
            middle = middle->next;
            fast = fast->next->next;
        }
        Node *current = head, *prev = NULL, *next = NULL;
        while (current != middle)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if (fast != NULL)
            middle = middle->next;
        Node *firstHalf = prev, *secondHalf = middle;
        while (firstHalf && secondHalf)
        {
            if (firstHalf->data != secondHalf->data)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
    void dnfSort()
    {
        Node *current = head, *prev = NULL;
        int cnt = 1;
        while (current->next)
        {
            cnt++;
            current = current->next;
        }
        Node *mid = head, *low = head, *high = current;
        while (mid && high && cnt)
        {
            cnt--;
            switch (mid->data)
            {
            case 0:
                if (prev == NULL)
                {
                    prev = mid;
                    mid = mid->next;
                    continue;
                }
                else
                {
                    prev->next = mid->next;
                    mid->next = low;
                    low = mid;
                    mid = prev->next;
                }
                break;
            case 1:
                prev = mid;
                mid = mid->next;
                break;
            case 2:
                if (prev == NULL)
                {
                    low = low->next;
                    mid->next = NULL;
                    high->next = mid;
                    high = mid;
                    mid = low;
                }
                else
                {
                    prev->next = mid->next;
                    mid->next = NULL;
                    high->next = mid;
                    high = mid;
                    mid = prev->next;
                }
                break;
            }
        }
        head = low;
        tail = high;
    }
    void segregateEvenOdd()
    {
        Node *even = NULL, *odd = NULL;
        Node *current = head;
        Node *prevE, *prevO;
        while (current)
        {
            if (((current->data) & 1))
            {
                if (odd == NULL)
                    odd = current;
                else
                    prevO->next = current;
                prevO = current;
            }
            else
            {
                if (even == NULL)
                    even = current;
                else
                    prevE->next = current;
                prevE = current;
            }
            current = current->next;
        }
        if (even != NULL && odd != NULL)
        {
            head = even;
            prevE->next = odd;
            tail = prevO;
            tail->next = NULL;
        }
        else if (even)
        {
            head = even;
            tail = prevE;
            tail->next = NULL;
        }
        else
        {
            head = odd;
            tail = prevO;
            tail->next = NULL;
        }
    }
};

void split(Node *h, Node **first, Node **second)
{
    Node *slow = h, *fast = h->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *first = h;
    *second = slow->next;
    slow->next = NULL;
}
Node *merge(Node *a, Node *b)
{
    Node *merged = NULL, *temp, *prev;
    while (a || b)
    {
        if (a && b)
        {
            if (a->data <= b->data)
            {
                temp = a;
                if (merged == NULL)
                    merged = temp;
                else
                    prev->next = temp;
                prev = temp;
                a = a->next;
            }
            else
            {
                temp = b;
                if (merged == NULL)
                    merged = temp;
                else
                    prev->next = temp;
                prev = temp;
                b = b->next;
            }
        }
        else if (a)
        {
            prev->next = a;
            return merged;
        }
        else
        {
            prev->next = b;
            return merged;
        }
    }
    return merged;
}
void mergeSort(Node **headRef)
{
    if (*headRef == NULL || (*headRef)->next == NULL)
        return;
    Node *h = *headRef, *a, *b;
    split(h, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a, b);
}
void mergeSort(LinkedList ll)
{
    mergeSort(&(ll.head));
    Node *current = ll.head;
    while (current->next)
        current = current->next;
    ll.tail = current;
}

Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail)
{
    Node *pivot = tail, *prev = NULL, *current = head, *tmpTail = pivot;
    while (current != pivot)
    {
        if (current->data < pivot->data)
        {
            if (*newHead == NULL)
                *newHead = current;
            prev = current;
            current = current->next;
        }
        else
        {
            if (prev)
                prev->next = current->next;
            Node *tmp = current->next;
            current->next = NULL;
            tmpTail->next = current;
            tmpTail = current;
            current = tmp;
        }
    }
    if (*newHead == NULL)
        *newHead = pivot;
    *newTail = tmpTail;
    return pivot;
}
Node *quickSort(Node *head, Node *tail)
{
    if (head == NULL || head == tail)
        return head;
    Node *newHead = NULL, *newTail = NULL;
    Node *pivot = partition(head, tail, &newHead, &newTail);
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSort(newHead, tmp);
        tmp = newHead;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newTail);
    return newHead;
}
void quickSort(LinkedList &ll)
{
    ll.head = quickSort(ll.head, ll.tail);
    Node *current = ll.head;
    while (current->next)
        current = current->next;
    ll.tail = current;
}

int main()
{
    int n1, n2;
    cin >> n1;
    LinkedList num1, num2, sum;
    for (int i = 0; i < n1; ++i)
    {
        int data;
        cin >> data;
        num1.push_back(data);
    }
    // for (int i = 0; i < n2; ++i)
    // {
    //     int data;
    //     cin >> data;
    //     num2.push_back(data);
    // }
    num1.segregateEvenOdd();
    // num2 = quickSort(num2);
    num1.print();
    // num2.print();
}