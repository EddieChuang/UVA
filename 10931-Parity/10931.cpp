#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int parity(int, string&);

int main() {

	int n;
	while (cin >> n && n)
	{
		string bin = "";
		int p = parity(n, bin);
		cout << "The parity of " << bin << " is " << p << " (mod 2)." << endl;
	}
	system("pause");
	return 0;
}

int parity(int n, string &bin)
{
	int p = 0;
	while (n)
	{
		if (n % 2)
			p++;
		bin += (n % 2) + '0';
		n /= 2;
	}
	reverse(bin.begin(), bin.end());
	return p;
}