
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};
Node *search(Node **root, int key)
{
    if (!(*root))
        return (*root) = new Node(key);
    if ((*root)->data == key)
        return NULL;
    if ((*root)->data > key)
    {
        if ((*root)->left)
            return search(&(*root)->left, key);
        (*root)->left = new Node(key);
        return (*root)->left;
    }
    if ((*root)->right)
        return search(&(*root)->right, key);
    (*root)->right = new Node(key);
    return (*root)->right;
}

class bst
{
    int nodes;

public:
    Node *root;
    bst(Node *root = NULL) : root(root), nodes(0) {}
    int number_of_nodes() { return nodes; }

    void insert(int data)
    {
        if (search(&root, data))
            nodes++;
        return;
    }
    void lot()
    {
        if (!root)
            return;
        Node *tmp;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        cout << endl;
    }
    int min()
    {
        if (!root)
            return INT_MAX;
        Node *current = root;
        while (current && current->left)
            current = current->left;
        return current->data;
    }
    int max()
    {
        if (!root)
            return INT_MIN;
        Node *current = root;
        while (current && current->right)
            current = current->right;
        return current->data;
    }
};
Node *minValueNode(Node *root)
{
    Node *current = root;
    while (current && current->left)
        current = current->left;
    return current;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
        Node *tmp = minValueNode(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->data == key)
    {
        if (root->right)
        {
            suc = root->right;
            while (suc->left)
                suc = suc->left;
        }
        if (root->left)
        {
            pre = root->left;
            while (pre->right)
                pre = pre->right;
        }
    }
    else if (key < root->data)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}
Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (n1 > n2)
        swap(n1, n2);
    if (root->data == n1 || root->data == n2)
        return root;
    if ((root->data > n1) && (root->data < n2))
        return root;
    if (root->data < n1)
        return LCA(root->right, n1, n2);
    else
        return LCA(root->left, n1, n2);
}
int main()
{
    int n;
    cin >> n;
    bst tree;
    while (n--)
    {
        int data;
        cin >> data;
        tree.insert(data);
    }
    cout << tree.number_of_nodes() << "\n";
    tree.lot();
    tree.root = deleteNode(tree.root, 1);
    tree.lot();
    Node *lca = LCA(tree.root, 18, 55);
    cout << lca->data << " ";

    // Node *pre = NULL, *suc = NULL;
    // findPreSuc(tree.root, pre, suc, 40);
    // if (pre)
    //     cout << "Inorder predessor is " << pre->data << " ";
    // if (suc)
    //     cout << "Inorder successor is " << suc->data << " ";
}