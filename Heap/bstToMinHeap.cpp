
#include <bits/stdc++.h>

using namespace std;
//Convert BST to minHeap
//Time Complexity := O(n)
//Space Complexity := O(n)
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

    Node *BSTfromPre(vector<int> pre, int &preIdx, int key, int min, int max)
    {
        if (preIdx >= pre.size())
            return NULL;
        Node *newNode = NULL;
        if (key > min && key < max)
        {
            newNode = new Node(key);
            preIdx++;
            if (preIdx < pre.size())
                newNode->left = BSTfromPre(pre, preIdx, pre[preIdx], min, key);
            if (preIdx < pre.size())
                newNode->right = BSTfromPre(pre, preIdx, pre[preIdx], key, max);
        }
        return newNode;
    }
    void constructBSTfromPre(vector<int> pre)
    {
        int idx = 0;
        root = BSTfromPre(pre, idx, pre[idx], INT_MIN, INT_MAX);
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
                return;
            tmp = s.top();
            s.pop();
            cout << tmp->data << " ";
            tmp = tmp->right;
        }
        cout << '\n';
    }
    void insert(int data)
    {
        if (search(&root, data))
            nodes++;
        return;
    }
};

void getInorder(Node *root, vector<int> &inorder)
{
    if (!root)
        return;
    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}
void bstToMinHeapUtil(Node *root, vector<int> inorder)
{
    static int i = 0;
    if (!root || i >= inorder.size())
        return;
    root->data = inorder[i++];
    bstToMinHeapUtil(root->left, inorder);
    bstToMinHeapUtil(root->right, inorder);
}
void bstToMinHeap(bst &tree)
{
    vector<int> inorder;
    getInorder(tree.root, inorder);
    bstToMinHeapUtil(tree.root, inorder);
    tree.preorder();
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
    tree.preorder();
    bstToMinHeap(tree);
}