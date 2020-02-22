#include "common.h"

using namespace std;

void QuickSort(vector<int> &nums, int l, int r)
{
	if (l >= r)
		return;
	int i = l; // cursor for final pivot location
	for (int j = l; j <= r - 1; j++)
	{ // nums[r] is chosen as the pivot
		if (nums[j] <= nums[r])
		{
			swap(nums[i], nums[j]);
			i++; // smaller or equal elements go to the left of i
		}
	}
	Swap(nums[i], nums[r]); // after swap, the pivot is nums[i]
	QuickSort(nums, l, i - 1);
	QuickSort(nums, i + 1, r);
}

int main()
{

	vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
	Print(arr);
	QuickSort(arr, 0, arr.size() - 1);
	cout << "After sorted:" << endl;
	Print(arr);
}
