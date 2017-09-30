#include <iostream>
#include <math.h>
using namespace std;

bool isJolly(int*, int);

int main() {

	int n;
	while (cin >> n)
	{
		int *sequence = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> sequence[i];
		if (isJolly(sequence, n))
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}

bool isJolly(int *sequence, int n)
{
	int *jolly = new int[n];
	for (int i = 0; i < n; ++i)
		jolly[i] = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		int diff = abs(sequence[i] - sequence[i + 1]);
		jolly[diff]++;
		if (diff >= n || diff <= 0 || jolly[diff] > 1)
			return false;
	}
	return true;
}