#include "common.h"
using namespace std;

void InsertSort(vector<int> &arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		// insert arr[i] to sorted arr[0] ~ arr[i-1]
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	return;
}

int main()
{
	vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
	InsertSort(arr);
	Print(arr);
}