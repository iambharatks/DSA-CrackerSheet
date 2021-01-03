#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
const char MARKER = '$';
class Node
{
public:
    char data;
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
    void insert(char data)
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
    root = new Node(str[si]);
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

//Tree Matching O(n*n)
bool areIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return ((root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
}
bool sInT(Node *root1, Node *root2)
{
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;
    if (areIdentical(root1, root2))
        return true;
    return (sInT(root1->left, root2) || sInT(root1->right, root2));
}

//Tree Matching In O(n)
void getInorder(Node *root, char *inorder, int &i)
{
    if (root == NULL)
        return;
    getInorder(root->left, inorder, i);
    inorder[i++] = root->data;
    getInorder(root->right, inorder, i);
}
void getPreorder(Node *root, char *preorder, int &i)
{
    if (root == NULL)
        return;
    getInorder(root->left, preorder, i);
    preorder[i++] = root->data;
    getInorder(root->right, preorder, i);
}
bool isSubtree(Node *root1, Node *root2)
{
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;
    int m = 0, n = 0;
    char in1[MAX], in2[MAX];
    getInorder(root1, in1, n);
    getInorder(root2, in2, m);
    in1[n] = '\0';
    in2[m] = '\0';
    if (strstr(in1, in2) == NULL)
        return false;
    m = 0, n = 0;
    char pr1[MAX], pr2[MAX];
    getInorder(root1, pr1, n);
    getInorder(root2, pr2, m);
    pr1[n] = '\0';
    pr2[m] = '\0';
    return (strstr(pr1, pr2) != NULL);
}

string dupSubUtil(Node *root, unordered_set<string> &subtrees)
{
    string s = "";
    if (root == NULL)
        return s + MARKER;
    string lstr = dupSubUtil(root->left, subtrees);
    if (lstr.compare(s) == 0)
        return s;
    string rstr = dupSubUtil(root->right, subtrees);
    if (rstr.compare(s) == 0)
        return s;
    s = s + root->data + lstr + rstr;
    if (s.length() > 3 && subtrees.find(s) != subtrees.end())
        return "";
    subtrees.insert(s);
    return s;
}

// Duplicate Subtrees
string dupTrees(Node *root, map<string, int> &mp)
{
    if (!root)
        return "";
    string s = "(";
    s += dupTrees(root->left, mp);
    s += to_string(root->data);
    s += dupTrees(root->right, mp);
    s += ")";
    if (mp[s] == 1)
        mp[to_string(root->data)] = -1;
    mp[s]++;
    return s;
}
void printAllDups(Node *root)
{
    // Code here
    map<string, int> mp;
    dupTrees(root, mp);
    int cnt = 0;
    for (auto i : mp)
        if (i.second == -1)
        {
            cout << i.first << " ";
            cnt++;
        }
    if (cnt == 0)
        cout << -1 << " ";
}

int main()
{
    string s;
    cin >> s;
    bt t;
    t.root = treeFromString(t.root, s, 0, s.size() - 1);
    t.inorder();
    cout << endl;
    printAllDups(t.root);
}