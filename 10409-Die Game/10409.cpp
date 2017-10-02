#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	while (cin >> n && n)
	{
		int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6;
		string move;
		while (n-- && cin >> move)
		{
			int tmp;
			if (move == "north")
			{
				tmp = top; top = south; south = bottom; bottom = north; north = tmp;
			}
			else if (move == "south")
			{
				tmp = top; top = north; north = bottom; bottom = south; south = tmp;
			}
			else if (move == "east")
			{
				tmp = top; top = west; west = bottom; bottom = east; east = tmp;
			}
			else if (move == "west")
			{
				tmp = top; top = east; east = bottom; bottom = west; west = tmp;
			}
		}
		cout << top << endl;
	}
	return 0;
}