#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){

	string n;
	while (cin >> n && n != "0")
	{
		int odd = 0, even = 0;
		for (int i = 0; i < n.size(); ++i)
		{
			if ((i + 1) % 2)
				odd += n[i] - '0';
			else
				even += n[i] - '0';
		}
		if (abs(odd - even) % 11 == 0)
			cout << n << " is a multiple of 11." << endl;
		else
			cout << n << " is not a multiple of 11." << endl;
	}
	return 0;
}