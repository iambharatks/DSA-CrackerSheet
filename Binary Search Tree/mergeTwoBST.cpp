
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

    void insert(int data)
    {
        if (search(&root, data))
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

//First Method O(n)
//1.get inorders of tree1 and tree2 : O(n)
//2.merge two inorder in sorted form(gap method) : O(n)
//3.create balanced bst using that sorted merged array : O(n)
//This approach is not inplace merging
void mergeSortedArray(vector<int> &inorder)
{
    int gap = inorder.size();
    for (gap = (gap == 1) ? 0 : (gap << 1) + (gap & 1); gap > 0; gap = (gap == 1) ? 0 : (gap << 1) + (gap & 1))
    {
        for (int i = 0; i + gap < inorder.size(); ++i)
        {
            if (inorder[i] > inorder[i + gap])
                swap(inorder[i], inorder[i + gap]);
        }
    }
}
Node *balancedBSTFromSorted(vector<int> &inorder, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = low + ((high - low) >> 1);
    Node *newNode = new Node(inorder[mid]);
    if (high == low)
        return newNode;
    newNode->left = balancedBSTFromSorted(inorder, low, mid - 1);
    newNode->right = balancedBSTFromSorted(inorder, mid + 1, high);
    return newNode;
}
void mergeBST(bst tree1, bst tree2, bst &mergedTree)
{
    vector<int> inorder;
    tree1.getInorder(inorder);
    tree2.getInorder(inorder);
    mergeSortedArray(inorder);
    int size = inorder.size();
    bst tree(balancedBSTFromSorted(inorder, 0, size - 1), size);
    mergedTree = tree;
}

//Second Method
//1.convert both trees into dll //O(n)
//2.merge two dll in sorted form //O(n)
//3.convert merged sorted dll inot balanced bst //O(n)
//This method is inplace
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
Node *dllToBST(Node **headref, int n)
{
    if (n <= 0)
        return NULL;
    Node *left = dllToBST(headref, n / 2);
    Node *root = *headref;
    root->left = left;
    *headref = (*headref)->right;
    root->right = dllToBST(headref, n - n / 2 - 1);
    return root;
}
void mergeSortedDll(Node *head1, Node *head2, Node **head)
{
    Node *prev = NULL;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            if (prev)
            {
                prev->right = head1;
                head1->left = prev;
            }
            else
                *head = head1;
            prev = head1;
            head1 = head1->right;
        }
        else
        {
            if (prev)
            {
                prev->right = head2;
                head2->left = prev;
            }
            else
                *head = head2;
            prev = head2;
            head2 = head2->right;
        }
    }
    if (head1)
    {
        if (prev)
        {
            prev->right = head1;
            head1->left = prev;
        }
        else
            *head = head1;
        return;
    }
    if (head2)
    {
        if (prev)
        {
            prev->right = head2;
            head2->left = prev;
        }
        else
            *head = head2;
        prev = head2;
    }
}
void treeToDll(Node *root, Node **head)
{
    if (!root)
        return;
    treeToDll(root->right, head);
    root->right = *head;
    if ((*head) != NULL)
        (*head)->left = root;
    *head = root;
    treeToDll(root->left, head);
}
void mergeBSTs(bst &tree1, bst &tree2)
{
    Node *head1 = NULL, *head2 = NULL;
    treeToDll(tree1.root, &head1);
    treeToDll(tree2.root, &head2);
    printDll(head1);
    printDll(head2);
    Node *head = NULL;
    mergeSortedDll(head1, head2, &head);
    printDll(head);
    int n = tree1.number_of_nodes() + tree2.number_of_nodes();
    head = dllToBST(&head, n);
    bst tree(head, n);
    tree1 = tree;
}

int main()
{
    bst tree1, tree2, mergedTree;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        tree1.insert(data);
    }
    cin >> n;
    while (n--)
    {
        cin >> data;
        tree2.insert(data);
    }
    mergeBSTs(tree1, tree2);
    cout << "printing Merged Tree\n";
    tree1.inorder();
    tree1.preorder();

}