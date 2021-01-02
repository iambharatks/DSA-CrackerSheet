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
//Print all paths from root to leaf
void printPathsfromRootToLeaf(Node *root, vector<int> curPath, vector<vector<int>> &paths)
{
    if (!root)
        return;
    curPath.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
        paths.push_back(curPath);
    else
    {
        printPathsfromRootToLeaf(root->left, curPath, paths);
        printPathsfromRootToLeaf(root->right, curPath, paths);
    }
}

// Print all the paths from root, with a specified sum in Binary tree
void printPath(vector<int> path)
{
    for (int i : path)
        cout << i << " ";
    cout << endl;
}
void printPathsForSumFromRoot(Node *root, int sum, int &target, vector<int> path)
{
    if (!root)
        return;
    sum += root->data;
    path.push_back(root->data);
    if (sum == target)
        printPath(path);
    printPathsForSumFromRoot(root->left, sum, target, path);
    printPathsForSumFromRoot(root->right, sum, target, path);
}

void printPath(vector<int> path, int start)
{
    for (int i = start; i < path.size(); ++i)
        cout << path[i] << " ";
    cout << endl;
}
void printkSumPath(Node *root, int sum, int &target, vector<int> path)
{
    if (!root)
        return;
    sum += root->data;
    path.push_back(root->data);
    if (sum == target)
        printPath(path);
    int leftSum = 0;
    for (int i = 0; i < path.size() - 1; i++)
    {
        leftSum += path[i];
        if (sum - leftSum == target)
            printPath(path, i + 1);
    }
    printkSumPath(root->left, sum, target, path);
    printkSumPath(root->right, sum, target, path);
}

int main()
{
    bt tree;
    int n;
    int data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        tree.insert(data);
    }
    vector<int> curPath;
    int target = 5;
    printkSumPath(tree.root, 0, target, curPath);
}
//1(3(2)(1(1)))(-1(4(1)(2))(5(6)))