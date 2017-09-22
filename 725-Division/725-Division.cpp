#include <iostream>
#include <string>
using namespace std;

bool division(int);

int main(){

	int number, x = 0;
	while (cin >> number && number)
	{
		if (x++)
			cout << endl;
		if(!division(number))
			cout << "There are no solutions for " << number << ".\n";
	}
	return 0;
}

bool division(int number)
{
	string numerator = "", denominator = "";
	bool ans = false;
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (i == j)
				continue;
			for (int k = 0; k <= 9; ++k)
			{
				if (j == k || i == k)
					continue;
				for (int m = 0; m <= 9; ++m)
				{
					if (k == m || j == m || i == m)
						continue;
					for (int n = 0; n <= 9; ++n)
					{
						if (m == n || k == n || j == n || i == n)
							continue;
						denominator = to_string(i) + to_string(j) + to_string(k) + to_string(m) + to_string(n);
						numerator = to_string(stoi(denominator) * number);
						string str = numerator + denominator;
						if (numerator.length() == 5 && string::npos != str.find("0") && string::npos != str.find("1") && string::npos != str.find("2") && string::npos != str.find("3") && string::npos != str.find("4") &&
							string::npos != str.find("5") && string::npos != str.find("6") && string::npos != str.find("7") && string::npos != str.find("8") && string::npos != str.find("9"))
						{
							ans = true;
							cout << numerator << " / " << denominator << " = " << number << endl;
						}
					}
				}
			}

		}
	}
	return ans;
}