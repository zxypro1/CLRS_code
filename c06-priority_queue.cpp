#include <vector>
using namespace std;

// 利用大根堆，实现优先队列
void heapify(vector<int>& arr, int pos, int max_index)
{
	// See c06-heap_sort.cpp for detail.
}

int Dequeue(vector<int>& arr)
{
	int ret = arr[0];
	arr[0] = arr[arr.size() - 1];
	heapify(arr, 0, arr.size() - 2);
	return ret;
}

void Enqueue(vector<int>& arr, int value)
{
	arr.push_back(INT_MIN);
	int pos = arr.size() - 1;
	int parent = (pos - 1) / 2;
	while (pos > 0 && arr[parent] < value)
	{
		arr[pos] = arr[parent];
		pos = parent;
		parent = (pos - 1) / 2;
	}
	arr[pos] = value;
}