#include <iostream>
using namespace std;

long long maxProduct(int*, int);

int main(){

	int n, Case = 1;
	while (cin >> n)
	{
		int *seq = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> seq[i];

		cout << "Case #" << Case << ": The maximum product is " << maxProduct(seq, n) << "." << endl << endl;
		Case++;
	}
	return 0;
}

long long maxProduct(int *seq, int n)
{
	long long max = 0, product;
	for (int i = 0; i < n; ++i)
	{
		product = 1;
		for (int j = i; j < n; ++j)
		{
			product *= seq[j];
			if (max < product)
				max = product;
		}
	}
	return max;
}