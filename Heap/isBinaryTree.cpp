#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
bool isHeap(struct Node *tree);
/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d", &n);
        struct Node *root = NULL;
        struct Node *child;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << isHeap(root) << endl;
    }
    return 0;
}

// Is Binary Tree Heap
bool isHeap(Node *tree)
{
    if (!tree)
        return true;
    if ((tree->left && tree->left->data > tree->data) || (tree->right && tree->right->data > tree->data))
        return false;

    bool left = isHeap(tree->left);
    bool right = isHeap(tree->right);
    return left && right;
}