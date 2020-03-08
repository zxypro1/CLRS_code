#include "common.h"
using namespace std;
const int BUCKET_NUM = 10;

struct Node
{
    int val;
    Node *next;

    Node(int i = 0) : val(i), next(NULL) {}
};

vector<Node *> buckets(BUCKET_NUM, nullptr);

void Insert(int i, int val)
{
    Node *newNode = new Node(val);
    if (buckets[i] == nullptr)
    {
        buckets[i] = newNode;
    }
    else
    {
        Node *pre = nullptr;
        Node *cur = buckets[i];
        while (cur != nullptr && cur->val < val)
        {
            pre = cur;
            cur = cur->next;
        }
        newNode->next = cur;
        if (pre == nullptr)
        {
            buckets[i] = newNode;
        }
        else
        {
            pre->next = newNode;
        }
    }
}

void BucketSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int index = arr[i] / BUCKET_NUM;
        Insert(index, arr[i]);
    }

    int index = 0;
    Node *tmp = nullptr;
    for (int i = 0; i < BUCKET_NUM; ++i)
    {
        Node *cur = buckets.at(i);
        while (cur != nullptr)
        {
            arr[index++] = cur->val;
            tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
}

int main()
{
    vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
    Print(arr);
    BucketSort(arr);
    Print(arr);
}
