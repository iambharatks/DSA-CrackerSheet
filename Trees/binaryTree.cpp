#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left = NULL, Node *right = NULL) : data(data), left(left), right(right) {}
};

// Binary Tree to Binary Search Tree Conversion
void toBSTUtil(Node *root, int *inorder, int size, int &idx)
{
    if (!root || idx >= size)
        return;
    toBSTUtil(root->left, inorder, size, idx);
    (root)->data = inorder[idx++];
    toBSTUtil(root->right, inorder, size, idx);
}
void getInorder(Node *root, int inorder[], int n)
{
    static int pos = 0;
    if (!root)
        return;
    if (pos >= n)
        return;
    getInorder(root->left, inorder, n);
    inorder[pos++] = root->data;
    getInorder(root->right, inorder, n);
}
class bt
{
    int nodes;

public:
    Node *root;
    bt(Node *root = NULL) : root(root), nodes(0) {}
    int number_of_nodes() { return nodes; }
    // using levelOrder
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

    void reverseLot()
    {
        if (!root)
            return;
        Node *tmp;
        queue<Node *> q;
        stack<int> s;
        q.push(root);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            s.push(tmp->data);
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
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
                return;
            tmp = s.top();
            s.pop();
            tmp = tmp->right;
        }
    }

    void postorder()
    {
        stack<Node *> s;
        Node *current = root, *previous = NULL;
        do
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }
            while (current == NULL && !s.empty())
            {
                current = s.top();
                if ((current->right == NULL) || (current->right == previous))
                {
                    cout << current->data << " ";
                    s.pop();
                    previous = current;
                    current = NULL;
                }
                else
                    current = current->right;
            }
        } while (!s.empty());
    }

    void leftView()
    {
        queue<Node *> q;
        Node *tmp = root;
        q.push(tmp);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                tmp = q.front();
                if (i == 0)
                    cout << tmp->data << " ";
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        cout << '\n';
    }

    void rightView()
    {
        queue<Node *> q;
        Node *tmp = root;
        q.push(tmp);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                tmp = q.front();
                q.pop();
                if (i == n - 1)
                    cout << tmp->data << " ";
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        cout << '\n';
    }

    void bottomView()
    {
        queue<pair<Node *, int>> q;
        pair<Node *, int> tmp;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            mp[tmp.second] = (tmp.first)->data;
            if (tmp.first->left)
                q.push({tmp.first->left, tmp.second - 1});
            if (tmp.first->right)
                q.push({tmp.first->right, tmp.second + 1});
        }
        for (auto i : mp)
            cout << i.second << " ";
    }

    void zigzag()
    {
        if (!root)
            return;
        bool leftToRight = true;
        stack<Node *> curLevel, nextLevel;
        curLevel.push(root);
        Node *tmp;
        while (!curLevel.empty())
        {
            tmp = curLevel.top();
            curLevel.pop();
            cout << tmp->data << " ";
            if (leftToRight)
            {
                if (tmp->left)
                    nextLevel.push(tmp->left);
                if (tmp->right)
                    nextLevel.push(tmp->right);
            }
            else
            {
                if (tmp->right)
                    nextLevel.push(tmp->right);
                if (tmp->left)
                    nextLevel.push(tmp->left);
            }
            if (curLevel.empty())
            {
                leftToRight = !leftToRight;
                swap(curLevel, nextLevel);
            }
        }
    }

    void diagonal()
    {
        queue<pair<Node *, int>> q;
        pair<Node *, int> tmp;
        q.push({root, 0});
        map<int, vector<int>> mp;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            mp[tmp.second].push_back(tmp.first->data);
            if (tmp.first->left)
                q.push({tmp.first->left, tmp.second + 1});
            if (tmp.first->right)
                q.push({tmp.first->right, tmp.second});
        }
        for (auto v : mp)
        {
            for (auto i : v.second)
                cout << i << " ";
            cout << '\n';
        }
    }

    void leftBoundary(Node *root)
    {
        if (root)
        {
            if (root->left)
            {
                cout << root->data << " ";
                leftBoundary(root->left);
            }
            else if (root->right)
            {
                cout << root->data << " ";
                leftBoundary(root->right);
            }
        }
    }
    void rightBoundary(Node *root)
    {
        if (root)
        {
            if (root->right)
            {
                rightBoundary(root->right);
                cout << root->data << " ";
            }
            else if (root->left)
            {
                rightBoundary(root->left);
                cout << root->data << " ";
            }
        }
    }
    void leafNodes(Node *root)
    {
        if (!root)
            return;
        leafNodes(root->left);
        if ((root->left == NULL) && (root->right == NULL))
            cout << root->data << " ";
        leafNodes(root->right);
    }
    void printBoundary()
    {
        if (!root)
            return;
        cout << root->data << " ";
        leftBoundary(root->left);
        leafNodes(root->left);
        leafNodes(root->right);
        rightBoundary(root->right);
    }

    void toBST()
    {
        int *inorder = new int[nodes]{0};
        getInorder(root, inorder, nodes);
        sort(inorder, inorder + nodes);
        int idx = 0;
        toBSTUtil(root, inorder, nodes, idx);
    }
};
bool search(Node *root, int data)
{
    if (!root)
        return false;
    Node *tmp;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        tmp = q.front();
        if (tmp->data == data)
            return true;
        cout << tmp->data << " ";
        q.pop();
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    return false;
}

