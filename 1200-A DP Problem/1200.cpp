#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct expression {

	int x;
	int constant;
};

int main() {

	int t;
	cin >> t;
	while (t--)
	{
		string expression;
		cin >> expression;

		double x = 0, constant = 0;
		int sign = 1, digit = 0, lhs = 1, length = expression.size();
		for (int i = 0; i <= length; ++i)
		{
			if (i < length && expression[i] >= '0' && expression[i] <= '9')
				digit++;
			else 
			{
				if (i < length && expression[i] == 'x')
					x += digit==0 ? 1 * lhs *sign : lhs * sign * stoi(expression.substr(i - digit, i));
				else if(digit != 0)
					constant += lhs * sign * stoi(expression.substr(i - digit, i));
				digit = 0;
			
				if (i < length && expression[i] == '-')
					sign = -1;
				else if (i < length && expression[i] == '+')
					sign = 1;		
				else if (i < length && expression[i] == '=')
				{
					sign = 1;
					lhs = -1;
				}
			}
		}
		if (x == 0 && constant != 0)
			cout << "IMPOSSIBLE" << endl;
		else if (x == 0 && constant == 0)
			cout << "IDENTITY" << endl;
		else
			cout << floor((-constant) / x) << endl;
	}
	return 0;
}