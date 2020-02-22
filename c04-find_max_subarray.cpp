#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <climits>
#include <vector>
using namespace std;

tuple<int, int, int> FindMaxCrossingSubarray(const vector<int> &arr, int low, int mid, int high)
{
	int left_index = mid, right_index = mid + 1;
	int tmp, left_sum = INT_MIN, right_sum = INT_MIN;

	// calc max left
	tmp = 0;
	for (int i = mid; i >= low; i--)
	{
		tmp += arr[i];
		if (tmp > left_sum)
		{
			left_sum = tmp;
			left_index = i;
		}
	}

	// calc max right
	tmp = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		tmp += arr[i];
		if (tmp > right_sum)
		{
			right_sum = tmp;
			right_index = i;
		}
	}
	return make_tuple(left_index, right_index, left_sum + right_sum);
}

tuple<int, int, int> FindMaxSubarray(const vector<int> &arr, int low, int high)
{
	if (low == high)
	{
		return make_tuple(low, high, arr[low]);
	}
	int mid = (low + high) / 2;
	int llow, lhigh, lsum, mlow, mhigh, msum, rlow, rhigh, rsum;
	tie(llow, lhigh, lsum) = FindMaxSubarray(arr, low, mid);
	tie(mlow, mhigh, msum) = FindMaxCrossingSubarray(arr, low, mid, high);
	tie(rlow, rhigh, rsum) = FindMaxSubarray(arr, mid + 1, high);
	if (lsum >= msum && lsum >= rsum)
	{
		return make_tuple(llow, lhigh, lsum);
	}
	else if (msum >= lsum && msum >= rsum)
	{
		return make_tuple(mlow, mhigh, msum);
	}
	else
	{
		return make_tuple(rlow, rhigh, rsum);
	}
}

int main()
{
	string line;
	cout << "Enter a price sequence:(must contain positive number) " << endl;
	getline(cin, line);
	istringstream iss(line);

	int input;
	vector<int> arr;
	while (iss >> input)
	{
		arr.push_back(input);
	}

	int low, high, sum;
	tie(low, high, sum) = FindMaxSubarray(arr, 0, arr.size() - 1);
	cout << "Max sum: " << sum << " at (" << low << ", " << high << ")" << endl;
}