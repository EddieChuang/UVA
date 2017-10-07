#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void flip(vector<int>&, int, int);

int main(){

	string str;
	while (getline(cin, str))
	{
		stringstream ss(str);
		vector<int> stack;
		
		int jack, i = 0;
		while (ss >> jack)
			stack.push_back(jack);

		for (int i = 0; i < stack.size(); ++i)
			cout << stack[i] << " ";
		cout << endl;

		while (!is_sorted(stack.begin(), stack.end()))
		{
			int n = max_element(stack.begin(), stack.end() - i) - stack.begin();
			flip(stack, n, i++);
		}
		cout << 0 << endl;

	}
	return 0;
}

void flip(vector<int> &stack, int n, int i)
{
	if (n != 0)
	{
		reverse(stack.begin(), stack.begin() + n + 1);
		cout << stack.size() - n << " ";
	}
	reverse(stack.begin(), stack.end() - i);
	cout << i + 1 << " ";
}