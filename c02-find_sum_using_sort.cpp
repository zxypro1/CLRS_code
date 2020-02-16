#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool FindSum(vector<int>& arr, int sum)
{
	sort(arr.begin(), arr.end());
	size_t i = 0, j = arr.size() - 1;
	while (j > i)
	{
		if (arr[i] + arr[j] < sum)
		{
			i++;
		}
		else if (arr[i] + arr[j] > sum)
		{
			j--;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//int main()
//{
//	vector<int> arr{ 9,7,6,4,8,3,8,11,29,0,99 };
//	cout << FindSum(arr, 40) << ' ' << FindSum(arr, 1) << endl;
//}