bool isBalanced(Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool l = isBalanced(root->left, &lh);
    bool r = isBalanced(root->right, &rh);
    *height = ((lh > rh) ? lh : rh) + 1;
    if (abs(l - r) >= 2)
        return false;
    return l && r;
}

int height(Node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void mirror(Node *root)
{
    if (!root)
        return;
    Node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

void leftViewUtil(Node *root, int level, int *max_level)
{
    if (root == NULL)
        return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
void leftView(Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
    cout << endl;
}

int diameter(Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 0;
    }
    int leftH = 0, rightH = 0;
    int leftD = diameter(root->left, &leftH);
    int rightD = diameter(root->right, &rightH);
    *height = max(leftH, rightH) + 1;
    return max(leftH + rightH + 1, max(leftD, rightD));
}

void fillMap(Node *root, map<int, pair<int, int>> &mp, int horDist, int level)
{
    if (!root)
        return;
    if (mp.count(horDist) == 0)
        mp[horDist] = {root->data, level};
    else if (mp[horDist].second > level)
        mp[horDist] = {root->data, level};
    fillMap(root, mp, horDist - 1, level + 1);
    fillMap(root, mp, horDist + 1, level + 1);
}
void topView(Node *root)
{
    if (!root)
        return;
    map<int, pair<int, int>> mp;
    fillMap(root, mp, 0, 0);
    for (auto i : mp)
        cout << i.second.first << " ";
}

int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;
    stack<char> s;
    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            if (s.top() == '(')
                s.pop();
            if (s.empty())
                return i;
        }
    }
    return -1;
}
Node *treeFromString(Node *root, string str, int si, int ei)
{
    if (si > ei)
        return NULL;
    root = new Node(str[si] - '0');
    int index = -1;
    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);
    if (index != -1)
    {
        root->left = treeFromString(root->left, str, si + 2, index - 1);
        root->right = treeFromString(root->right, str, index + 2, ei - 1);
    }
    return root;
}

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

int sumTree(Node *root)
{
    if (!root)
        return 0;
    int oldData = root->data;
    root->data = sumTree(root->left) + sumTree(root->right);
    return oldData + root->data;
}

int search(int in[], int s, int e, int key)
{
    for (int i = s; i <= e; i++)
        if (in[i] == key)
            return i;
    return -1;
}
Node *buildTreeUsingIP(int in[], int pre[], int is, int ie, int n)
{
    static int preIdx = 0;
    Node *newNode = NULL;
    if (is > ie || preIdx >= n)
        return NULL;
    newNode = new Node(pre[preIdx++]);
    if (is == ie)
        return newNode;
    int inoIdx = search(in, is, ie, newNode->data);
    newNode->left = buildTreeUsingIP(in, pre, is, inoIdx - 1, n);
    newNode->right = buildTreeUsingIP(in, pre, inoIdx + 1, ie, n);
    return newNode;
}

int minSwaps(Node *root, int n)
{
    int bt[n];
    getInorder(root, bt, n);
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = {bt[i], i};
    sort(arr, arr + n);
    bool vis[n];
    memset(vis, 0, n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arr[i].second == i)
            continue;
        int cycle_size = 0, j = i;
        while (!vis[j])
        {
            vis[j] = true;
            j = arr[j].second;
            cycle_size++;
        }
        if (cycle_size > 0)
            ans += (cycle_size - 1);
    }
    return ans;
}

