#include "common.h"
#include <algorithm>
using namespace std;

void CountingSort(const vector<int> &nums, vector<int> &sorted)
{
    int min_n = *min_element(nums.begin(), nums.end());
    int max_n = *max_element(nums.begin(), nums.end());
    vector<int> count_arr(max_n - min_n + 1, 0);
    for (int n : nums)
    {
        count_arr[n - min_n]++;
    }
    for (int i = 1; i < count_arr.size(); i++)
    {
        count_arr[i] += count_arr[i - 1];
    }
    for (int n : nums)
    {
        sorted[--count_arr[n - min_n]] = n;
    }
}

int main()
{

    vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
    vector<int> sorted(arr.size(), 0);
    Print(arr);
    CountingSort(arr, sorted);
    Print(sorted);
}
