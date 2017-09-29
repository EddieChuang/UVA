#include <iostream>
#include <queue>
using namespace std;

struct node{

	int v[3];
	int dist;
	bool operator < (const node &n) const{
		return dist > n.dist;
	}

	node (int a, int b, int c, int d) : dist(d){
		v[0] = a; v[1] = b; v[2] = c;
	}
};


void BFS(int, int, int, int);
void update(const node&, int*);

int main(){

	int Case, a, b, c, d;
	cin >> Case;

	while (Case-- && cin >> a >> b >> c >> d)
		BFS(a, b, c, d);

	return 0;
}

void BFS(int a, int b, int c, int d)
{
	int cap[3] = { a, b, c };
	int vis[205][205] = { 0 };
	
	int ans[205];
	for (int i = 0; i < 205; ++i)
		ans[i] = -1;
	
	priority_queue<node> q;
	q.push(node(0, 0, c, 0));

	vis[0][0] = 1;
	while (!q.empty())
	{
		node u = q.top();
		q.pop();
		update(u, ans);
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i == j || u.v[i] == 0 || u.v[j] == cap[j])
					continue;                                       
				
				int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
				node u2 = u;                              
				u2.dist = u.dist + amount;
				u2.v[i] -= amount;
				u2.v[j] += amount;
				
				if (!vis[u2.v[0]][u2.v[1]])
				{
					vis[u2.v[0]][u2.v[1]] = 1;
					q.push(u2);
				}
			}
		}
	}
	for (int i = d; i >= 0; --i)
	{
		if (ans[i] >= 0)
		{
			cout << ans[i] << " " << i << endl;
			break;
		}
	}
}

void update(const node& u, int *ans)
{
	for (int i = 0; i < 3; ++i)
	{
		int d = u.v[i];
		if (ans[d] == -1 || u.dist < ans[d])
			ans[d] = u.dist;
	}
}