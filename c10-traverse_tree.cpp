#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "common.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    Node *root = nullptr;

public:
    BinaryTree() {}
    BinaryTree(const vector<int> &li)
    {
        if (li.size() < 1)
        {
            return;
        }
        root = new Node(li[0]);
        queue<Node *> que;
        que.push(root);
        for (int i = 1; i < li.size(); i++)
        {
            Node *cur = new Node(li[i]);
            if (que.front()->left == nullptr)
            {
                que.front()->left = cur;
            }
            else
            {
                que.front()->right = cur;
                que.pop();
            }
            que.push(cur);
        }
    }

    ~BinaryTree()
    {
        stack<Node *> s;
        Node *cur = root;
        Node *tmp;
        while (s.size() > 0 || cur != nullptr)
        {
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            tmp = s.top();
            s.pop();
            cur = tmp->right;
            delete tmp;
        }
        root = nullptr;
    }

    void LevelOrder(vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        queue<Node *> que;
        que.push(root);
        Node *cur;
        while (que.size() > 0)
        {
            cur = que.front();
            res.push_back(cur->data);
            que.pop();
            if (cur->left != nullptr)
            {
                que.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                que.push(cur->right);
            }
        }
    }

    void PreOrder(vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> s;
        s.push(root);

        Node *cur;
        while (s.size() > 0)
        {
            cur = s.top();
            s.pop();
            res.push_back(cur->data);
            if (cur->right)
            {
                s.push(cur->right);
            }

            if (cur->left)
            {
                s.push(cur->left);
            }
        }
    }

    void InOrder(vector<int> &res)
    {
        stack<Node *> s;
        Node *cur = root;
        while (s.size() > 0 || cur != nullptr)
        {
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            res.push_back(s.top()->data);
            cur = s.top()->right;
            s.pop();
        }
    }

    void PostOrder(vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<Node *> s;
        s.push(root);

        Node *cur;
        while (s.size() > 0)
        {
            cur = s.top();
            s.pop();
            res.push_back(cur->data);
            if (cur->left)
            {
                s.push(cur->left);
            }

            if (cur->right)
            {
                s.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
    }
};

int main()
{
    vector<int> li{1, 2, 3, 4, 5, 6, 7};
    BinaryTree tree(li);
    vector<int> res;

    tree.LevelOrder(res);
    Print(res);
    res.clear();

    tree.PreOrder(res);
    Print(res);
    res.clear();

    tree.InOrder(res);
    Print(res);
    res.clear();

    tree.PostOrder(res);
    Print(res);
    res.clear();
}