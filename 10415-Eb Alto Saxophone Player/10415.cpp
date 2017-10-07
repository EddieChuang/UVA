#include <iostream>
#include <map>
using namespace std;

int main(){

	map<char, string> table;
	table['c'] = "0111001111";
	table['d'] = "0111001110";
	table['e'] = "0111001100";
	table['f'] = "0111001000";
	table['g'] = "0111000000";
	table['a'] = "0110000000";
	table['b'] = "0100000000";
	table['C'] = "0010000000";
	table['D'] = "1111001110";
	table['E'] = "1111001100";
	table['F'] = "1111001000";
	table['G'] = "1111000000";
	table['A'] = "1110000000";
	table['B'] = "1100000000";

	int t;
	cin >> t;
	cin.get(); //cin.ignore();
	while (t--)
	{
		char c;
		int count[10] = { 0 }, curr[10] = { 0 };
		while (cin.get(c) && c != '\n')
		{
			for (int i = 0; i < 10; ++i)
			{
				if (curr[i] == 0 && table[c][i] == '1')
					count[i]++;
				curr[i] = table[c][i] - '0';
			}
		}

		cout << count[0];
		for (int i = 1; i < 10; ++i)
			cout << " " << count[i];
		cout << endl;
	}
	return 0;
}