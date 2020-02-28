#include "common.h"
#include <cassert>
#include <algorithm>
using namespace std;

int QuickSelection(vector<int> &nums, int l, int r, int rank)
{
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
    if (i == rank)
    {
        return nums[i];
    }
    else if (i > rank)
    {
        return QuickSelection(nums, l, i - 1, rank);
    }
    else
    {
        return QuickSelection(nums, i + 1, r, rank - i - 1);
    }
}

int main()
{
    vector<int> arr{9, 7, 6, 4, 8, 3, 8, 11, 29, 0, 99};
    vector<int> arryCopy(arr);
    sort(arryCopy.begin(), arryCopy.end());
    for (int i = 0; i < arr.size(); i++)
    {
        assert(QuickSelection(arr, 0, arr.size() - 1, i) == arryCopy[i]);
    }
    return 0;
}
