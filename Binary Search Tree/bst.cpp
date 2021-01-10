
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
                return;
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
    Node *balancedBSTUtil(vector<int> sorted_array, int low, int high)
    {
        if (low > high)
            return NULL;
        int mid = low + (high - low) / 2;
        Node *newNode = new Node(sorted_array[mid]);
        if (high == low)
            return newNode;
        newNode->left = balancedBSTUtil(sorted_array, low, mid - 1);
        newNode->right = balancedBSTUtil(sorted_array, mid + 1, high);
        return newNode;
    }
    void balancedBST(vector<int> array)
    {
        sort(array.begin(), array.end());
        root = balancedBSTUtil(array, 0, array.size() - 1);
    }

    void kthLargestUtil(Node *root, int k, int &cnt, int &ans)
    {
        if (!root || cnt == k)
            return;
        kthLargestUtil(root->right, k, cnt, ans);
        cnt++;
        if (cnt == k)
        {
            ans = root->data;
            return;
        }
        kthLargestUtil(root->left, k, cnt, ans);
    }
    int kthLargest(int K)
    {
        int ans = INT8_MAX, cnt = 0;
        kthLargestUtil(root, K, cnt, ans);
        return (ans == INT8_MAX) ? -1 : ans;
    }

    void kthSmallestElementUtil(Node *root, int k, int &cnt, int &ans)
    {
        if (!root || cnt == k)
            return;
        kthSmallestElementUtil(root->left, k, cnt, ans);
        cnt++;
        if (cnt == k)
        {
            ans = root->data;
            return;
        }
        kthSmallestElementUtil(root->right, k, cnt, ans);
    }
    int KthSmallestElement(int K)
    {
        //Your code here
        int ans = INT8_MIN, cnt = 0;
        kthSmallestElementUtil(root, K, cnt, ans);
        return (ans == INT8_MIN) ? -1 : ans;
    }
    int findMedian()
    {
        if (!root)
            return 0;
        if (nodes == 1)
            return root->data;
        int curCnt = 0;
        Node *current = root, *prev = NULL, *pred = NULL;
        while (current)
        {
            if (!current->left)
            {
                curCnt++;
                if ((nodes & 1) == 0 && curCnt == (nodes / 2 + 1))
                    return (prev->data + current->data) / 2;
                else if ((nodes & 1) && curCnt == (nodes + 1) / 2)
                    return current->data;
                prev = current;
                current = current->right;
            }
            else
            {
                pred = current->right;
                while (pred->right != NULL && pred->right != current)
                    pred = pred->right;
                if (pred->right)
                {
                    pred->right = NULL;
                    curCnt++;
                    if ((nodes & 1) == 0 && curCnt == (nodes / 2 + 1))
                        return (prev->data + current->data) / 2;
                    else if ((nodes & 1) && curCnt == (nodes + 1) / 2)
                        return current->data;
                    prev = current;
                    current = current->right;
                }
                else
                {
                    pred->right == current;
                    current = current->left;
                }
            }
        }
        return -1;
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

int getCount(Node *root, int l, int h)
{
    static int cnt = 0;
    if (!root)
        return cnt;
    if (root->data >= l && root->data <= h)
        cnt++;
    if (root->data > l)
    {
        getCount(root->left, l, h);
    }
    if (root->data < h)
    {
        getCount(root->right, l, h);
    }
    return cnt;
}
// Brothers From Different Roots
int countPairs(Node *root1, Node *root2, int x)
{
    if (root1 == NULL || root2 == NULL)
        return 0;
    stack<Node *> st1, st2;
    Node *top1, *top2;
    int count = 0;
    while (true)
    {
        while (root1 != NULL)
        {
            st1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL)
        {
            st2.push(root2);
            root2 = root2->right;
        }
        if (st1.empty() || st2.empty())
            break;
        top1 = st1.top();
        top2 = st2.top();
        cout << top1->data << " " << top2->data << "\n";
        if ((top1->data + top2->data) == x)
        {
            count++;
            st1.pop();
            st2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }
        else if ((top1->data + top2->data) < x)
        {
            st1.pop();
            root1 = top1->right;
        }
        else
        {
            st2.pop();
            root2 = top2->left;
        }
    }
    return count;
}

int main()
{
    int n, data;
    cin >> n;
    bst t1, t2;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        t1.insert(data);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> data;
    //     t2.insert(data);
    // }
    t1.lot();
    // cout << getCount(t1.root, 7, 9);
    cout << t1.findMedian() << "\n";
    // Node *pre = NULL, *suc = NULL;
    // findPreSuc(tree.root, pre, suc, 40);
    // if (pre)
    //     cout << "Inorder predessor is " << pre->data << " ";
    // if (suc)
    //     cout << "Inorder successor is " << suc->data << " ";
}