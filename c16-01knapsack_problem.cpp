#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 5;

void KnapsackProblem(int num, int values[], int cost[], int capacity)
{
    int dp[capacity + 1];
    for (int i = 0; i <= capacity; i++)
    {
        dp[i] = 0; // 求最大值，而不是恰巧装满
    }

    for (int i = 0; i < num; i++) // 前i件物品，放入背包时的最大价值
    {
        for (int j = capacity; j >= cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + values[i]); // 状态转移方程
        }
    }

    cout << dp[capacity] << endl;
}

int main()
{
    int num = 5, capacity = 15;
    vector<int> value{4, 2, 2, 1, 10};
    vector<int> cost{12, 2, 1, 1, 4};
    KnapsackProblem(num, value.data(), cost.data(), capacity); // 15
}
