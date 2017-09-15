#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>, int*, int);
void shortest_path(vector<vector<int>>, int*);
vector<int> ans;

int main(){

	int n, m;
	cin >> n >> m;
	vector<vector<int>> labyrinth(n+1, vector<int>(n+1, -1));
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (labyrinth[a][b] > c || labyrinth[a][b] == -1)
			labyrinth[a][b] = labyrinth[b][a] = c;
	}

	int *distance = new int[n + 1];
	for (int i = 0; i < n; ++i)
		distance[i] = -1;
	distance[n] = 0;
	
	shortest_path(labyrinth, distance);
	BFS(labyrinth, distance, 1);

	cout << ans.size() << endl;
	int room = 1;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << labyrinth[room][ans[i]] << " ";
		room = ans[i];
	}
	return 0;
}

void shortest_path(vector<vector<int>> labyrinth, int* distance)
{
	for (int i = labyrinth.size() - 1; i >= 1; --i)
		for (int j = 1; j <= i; ++j)
			if (labyrinth[i][j] != -1 && (distance[j] == -1 || distance[j] >= distance[i] + labyrinth[i][j]))
				distance[j] = distance[i] + labyrinth[i][j];
}

void BFS(vector<vector<int>> labyrinth, int* distance, int i)
{
	int min = -1, min_index;
	for (int j = i+1; j < labyrinth[i].size(); ++j)
	{
		if (labyrinth[i][j] == -1)
			continue;
		if (min == -1 || distance[j] < min)
		{
			min_index = j;
			min = distance[j];
		}
		else if (distance[j] == min && j < min_index)
			min_index = j;
	}
	
	if (i < labyrinth.size() - 1)
	{
		ans.push_back(min_index);
		BFS(labyrinth, distance, min_index);
	}
}