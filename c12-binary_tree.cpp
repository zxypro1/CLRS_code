#include <iostream>
#include <vector>
#include <stack>
#include "common.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class OrderedBinaryTree
{
    Node *root = nullptr;

public:
    OrderedBinaryTree() {}
    OrderedBinaryTree(const vector<int> &li)
    {
        for (int i : li)
        {
            this->insert(i);
        }
    }

    ~OrderedBinaryTree()
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

    void insert(int x)
    {
        if (root == nullptr)
        {
            root = new Node(x);
        }
        else
        {
            Node *newNode = new Node(x);
            Node *cur = root;
            Node *parent;
            while (cur != nullptr)
            {
                parent = cur;
                cur = cur->data > x ? cur->left : cur->right;
            }
            if (parent->data > x)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            }
        }
    }

    bool find(int x)
    {
        Node *cur = root;
        while (cur != nullptr)
        {
            if (cur->data == x)
            {
                return true;
            }
            cur = cur->data > x ? cur->left : cur->right;
        }
        return false;
    }

    Node *max(Node *r = nullptr)
    {
        if (r == nullptr)
        {
            r = root;
        }
        Node *tmp = r;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
        return tmp;
    }

    Node *min(Node *r = nullptr)
    {
        if (r == nullptr)
        {
            r = root;
        }
        Node *tmp = r;
        while (tmp->left)
        {
            tmp = tmp->left;
        }
        return tmp;
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
};

int main()
{
    vector<int> li{7, 2, 3, 4, 5, 6, 1};
    OrderedBinaryTree tree(li);

    vector<int> res;
    tree.InOrder(res);
    Print(res);

    cout << tree.find(1) << ' ' << tree.find(9) << endl;
    cout << tree.max()->data << ' ' << tree.min()->data << endl;
}