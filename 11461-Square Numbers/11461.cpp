#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int a, b;
	int square[100001] = { 0 };
	for (int i = 0; i <= sqrt(100000); ++i)
		square[int(pow(i, 2))] = 1;
	while (cin >> a >> b && (a || b))
	{
		int count = 0;
		for (int i = a; i <= b; ++i)
		{
			if (square[i])
				count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}