#include <string>
#include <iostream>
#include <algorithm>

using std::string;

string BigNumAdd(string a, string b)
{
	string ans;
	int len1 = a.length(), len2 = b.length();
	int carry = 0, cur;
	int pos = 0;
	for (; pos < len1 && pos < len2; pos++)
	{
		cur = carry + a[len1 - 1 - pos] - '0' + b[len2 - 1 - pos] - '0';
		ans.push_back(cur % 10 + '0');
		carry = cur / 10;
	}
	for (; pos < len1; pos++)
	{
		cur = carry + a[len1 - 1 - pos] - '0';
		ans.push_back(cur % 10 + '0');
		carry = cur / 10;
	}
	for (; pos < len2; pos++)
	{
		cur = carry + b[len2 - 1 - pos] - '0';
		ans.push_back(cur % 10 + '0');
		carry = cur / 10;
	}
	if (carry != 0)
	{
		ans.push_back(carry + '0');
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	std::cout << BigNumAdd("99999999999999999999999", "8888888888888888888888888") << std::endl;
	return 0;
}