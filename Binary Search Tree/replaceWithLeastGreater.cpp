// Replace every element with the least greater element on its right

//1 .My Approach is that i will insert all the elements of array in bst.
//2. Then, I will replace every node with its inorder successor
// (O(n*n) for unbalanced bst)
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};

class bst
{
    int nodes;

public:
    Node *root;
    bst(Node *root = NULL, int nodes = 0) : root(root), nodes(nodes) {}
    int number_of_nodes() { return nodes; }

    Node *search(Node **root, int key, int &suc)
    {
        if (!(*root))
            return (*root) = new Node(key);
        if ((*root)->data == key)
            return NULL;
        if ((*root)->data > key)
        {
            suc = (*root)->data;
            if ((*root)->left)
                return search(&(*root)->left, key, suc);
            (*root)->left = new Node(key);
            return (*root)->left;
        }
        if ((*root)->right)
            return search(&(*root)->right, key, suc);
        (*root)->right = new Node(key);
        return (*root)->right;
    }

    void insert(int data, int &suc)
    {
        if (search(&root, data, suc))
            nodes++;
        return;
    }

    void preorder()
    {
        stack<Node *> s;
        Node *tmp = root;
        while (true)
        {
            while (tmp)
            {
                cout << tmp->data << " ";
                s.push(tmp);
                tmp = tmp->left;
            }
            if (s.empty())
            {
                cout << endl;
                return;
            }
            tmp = s.top();
            s.pop();
            tmp = tmp->right;
        }
    }
    void inorder()
    {
        stack<Node *> s;
        Node *tmp = root;
        while (true)
        {
            while (tmp)
            {
                s.push(tmp);
                tmp = tmp->left;
            }
            if (s.empty())
            {
                cout << endl;
                return;
            }
            tmp = s.top();
            s.pop();
            cout << tmp->data << " ";
            tmp = tmp->right;
        }
    }
    void lot()
    {
        if (!root)
        {
            cout << "empty bst\n";
            return;
        }
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

    int height()
    {
        queue<Node *> q;
        int level = 0;
        if (!root)
            return level;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                level++;
            }
            else
            {
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        return level;
    }

    void getInorder(vector<int> &inorder)
    {
        stack<Node *> s;
        Node *node = root;
        while (true)
        {
            while (node)
            {
                s.push(node);
                node = node->left;
            }
            if (s.empty())
                return;
            node = s.top();
            inorder.push_back(node->data);
            s.pop();
            node = node->right;
        }
    }
};

void replace(Node *root, vector<int> &arr)
{
    if (!root)
        return;
}

int main()
{
    int n, data;
    cin >> n;
    bst tree;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int suc = -1;
        tree.insert(arr[i], suc);
        arr[i] = suc;
    }
    tree.inorder();
    for (int i : arr)
        cout << i << " ";
}