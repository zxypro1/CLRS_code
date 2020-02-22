#include <vector>
#include "common.h"
using namespace std;

// 循环方式调整堆
void Heapify2(vector<int> &arr, int pos, int max_index)
{
	int left, right, tmp, max;
	while (true)
	{
		max = pos;
		left = 2 * pos + 1;
		right = 2 * pos + 2;
		if (left <= max_index && arr[left] > arr[max])
		{
			max = left;
		}
		if (right <= max_index && arr[right] > arr[max])
		{
			max = right;
		}
		if (max == pos)
		{
			break;
		}
		tmp = arr[pos];
		arr[pos] = arr[max];
		arr[max] = tmp;
		pos = max;
	}
}

// 递归方式调整堆
void Heapify(vector<int> &arr, int pos, int max_index)
{
	int left = 2 * pos + 1;
	int right = 2 * pos + 2;
	int max = pos;
	if (left <= max_index && arr[left] > arr[max])
	{
		max = left;
	}
	if (right <= max_index && arr[right] > arr[max])
	{
		max = right;
	}
	if (pos != max)
	{
		int tmp = arr[pos];
		arr[pos] = arr[max];
		arr[max] = tmp;
		Heapify(arr, max, max_index);
	}
}

void HeapSort(vector<int> &arr)
{
	// 建堆
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		Heapify(arr, i, arr.size() - 1);
	}

	// 排序
	int tmp;
	for (int i = arr.size() - 1; i >= 1; i--)
	{
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		Heapify2(arr, 0, i - 1);
	}
}

int main()
{
	vector<int> tmp{9, 8, 7, 6, 17, 1};
	HeapSort(tmp);
	Print(tmp);
}