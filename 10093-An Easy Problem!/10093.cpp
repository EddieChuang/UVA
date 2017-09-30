#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> nBase;
int easyProblem(int, int);

int main() {

	for (int i = 0; i < 10; ++i)
		nBase['0' + i] = i;
	for (int i = 0; i < 26; ++i)
	{
		nBase['A' + i] = i + 10;
		nBase['a' + i] = i + 36;
	}

	string r;
	while (cin >> r)
	{
		int minBase = 2, sum = 0;
		for (int i = 0; i < r.size(); ++i)
		{
			sum += nBase[r[i]];
			if (minBase <= nBase[r[i]])
				minBase = nBase[r[i]] + 1;
		}
		int ans = easyProblem(sum, minBase);
		if (ans != -1)
			cout << ans << endl;
		else
			cout << "such number is impossible!" << endl;
	}
	return 0;
}

int easyProblem(int sum, int minBase)
{
	for (int i = minBase; i <= 62; ++i)
		if (sum % (i - 1) == 0)
			return i;
	return -1;
}