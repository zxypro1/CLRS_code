#include <vector>
#include "common.h"

using namespace std;

void MaxRotCutEarning(int length, const vector<int> &price, vector<int> &memo, vector<int> &solution)
{
    for (int i = 1; i <= length; i++)
    {
        int income = -1;
        for (int j = 1; j <= i; j++)
        {
            if (income < price[j] + memo[i - j])
            {
                income = price[j] + memo[i - j];
                solution[i] = j;
            }
        }
        memo[i] = income;
    }
}

int main()
{
    vector<int> price{0, 1, 5, 8, 9, 10, 17, 17, 20, 24};
    int length = price.size() - 1;
    vector<int> memo(length + 1, 0);
    vector<int> solution(length + 1, 0);
    MaxRotCutEarning(length, price, memo, solution);
    Print(memo);
    while (length > 0)
    {
        cout << solution[length] << endl;
        length -= solution[length];
    }
}