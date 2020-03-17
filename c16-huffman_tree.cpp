#include <iostream>
#include <queue>
#include <stack>
#include "common.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
    Node(int d, Node *l, Node *r) : data(d), left(l), right(r) {}

    bool operator<(const Node &r) const
    {
        return this->data < r.data;
    }
};

class NodeComparator
{
public:
    int operator()(const Node *n1, const Node *n2)
    {
        return n1->data > n2->data;
    }
};

class HuffmanTree
{
public:
    Node *root = nullptr;
    HuffmanTree(const vector<int> &li)
    {
        priority_queue<Node *, vector<Node *>, NodeComparator> minHeap;
        for (int i : li)
        {
            minHeap.push(new Node(i));
        }
        while (minHeap.size() > 1)
        {
            Node *a = minHeap.top();
            minHeap.pop();
            Node *b = minHeap.top();
            minHeap.pop();
            Node *parent = new Node(a->data + b->data, a, b);
            minHeap.push(parent);
        }
        this->root = minHeap.top();
        minHeap.pop();
    }

    ~HuffmanTree()
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
};

int main()
{
    vector<int> seq{1, 1, 2, 3, 5, 8, 13, 21};
    HuffmanTree t(seq);

    std::cout << t.root->left->data << std::endl;
    std::cout << t.root->right->left->data << std::endl;
    std::cout << t.root->right->right->left->data << std::endl;
}