bool isLeafNode(Node *node)
{
    if (!node)
        return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

bool isSumTree(Node *root)
{
    if (!root || isLeafNode(root))
        return true;
    int ls = 0, rs = 0;
    if (isSumTree(root->left) || isSumTree(root->right))
    {
        if (root->left == NULL)
            ls = 0;
        else if (isLeafNode(root->left))
            ls = root->left->data;
        else
            ls = 2 * root->left->data;
        if (root->right == NULL)
            rs = 0;
        else if (isLeafNode(root->right))
            rs = root->right->data;
        else
            rs = 2 * root->right->data;
        return (root->data == ls + rs);
    }
    return false;
}

int sumOfLongestPathfromRoot(Node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int l = sumOfLongestPathfromRoot(root->left, &lh);
    int r = sumOfLongestPathfromRoot(root->right, &rh);
    *height = ((lh > rh) ? lh : rh) + 1;
    if (lh > rh)
        return l + root->data;
    else if (lh < rh)
        return r + root->data;
    else
        return ((l > r) ? l : r) + root->data;
}

int maxSum(Node *root)
{
    if (!root)
        return 0;
    return max(maxSum(root->left), maxSum(root->right)) + root->data;
}

// Maximum sum of nodes in Binary tree such that no two are adjacent
//Method 1
int sumOfGrandChildren(Node *node);
int getMaxSumUtil(Node *node, map<Node *, int> &mp);
int getMaxSum(Node *node);
int sumOfGrandChildren(Node *root, map<Node *, int> &mp)
{
    int sum = 0;
    if (root->left)
        sum += getMaxSumUtil(root->left->left, mp) + getMaxSumUtil(root->left->right, mp);
    if (root->right)
        sum += getMaxSumUtil(root->right->left, mp) + getMaxSumUtil(root->right->right, mp);
    return sum;
}
int getMaxSumUtil(Node *root, map<Node *, int> &mp)
{
    if (root == NULL)
        return 0;
    if (mp.find(root) != mp.end())
        return mp[root];
    int inc = root->data + sumOfGrandChildren(root, mp);
    int exl = getMaxSumUtil(root->left, mp) + getMaxSumUtil(root->right, mp);
    mp[root] = max(inc, exl);
    return mp[root];
}
int getMaxSum(Node *root)
{
    if (!root)
        return 0;
    map<Node *, int> mp;
    return getMaxSumUtil(root, mp);
}
//Method 2
pair<int, int> maxSumUtil(Node *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> sum1 = maxSumUtil(root->left);
    pair<int, int> sum2 = maxSumUtil(root->right);
    pair<int, int> sum;
    //first = included
    //second = not included
    sum.first = sum1.second + sum2.second + root->data;
    sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);
    return sum;
}
int getMaxSum2(Node *root)
{
    pair<int, int> res = maxSumUtil(root);
    return max(res.first, res.second);
}
// Lowest Common Ancestor in a Binary Tree

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);
    if (left && right)
        return root;
    return (left) ? left : right;
}
int findLCA(Node *root, int n1, int n2)
{
    if (!root)
        return INT_MAX;
    if (search(root, n1) && search(root, n2))
    {
        Node *lcaN = lca(root, n1, n2);
        return lcaN->data;
    }
    return INT_MAX;
}

bool kthAncestor(Node *root, int data, int &k, int &ancestor)
{
    if (!root)
        return false;
    if (root->data == data)
    {
        k--;
        return true;
    }
    bool left = kthAncestor(root->left, data, k, ancestor);
    if (left)
    {
        if (k == 0)
            ancestor = root->data, k--;
        else if (k > 0)
            k--;
        return true;
    }
    bool right = kthAncestor(root->right, data, k, ancestor);
    if (right)
    {
        if (k == 0)
            ancestor = root->data, k--;
        else if (k > 0)
            k--;
        return true;
    }
    return false;
}

bool isBST(Node *root)
{
    if (!root)
        return false;
    if (root->left && root->left->data >= root->data)
        return false;
    if (root->right && root->right->data <= root->data)
        return false;
    return (isBST(root->left) && isBST(root->right));
}

int main()
{
    bt tree;
    int n, data, height = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        tree.insert(data);
    }
    tree.toBST();
    tree.inorder();
}