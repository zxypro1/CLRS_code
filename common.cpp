#include <iostream>
#include "common.h"

using std::cout;
using std::endl;

void Print(const vector<int>& v)
{
	for (int i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
}