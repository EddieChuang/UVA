#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{

	int a;
	int b;
	int c;
	int id;
	node(int x, int y, int z, int ID) : a(x), b(y), c(z), id(ID){}
};

int DFS(node);

vector<node> blocks;
vector<vector<node>> graph;
int *height;

int main(){

	int n, x, y, z, Case = 1;
	while (cin >> n && n)
	{
		blocks.clear();
		graph.clear();
		
		int ID = 0, max_height = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y >> z;
			blocks.push_back(node(x, y, z, ID++));
			if (x != y || y != z)
				blocks.push_back(node(y, z, x, ID++));
			if (y != x)
				blocks.push_back(node(x, z, y, ID++));
		}

		height = new int[ID];
		for (int i = 0; i < ID; ++i)
			height[i] = blocks[i].c;

		graph.resize(ID);

		for (int i = 0; i < blocks.size(); ++i)
		{
			int a1 = blocks[i].a, b1 = blocks[i].b;
			for (int j = 0; j < blocks.size(); ++j)
			{
				if (i == j)
					continue;
				int a2 = blocks[j].a, b2 = blocks[j].b;
				if ((a1 > a2 && b1 > b2) || (a1 > b2 && b1 > a2))
					graph[blocks[i].id].push_back(blocks[j]);
			}
		}

		for (int i = 0; i < blocks.size(); ++i)
			max_height = max(max_height, DFS(blocks[i]));
		
		cout << "Case " << Case++ << ": maximum height = " << max_height << endl;
	}
	return 0;
}

int DFS(node block)
{
	if (height[block.id] != block.c)
		return height[block.id];
	for (int i = 0; i < graph[block.id].size(); ++i)
		height[block.id] = max(height[block.id], block.c + DFS(graph[block.id][i]));
	return height[block.id];
}