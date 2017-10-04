#include <iostream>
using namespace std;

void cheapestBase(int*, int);

int main(){

	int t, n;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cout << "Case " << i << ":" << endl;
		int cost[36];
		for (int j = 0; j < 36; ++j)
			cin >> cost[j];

		cin >> n;

		cheapestBase(cost, n);
		if (i < t)
			cout << endl;

	}


	system("pause");
	return 0;
}

void cheapestBase(int *cost, int n)
{
	int query;
	while (n--)
	{
		cin >> query;

		int price[37] = { 0 };
		int min = 999999, number = query;
		for (int base = 2; base <= 36; ++base)
		{
			for (;number; number /= base)
				price[base] += cost[number%base];
			if (min > price[base])
				min = price[base];
			number = query;
		}

		cout << "Cheapest base(s) for number " << query << ":";
		for (int base = 2; base <= 36; ++base)
			if (min == price[base])
				cout << " " << base;
		cout << endl;

	}
}

