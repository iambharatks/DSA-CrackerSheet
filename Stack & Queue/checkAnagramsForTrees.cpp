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
//O(n) Appraoch
//Using levelOrder traversal
bool isAnagram(bt t1, bt t2)
{
    queue<Node *> q1, q2;
    Node *tmp1, *tmp2;
    q1.push(t1.root);
    q2.push(t2.root);
    q1.push(NULL);
    q2.push(NULL);
    unordered_map<int, int> mp1, mp2;
    while (!q1.empty() && !q2.empty())
    {
        tmp1 = q1.front();
        tmp2 = q2.front();
        q1.pop();
        q2.pop();
        if (!tmp1 && !tmp2)
        {
            if (!q1.empty() && !q2.empty())
            {
                q1.push(NULL);
                q2.push(NULL);
            }
            else if (!q1.empty() || !q2.empty())
                return false;
            for (auto i : mp1)
            {
                if (mp2[i.first] != i.second)
                    return false;
            }
            mp1.clear();
            mp2.clear();
        }
        else if (!tmp1 || !tmp2)
            return false;
        else
        {
            mp1[tmp1->data]++;
            mp2[tmp2->data]++;
            if (tmp1->left)
                q1.push(tmp1->left);
            if (tmp1->right)
                q1.push(tmp1->right);
            if (tmp2->left)
                q2.push(tmp2->left);
            if (tmp2->right)
                q2.push(tmp2->right);
        }
    }
}

int main()
{
}