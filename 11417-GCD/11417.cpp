#include <iostream>
using namespace std;

int GCD(int a, int b);

int main() {

	int n;
	while (cin >> n && n)
	{
		int G = 0;
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j <= n; ++j)
				G += GCD(i, j);

		cout << G << endl;
	}
	return 0;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}