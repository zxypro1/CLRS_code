#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "common.h"
using namespace std;

int LCSLength(const string &x, const string &y)
{
    vector<vector<int>> C(x.length() + 1, vector<int>(y.length() + 1, 0));
    for (int i = 0; i < x.length(); i++)
    {
        for (int j = 0; j < y.length(); j++)
        {
            if (x[i] == y[j])
            {
                C[i + 1][j + 1] = C[i][j] + 1;
            }
            else
            {
                C[i + 1][j + 1] = max(C[i][j + 1], C[i + 1][j]);
            }
        }
    }
    for (int i = 0; i < C.size(); i++)
    {
        Print(C[i]);
        cout << endl;
    }
    return C[x.length()][y.length()];
}

int main()
{
    cout << LCSLength("hsudujh", "hsuhsud1u") << endl;
}