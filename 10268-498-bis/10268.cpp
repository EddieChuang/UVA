#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	long long int x, a;
	string line;
	while (cin >> x)
	{
		cin.ignore();
		getline(cin, line);
		stringstream ss(line);
		vector<long long int> polynomial;
		while (ss >> a)
			polynomial.push_back(a);
		long long int sum = 0, n = polynomial.size(), xp=1;
		for (int i = n - 2; i >= 0; --i, xp *= x)
			sum += polynomial[i] * (n - i - 1) * xp;

		cout << sum << endl;
	}
	return 0;
}