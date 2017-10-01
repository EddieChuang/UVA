#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define max 1000000

int prime[max] = { 0 };

int main(){

	for (int i = 2; i <= max; ++i)
		for (int j = i * 2; j <= max; j += i)
				prime[j] = 1;

	string n, tmp;
	while (cin >> n)
	{
		tmp = n;
		bool isPrime = prime[atoi(n.c_str())] == 0;

		reverse(n.begin(), n.end());

		bool isEmirp = tmp != n && prime[atoi(n.c_str())] == 0 && isPrime;
		reverse(n.begin(), n.end());
		if (isEmirp)
			cout << n << " is emirp." << endl;
		else if (isPrime)
			cout << n << " is prime." << endl;
		else
			cout << n << " is not prime." << endl;
	}
	return 0;
}