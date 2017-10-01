#include <iostream>
using namespace std;

int threeN(int);
void swap(int&, int&);

int main(){

	int i, j;
	while (cin >> i >> j)
	{
		int origin_i = i, origin_j = j;
		if (i > j)
			swap(i, j);

		int max = 0;
		for (int n = i; n <= j; ++n)
		{
			int count = threeN(n);
			max = (count > max) ? count : max;
		}
		cout << origin_i << " " << origin_j << " " << max << endl;
	}
	return 0;
}

int threeN(int n)
{
	if (n == 1)
		return 1;
	if (n % 2 == 1)
		return threeN(3 * n + 1) + 1;
	return threeN(n / 2) + 1;
}

void swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}