#include <iostream>
using namespace std;

int summingDigits(int);

int main() {

	int n;
	while (cin >> n && n)
		cout << summingDigits(n) << endl;
	return 0;
}

int summingDigits(int n)
{
	if (n / 10 == 0)
		return n;

	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return summingDigits(sum);
}