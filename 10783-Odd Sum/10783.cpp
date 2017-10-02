#include <iostream>
using namespace std;

int main() {

	int t;
	cin >> t;

	for(int n = 1; n <= t; ++n)
	{
		int x, y;
		cin >> x >> y;

		int sum = 0;
		for (int i = x; i <= y; ++i)
			if (i % 2)
				sum += i;
		cout << "Case " << n << ": " << sum << endl;
	}
	return 0;
}