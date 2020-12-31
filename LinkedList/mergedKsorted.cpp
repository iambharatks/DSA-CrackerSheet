#include <bits/stdc++.h>
using namespace std;
//153. Merge K sorted lls
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *mergeKLists(Node *arr[], int N);
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;
            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Node *res = mergeKLists(arr, N);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends

Node *merge(Node *first, Node *second)
{
    Node *merged = NULL;
    Node *tmp, *prev = NULL;
    while (first || second)
    {
        if (first && second)
        {
            if (first->data <= second->data)
            {
                tmp = first;
                first = first->next;
            }
            else
            {
                tmp = second;
                second = second->next;
            }
            if (merged == NULL)
                merged = tmp;
            else
                prev->next = tmp;
            prev = tmp;
        }
        else if (first)
        {
            if (merged == NULL)
                merged = first;
            else
                prev->next = first;
            return merged;
        }
        else
        {
            if (merged == NULL)
                merged = second;
            else
                prev->next = second;
            return merged;
        }
    }
    return merged;
}
Node *mergeKLists(Node *arr[], int N)
{
    // Your code here
    int i = 2;
    if (N == 0)
        return NULL;
    if (N == 1)
        return arr[0];
    Node *merged = merge(arr[0], arr[1]);
    while (i < N)
    {
        merged = merge(merged, arr[i]);
        i++;
    }
    return merged;
}
