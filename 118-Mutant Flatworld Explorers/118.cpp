#include <iostream>
#include <string>
using namespace std;

int main(){

	int n, m, x, y, i;
	char direction;
	cin >> n >> m;
	int scent[2500] = { 0 };
	while (cin >> x >> y >> direction)
	{
		string command;
		cin >> command;
		
		for (i = 0; i < command.size(); ++i)
		{
			if (direction == 'N')
			{
				if (command[i] == 'R')
					direction = 'E';
				else if (command[i] == 'L')
					direction = 'W';
				else if (command[i] == 'F' && y < m)
					y++;
				else if (!scent[y * n + x])
				{
					scent[y * n + x] = 1;
					break;
				}
			}
			else if (direction == 'E')
			{
				if (command[i] == 'R')
					direction = 'S';
				else if (command[i] == 'L')
					direction = 'N';
				else if (command[i] == 'F' && x < n)
					x++;
				else if (!scent[y * n + x])
				{
					scent[y * n + x] = 1;
					break;
				}
			}
			else if (direction == 'S')
			{
				if (command[i] == 'R')
					direction = 'W';
				else if (command[i] == 'L')
					direction = 'E';
				else if (command[i] == 'F' && y > 0)
					y--;
				else if (!scent[y * n + x])
				{
					scent[y * n + x] = 1;
					break;
				}
			}
			else if (direction == 'W')
			{
				if (command[i] == 'R')
					direction = 'N';
				else if (command[i] == 'L')
					direction = 'S';
				else if (command[i] == 'F' && x > 0)
					x--;
				else if (!scent[y * n + x])
				{
					scent[y * n + x] = 1;
					break;
				}
			}

		}

		cout << x << " " << y << " " << direction;
		if (i != command.size())
			cout << " LOST";
		cout << endl;
		
	}



	system("pause");
}