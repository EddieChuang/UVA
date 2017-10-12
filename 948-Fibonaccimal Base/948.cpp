#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> fib_base{0, 1};
	for (int i = 2; fib_base[i - 1] <= 100000000; i++)
		fib_base.push_back(fib_base[i - 1] + fib_base[i - 2]);

	int n, number;
	cin >> n;
	while (n--)
	{
		cin >> number;
		int tmp = number;
		cout << number << " = ";
		for (int i = fib_base.size() - 1; i >= 2; --i)
		{
			if (fib_base[i] <= number)
			{
				cout << "1";
				number -= fib_base[i];
			}
			else if (fib_base[i] < tmp)
				cout << "0";
		}
		cout << " (fib)" << endl;
	}
	return 0;
}