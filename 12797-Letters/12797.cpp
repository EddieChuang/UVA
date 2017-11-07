#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int direction[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };  //down, right, up, left
char park[100][100];

vector<vector<bool>> allPath;
vector<bool> path(256, false);



//void shortest(int path[100][100], set<int> letter, int x, int y);
void setAllPath(int i);
void DFS(vector<bool> path, int distance[100][100], int x, int y);

int main() {

	fstream output("output.txt", ios::out);
	
	setAllPath(0);
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> park[i][j];
		
		int ans = 10001;
		int  distance[100][100];
		for (int i = 0; i < allPath.size(); ++i)
		{
			memset(distance, 10001, sizeof(int) * 10000);
			distance[0][0] = 1;

			DFS(allPath[i], distance, 0, 0);
			ans = min(distance[n - 1][n - 1], ans);
		}
		
		if (ans == 10001)
			output << -1 << endl;
		else
			output << ans << endl;
	}
	output.close();
}

void setAllPath(int i)
{
	if (i == 10)
	{
		allPath.push_back(path);
		return;
	}

	path['a' + i] = true;
	setAllPath(i + 1);
	path['a' + i] = false;

	path['A' + i] = true;
	setAllPath(i + 1);
	path['A' + i] = false;
}

void DFS(vector<bool> path, int distance[100][100], int x, int y)
{
	if (!path[park[x][y]])
		return;

	for (int i = 0; i < 4; ++i)
	{
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && path[park[next_x][next_y]])
		{
			if (distance[next_x][next_y] >= distance[x][y] + 1)
			{
				distance[next_x][next_y] = distance[x][y] + 1;
				DFS(path, distance, next_x, next_y);
			}
		}
	}
}

/*
void shortest(int path[100][100], set<int> letter, int x, int y)
{
	letter.insert(park[x][y]);
	
	for (int i = 0; i < 4; ++i)
	{
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		char c = park[next_x][next_y];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n)
		{
			if (((isupper(c) && letter.count(tolower(c)) == 0)||(islower(c) && letter.count(toupper(c)) == 0))
				 && path[next_x][next_y] >= path[x][y] + 1)
			{
				path[next_x][next_y] = path[x][y] + 1;
				shortest(path, letter, next_x, next_y);
			}
		}
	}
}*/