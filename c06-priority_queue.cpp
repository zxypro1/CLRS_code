#include <cstdio>
#include <type_traits>
#include <vector>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// copy from c06-heap_sort.cpp
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

int Dequeue(vector<int> &arr)
{
	int ret = arr[0];
	arr[0] = arr[arr.size() - 1];
	Heapify(arr, 0, arr.size() - 2);
	return ret;
}

void Enqueue(vector<int> &arr, int value)
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

int main(int argc, const char** argv) {
	vector<int>obj;
	int j=0;
	while(cin>>j){
		obj.push_back(j);
	}
	Enqueue(obj,8);
}