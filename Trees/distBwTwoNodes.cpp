#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};

class bt
{
    int nodes;

public:
    Node *root;
    bt(Node *root = NULL) : root(root), nodes(0) {}
    int number_of_nodes() { return nodes; }
    void insert(int data)
    {
        nodes++;
        Node *newNode = new Node(data);
        Node *tmp;
        if (!root)
        {
            root = newNode;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            else
            {
                tmp->left = newNode;
                return;
            }
            if (tmp->right)
                q.push(tmp->right);
            else
            {
                tmp->right = newNode;
                return;
            }
        }
    }
};

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return root;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    return (left) ? left : right;
}

int findLevel(Node *root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return level;
    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}

int findDistance(Node *root, int a, int b)
{
    Node *lca = LCA(root, a, b);
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    return d1 + d2;
}



int main()
{
    bt tree;
    int n;
    cin >> n;
    while (n--)
    {
        int data;
        cin >> data;
        tree.insert(data);
    }
    int a, b;
    cin >> a >> b;
    cout << findDistance(tree.root, a, b);
}
