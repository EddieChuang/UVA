#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>, int, bool*, vector<int>&);

int main(){

	int m, n;
	while (cin >> n >> m && (n || m))
	{
		vector<vector<int>> graph(n + 1);
		vector<int> ans;

		bool *visit = new bool[n + 1];
		bool *connected = new bool[n + 1];
		for (int i = 1; i <= n; ++i)
			*(visit + i) = *(connected + i) = false;

		while (m--)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			*(connected + v) = true;
		}

		for (int i = 1; i <= n; ++i)
			if (!*(connected + i))   //root
				DFS(graph, i, visit, ans);
		
		for (vector<int>::iterator it = ans.end() - 1; it != ans.begin(); --it)
			cout << *it << " ";
		cout << *ans.begin() << endl;
	}
	return 0;
}

void DFS(vector<vector<int>> graph, int i, bool *visit, vector<int> &ans)
{
	if (*(visit + i))
		return;
	*(visit + i) = true;

	//for (int index : graph[i])
	for (int j = 0; j < graph[i].size(); ++j)
		DFS(graph, graph[i][j], visit, ans);
	ans.push_back(i);
}