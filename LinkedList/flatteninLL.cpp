#include <bits/stdc++.h>

using namespace std;
//150. Flatten a Linked List
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node *flatten(Node *root);

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {
                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);
                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;
        Node *root = flatten(head);
        printList(root);
        cout << endl;
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
                first = first->bottom;
            }
            else
            {
                tmp = second;
                second = second->bottom;
            }
            if (merged == NULL)
                merged = tmp;
            else
                prev->bottom = tmp;
            prev = tmp;
        }
        else if (first)
        {
            if (merged == NULL)
                merged = first;
            else
                prev->bottom = first;
            return merged;
        }
        else
        {
            if (merged == NULL)
                merged = second;
            else
                prev->bottom = second;
            return merged;
        }
    }
    return merged;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL)
        return NULL;
    Node *first = root, *second = root->next, *next;
    while (second)
    {
        next = second->next;
        first = merge(first, second);
        second = next;
    }
    return first;
}