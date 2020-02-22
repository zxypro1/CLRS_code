#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool FindSum2(vector<int> &numbers, int target)
{
	bool found = false;
	unordered_set<int> s;
	for (int i : numbers)
	{
		s.insert(i);
	}
	for (int i : numbers)
	{
		if (s.find(target - i) != s.end())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
	cout << FindSum2(arr, 40) << ' ' << FindSum2(arr, 1) << endl;
}