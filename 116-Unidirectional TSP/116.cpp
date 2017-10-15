#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int m, n;
	while (cin >> m >> n)
	{
		// initialize
		int **grid = new int*[m];
		int **dp = new int*[m];
		int **next = new int*[m];
		int start, row, ans = numeric_limits<int>::max();
		for (int i = 0; i < m; ++i)
		{
			grid[i] = new int[n];
			dp[i] = new int[n];
			next[i] = new int[n];
			for (int j = 0; j < n; ++j)
			{
				cin >> grid[i][j];
				if (j == n - 1)
					dp[i][j] = grid[i][j];
				else
					dp[i][j] = numeric_limits<int>::max();  //2,147,483,647
				if (n == 1 && dp[i][j] < ans)
				{
					ans = dp[i][j];
					start = i;
				}
			}
		}
		// end initialize

		for (int j = n - 2; j >= 0; --j)
		{
			for (int i = 0; i < m; ++i)
			{
				int next_row[3] = { i, i - 1, (i + 1) % m };
				if (i == 0)
					next_row[1] = m - 1;

				sort(next_row, next_row + 3);
				for (int k = 0; k < 3; ++k)
				{
					int d = dp[next_row[k]][j + 1] + grid[i][j];
					if (d < dp[i][j])
					{
						dp[i][j] = d;
						next[i][j] = next_row[k];
					}
				}
				if (j == 0 && dp[i][j] < ans)
				{
					ans = dp[i][j];
					start = i;
				}
			}
		}

		cout << start + 1;
		for (int j = 0, row = next[start][j]; j < n - 1; ++j, row = next[row][j])
			cout << " " << row + 1;
		cout << endl << dp[start][0] << endl;
	}
	return 0;
}