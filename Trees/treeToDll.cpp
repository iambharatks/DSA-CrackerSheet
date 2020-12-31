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
void printDll(Node *root)
{
    cout << "printing dll\n";
    for (; root->right; root = root->right)
        cout << root->data << " ";
    cout << root->data << " ";
    cout << endl;
    for (; root->left; root = root->left)
        cout << root->data << " ";
    cout << root->data << " ";
    cout << endl;
}
//set1
Node *treeToDllUtil(Node *root)
{
    if (!root)
        return NULL;
    if (root->left)
    {
        Node *left = treeToDllUtil(root->left);
        for (; left->right; left = left->right)
            ;
        left->right = root;
        root->left = left;
    }
    if (root->right)
    {
        Node *right = treeToDllUtil(root->right);
        for (; right->left; right = right->left)
            ;
        right->left = root;
        root->right = right;
    }
    return (root);
}
void treeToDll(Node *root)
{
    if (!root)
        return;
    root = treeToDllUtil(root);
    for (; root->left; root = root->left)
        ;
    printDll(root);
}

//set2
void fixPrev(Node *root)
{
    static Node *pre = NULL;
    if (root != NULL)
    {
        fixPrev(root->left);
        root->left = pre;
        pre = root;
        fixPrev(root->right);
    }
}
Node *fixNextPtr(Node *root)
{
    Node *prev = NULL;
    while (root && root->right)
        root = root->right;
    while (root && root->left)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return root;
}
void BtoDll(Node *root)
{
    fixPrev(root);
    root = fixNextPtr(root);
    printDll(root);
}

//set3
void binaryToDll(Node *root, Node **head)
{
    if (!root)
        return;
    static Node *prev = NULL;
    binaryToDll(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    binaryToDll(root->right, head);
}

//set 4
void btToDll(Node *root, Node **head)
{
    if (!root)
        return;
    btToDll(root->right, head);
    root->right = *head;
    if (*head != NULL)
        (*head)->left = root;
    *head = root;
    btToDll(root->left, head);
}

int main()
{
    bt tree;
    int n, data, tmp;
    cin >> n;
    int t;
    while (n--)
    {
        cin >> data;
        tree.insert(data);
    }
    n = tree.number_of_nodes();
}