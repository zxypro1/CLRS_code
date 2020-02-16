#include "common.h"

void Merge(vector<int>& arr, int start, int mid, int end)
{
	// arr[end] is the last element.
	vector<int> left(arr.begin() + start, arr.begin() + mid + 1);
	vector<int> right(arr.begin() + mid + 1, arr.begin() + end + 1);

	size_t pos = start, i = 0, j = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			arr[pos++] = left[i++];
		}
		else
		{
			arr[pos++] = right[j++];
		}
	}
	while (i < left.size())
	{
		arr[pos++] = left[i++];
	}
	while (j < right.size())
	{
		arr[pos++] = right[j++];
	}
}

void MergeSort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

//int main()
//{
//	vector<int> arr{ 9,7,6,4,8,3,8,11,29,0,99 };
//	MergeSort(arr, 0, arr.size() - 1);
//	Print(arr);
//}