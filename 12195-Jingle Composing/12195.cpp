#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;

	while (cin >> str && str != "*")
	{
		int num = 0, duration = 0;
		for (int i = 1; i < str.size(); ++i)
		{
			if (str[i] == '/')
			{
				if (duration == 64)
					num++;
				duration = 0;
			}
			else if (str[i] == 'W')
				duration += 64;
			else if (str[i] == 'H')
				duration += 32;
			else if (str[i] == 'Q')
				duration += 16;
			else if (str[i] == 'E')
				duration += 8;
			else if (str[i] == 'S')
				duration += 4;
			else if (str[i] == 'T')
				duration += 2;
			else if (str[i] == 'X')
				duration += 1;
		}
		cout << num << endl;
	}
	system("pause");
}