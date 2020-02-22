#include <iostream>
#include <tuple>
#include <random>
#include <algorithm>
#include "common.h"

using namespace std;

struct Interval // 区间定义
{
	int from;
	int to;

	Interval(int a, int b) : from(min(a, b)), to(max(a, b)) {}

	friend ostream &operator<<(ostream &os, const Interval &self)
	{
		os << "[" << self.from << ", " << self.to << "] ";
		return os;
	}
};

void FuzzQuickSort(vector<Interval> &arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	Interval pivot = arr[end];
	int p1 = start - 1, p2 = end + 1;
	int cur = start;
	while (cur < p2)
	{
		if (arr[cur].to < pivot.from)
		{
			p1++;
			Interval tmp = arr[cur];
			arr[cur] = arr[p1];
			arr[p1] = tmp;
			cur++;
		}
		else if (arr[cur].from > pivot.to)
		{
			p2--;
			Interval tmp = arr[cur];
			arr[cur] = arr[p2];
			arr[p2] = tmp;
		}
		else
		{ // 取交集，更新pivot，用核心区域（交集）保证有序
			pivot.from = max(arr[cur].from, pivot.from);
			pivot.to = min(arr[cur].to, pivot.to);
			cur++;
		}
	}

	// now [start, p1] < pivot (p1, p2) ≈ pivit [p2, end] > pivot
	FuzzQuickSort(arr, start, p1);
	FuzzQuickSort(arr, p2, end);
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr0_5(0, 5);
	std::uniform_int_distribution<int> distr0_9(0, 9);

	vector<Interval> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.emplace_back(Interval(distr0_5(gen), distr0_9(gen)));
	}
	Print(arr);
	FuzzQuickSort(arr, 0, arr.size() - 1);
	cout << "After fuzz sort: " << endl;
	Print(arr);
}
